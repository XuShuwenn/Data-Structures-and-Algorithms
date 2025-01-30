#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//树节点信息
struct treeNode{
	int value;//值
	treeNode* lchild;//左孩子
	treeNode* rchild;//右孩子
	treeNode(int v){
		value =v,lchild=NULL,rchild=NULL;
	}
};
//二叉搜索树的创建
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
//中序遍历“左根右”
void InOrder(treeNode* root)
{
	if(root==NULL)return;
	InOrder(root->lchild);
	cout<<root->value<<" ";
	InOrder(root->rchild);
}
//前序遍历“根左右”
void PreOrder(treeNode* root)
{
	if(root==NULL)return;
	cout<<root->value<<" ";
	PreOrder(root->lchild);
	PreOrder(root->rchild);
}
//后序遍历“左右根”
void PostOrder(treeNode* root)
{
	if(root==NULL)return;
	cout<<root->value<<" ";
	PostOrder(root->lchild);
	PostOrder(root->rchild);
}
//(基于广度优先搜索实现的)层次遍历
int h=0;
void LayerOrder(treeNode* root)
{
	queue<treeNode*>q;//queue是一种容器转换器模板，调用#include< queue>即可使用队列类
	q.push(root);// 将root插入队列尾
	treeNode* last=root;//last表示当前行最右节点
	treeNode* nlast=NULL;//nlast表示下一行最右节点，要提前找到
	while(!q.empty())//循环条件：q非空
	{
		treeNode* tmp=q.front();
		cout<<tmp->value<<" ";
		q.pop();//出队列
		if(tmp->lchild!=NULL){
			q.push(tmp->lchild);//左孩子进队
			nlast=tmp->lchild;
		}
		if(tmp->rchild!=NULL){
			q.push(tmp->rchild);//右孩子进队
			nlast=tmp->rchild;
		}
		if(tmp==last){
			cout<<endl;
			h++;
			last=nlast;
		}
	}
}
//递归求树高
int treeHeight(treeNode*root)
{
	if(root==NULL)return 0;
	int lh=treeHeight(root->lchild);
	int rh=treeHeight(root->rchild);
	return lh>rh?lh+1:rh+1;
}
//查找
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
	cout<<"\n前序遍历:\n";
	PreOrder(root);
	cout<<"\n中序遍历:\n";
	InOrder(root);
	cout<<"\n后序遍历:\n";
	PostOrder(root);
	cout<<"\n层次遍历:\n";
	LayerOrder(root);
	cout<<"\n树的高度：\n"<<treeHeight(root);
	int tar;
	while(cin>>tar)
	{
		cout<<find(root,tar)<<endl;
	}//查找时间复杂度O(logn)
	return 0;
}
