#include <bits/stdc++.h>
using namespace std;

//展开乐谱序列
bool expand(const string& score, vector<char>& expanded) 
{
    expanded.clear();
    istringstream ss(score);
    string token;
    while (getline(ss, token, '-')) 
	{
		if(!token.empty()&&'A'<=token[0]&&token[0]<='G')
		{
			char note = token[0];
	        int count = 0;
	        for (size_t i = 1; i < token.size(); ++i) 
			{
	            if (!isdigit(token[i])) return false;
	            count = count * 10 + (token[i] - '0');
	        }
	        if (count <= 0) return false;
	        expanded.insert(expanded.end(), count, note);	
		}
		else return false;//rawScore的输入格式不正确
    }
    return true;
}

// 判断播放序列是否合法
bool IsValidPlay(const vector<char>& score, const string& playSeq, int k) 
{
    if (playSeq.size() != score.size()) return false;
    vector<char> stk;
    size_t scoreIndex = 0, playIndex = 0;

    while (playIndex<playSeq.size())
	{
        bool canPlay = false;
        //当栈中非空，尝试播
        if (!stk.empty()) 
		{
            size_t take = min((size_t)k, stk.size());//播的音符个数
            if (take>0&&playIndex + take <= playSeq.size())
			{
                bool match = true;
                for (size_t i = 0; i < take; ++i)
				{
                    if (stk[stk.size() - 1 - i] != playSeq[playIndex + i])//播放栈倒着和playSeq逐一比较音符，有不同则match改为false
					{
                        match = false;
                        break;
                    }
                }
                if (match)
				{
                    for (size_t i = 0; i < take; ++i) stk.pop_back();
                    playIndex += take;
                    canPlay=true;
                }
            }
        }
        //如果无法播放，尝试存入新音符
        if(!canPlay)
		{
            if (scoreIndex<score.size())
			{
                stk.push_back(score[scoreIndex++]);
            }
			else {
				return false;
			}
        }
    }
    return stk.empty() && scoreIndex == score.size() && playIndex == playSeq.size();
}
int main()
{
	int k;
    string rawScore;
    cin>>rawScore>> k;
    vector<char> expanded_score;
    if (!expand(rawScore, expanded_score)) 
	{
        cout << -1 << endl;
        return 0;
    }
    vector<string> answers;
    string playLine;
    int n=0;
    while(cin>>playLine)
	{
		n++;
		if(playLine.empty())
		{
			cout<<-1<<endl;
			return 0;
		}
		bool valid=true;
        for (char ch : playLine)
		{
            if (ch < 'A' || ch > 'G') 
			{
				valid=false;           
				break;
            }
        }
        
        if(valid)
        {
            answers.push_back(IsValidPlay(expanded_score, playLine, k) ? "true" : "false");
		}
        else
		{
            cout<<-1<<endl;
            return 0;
        } 
    }
    if(n==0)
    {
		cout<<-1<<endl;
		return 0;
	}
    // 最后统一输出答案
    for (const auto& ans : answers) 
	{
        cout << ans << endl;
    }
    return 0;
}
