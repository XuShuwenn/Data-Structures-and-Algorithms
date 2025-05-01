#include <bits/stdc++.h>
using namespace std;

//չ����������
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
		else return false;//rawScore�������ʽ����ȷ
    }
    return true;
}

// �жϲ��������Ƿ�Ϸ�
bool IsValidPlay(const vector<char>& score, const string& playSeq, int k) 
{
    if (playSeq.size() != score.size()) return false;
    vector<char> stk;
    size_t scoreIndex = 0, playIndex = 0;

    while (playIndex<playSeq.size())
	{
        bool canPlay = false;
        //��ջ�зǿգ����Բ�
        if (!stk.empty()) 
		{
            size_t take = min((size_t)k, stk.size());//������������
            if (take>0&&playIndex + take <= playSeq.size())
			{
                bool match = true;
                for (size_t i = 0; i < take; ++i)
				{
                    if (stk[stk.size() - 1 - i] != playSeq[playIndex + i])//����ջ���ź�playSeq��һ�Ƚ��������в�ͬ��match��Ϊfalse
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
        //����޷����ţ����Դ���������
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
    // ���ͳһ�����
    for (const auto& ans : answers) 
	{
        cout << ans << endl;
    }
    return 0;
}
