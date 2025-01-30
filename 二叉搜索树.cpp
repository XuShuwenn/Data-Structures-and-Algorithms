#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//���ڵ���Ϣ
struct treeNode{
	int value;//ֵ
	treeNode* lchild;//����
	treeNode* rchild;//�Һ���
	treeNode(int v){
		value =v,lchild=NULL,rchild=NULL;
	}
};
//�����������Ĵ���
treeNode* build_binarySearchTree(vector<int> a){
	treeNode* root=new treeNode(a[0]);
	for(int i=1;i<a.size();i++)
	{
		treeNode*tmp=new treeNode(a[i]);
		treeNode*troot=root;
		while(troot)
		{
			if(tmp->value<troot->value)
			{
				if(troot->lchild==NULL){
					troot->lchild=tmp;
					break;
				}
				else troot=troot->lchild;
			}
			else if(tmp->value>troot->value)
			{
				if(troot->rchild==NULL){
					troot->rchild=tmp;
					break;
				}
				else troot=troot->rchild;
			}
		}
	}
	return root;
}
//�������������ҡ�
void InOrder(treeNode* root)
{
	if(root==NULL)return;
	InOrder(root->lchild);
	cout<<root->value<<" ";
	InOrder(root->rchild);
}
//ǰ������������ҡ�
void PreOrder(treeNode* root)
{
	if(root==NULL)return;
	cout<<root->value<<" ";
	PreOrder(root->lchild);
	PreOrder(root->rchild);
}
//������������Ҹ���
void PostOrder(treeNode* root)
{
	if(root==NULL)return;
	cout<<root->value<<" ";
	PostOrder(root->lchild);
	PostOrder(root->rchild);
}
//(���ڹ����������ʵ�ֵ�)��α���
int h=0;
void LayerOrder(treeNode* root)
{
	queue<treeNode*>q;//queue��һ������ת����ģ�壬����#include< queue>����ʹ�ö�����
	q.push(root);// ��root�������β
	treeNode* last=root;//last��ʾ��ǰ�����ҽڵ�
	treeNode* nlast=NULL;//nlast��ʾ��һ�����ҽڵ㣬Ҫ��ǰ�ҵ�
	while(!q.empty())//ѭ��������q�ǿ�
	{
		treeNode* tmp=q.front();
		cout<<tmp->value<<" ";
		q.pop();//������
		if(tmp->lchild!=NULL){
			q.push(tmp->lchild);//���ӽ���
			nlast=tmp->lchild;
		}
		if(tmp->rchild!=NULL){
			q.push(tmp->rchild);//�Һ��ӽ���
			nlast=tmp->rchild;
		}
		if(tmp==last){
			cout<<endl;
			h++;
			last=nlast;
		}
	}
}
//�ݹ�������
int treeHeight(treeNode*root)
{
	if(root==NULL)return 0;
	int lh=treeHeight(root->lchild);
	int rh=treeHeight(root->rchild);
	return lh>rh?lh+1:rh+1;
}
//����
bool find(treeNode*root,int target){
	while(root){
		if(target==root->value){
			return 1;
		}
		if(target<root->value){
			root=root->lchild;
		}
		if(target>root->value){
			root=root->rchild;
		}
	}
}
int main(){
	vector<int>a{5,4,3,1,2,6,8,9,7};
	treeNode*root=build_binarySearchTree(a);
	cout<<"\nǰ�����:\n";
	PreOrder(root);
	cout<<"\n�������:\n";
	InOrder(root);
	cout<<"\n�������:\n";
	PostOrder(root);
	cout<<"\n��α���:\n";
	LayerOrder(root);
	cout<<"\n���ĸ߶ȣ�\n"<<treeHeight(root);
	int tar;
	while(cin>>tar)
	{
		cout<<find(root,tar)<<endl;
	}//����ʱ�临�Ӷ�O(logn)
	return 0;
}
