#include<stdio.h>
#define MAX_Size 100
typedef struct Node{
	int data;
	int left;
	int right;
}BTree;
typedef struct{
	int data[MAX_Size];
	int top;
}stack;
int is_Empty(stack q){
	return (q.top==-1);
}
void Push(stack &q,int e){
	if(q.top!=MAX_Size-1){
		q.top++;
		q.data[q.top]=e; 
	}
}
void Pop(stack &q,int &e){
	if(q.top!=-1){
		e=q.data[q.top];
		q.top--;
	}
}

BTree B[MAX_Size];
int cnt=1;

void CreateBTree(int data,int left,int right){
	B[cnt].data=data;
	B[cnt].left=left;
	B[cnt].right=right;
	cnt++;
}

void PreOrder(int i){
	if(i!=-1){
		printf("%d ",B[i].data);
		PreOrder(B[i].left);
		PreOrder(B[i].right);  		
	}                                                                                                                                                                                  
}
void InOrder(int i){
	if(i!=-1){
		InOrder(B[i].left);
		printf("%d ",B[i].data);	
		InOrder(B[i].right);
	} 
}
void PostOrder(int i){
	if(i!=-1){
		PostOrder(B[i].left);
		PostOrder(B[i].right);
		printf("%d ",B[i].data);
	}
}

int main()
{
	//²âÊÔÑùÀý£º
//8 
//1 2 3 
//2 4 5 
//3 6 -1 
//4 -1 -1 
//5 -1 -1 
//6 -1 7 
//7 -1 8
//8 -1 -1 
	int n,data,left,right;
	BTree B[MAX_Size];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&data,&left,&right);
		CreateBTree(data,left,right);
	}
	int index=1;
	PreOrder(index);
	printf("\n");
	InOrder(index);
	printf("\n");
	PostOrder(index);
	return 0;
}
