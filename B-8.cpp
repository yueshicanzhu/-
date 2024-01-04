#include<stdio.h>
#include<string.h>
#define MAX_Size 100
typedef struct{
	int data[MAX_Size];
	int front,rear;
}queue;
typedef struct{
	int index;
	int data;
}box;

int Adj[MAX_Size][MAX_Size]={0};
int e[MAX_Size]={0};

int visit[MAX_Size]={0};
int cnt=0;
void push(int x){
	int i;
	for(i=0;i<cnt;i++){
		if(visit[i]==x)break;
	}
	if(visit[x]==0){
		visit[x]=1;
		cnt++;
	} 	
}
int is_Empty(queue q){
	return (q.front==q.rear);
}
void enqueue(queue &q,int x){
	if(q.rear==MAX_Size-1)return ;
	q.rear++;
	q.data[q.rear]=x;
}
void dequeue(queue &q,int &x){
	if(q.rear==q.front)return;
	q.front++;
	x=q.data[q.front];
}

void BFS(int x){
	queue q;
	int j;
	q.front=q.rear=-1;
	visit[x]=1;
	enqueue(q,x);
	while(!is_Empty(q)){
		dequeue(q,x);
		for(int i=0;i<cnt;i++){
			if(Adj[x][j]!=0){
				visit[j]=1;
				enqueue(q,j);
			}
		}
	}
}
int is_true(){
	int i;
	for(i=0;i<cnt;i++){
		if(visit[i]==0)break;
	}
	if(i==cnt)return 1;
	else return 0;
}
int main()
{
	char str[MAX_Size];
	int i,j,x,y;
	while(~scanf("%[^\n]%*c",str)){
		for(i=0;str[i]!='\0';i++){
			x=str[0]-'0';
			push(x);
			y=str[5]-'0';
			push(y);
			Adj[x][y]=1;
			if(strlen(str)>5){
				for(j=8;j<strlen(str);j=j+3){
					y=str[j]-'0';
					push(y);
					Adj[x][y]=1;
				}
			}
		}
	}
//	for(i=0;i<cnt;i++){
//		for(j=0;j<cnt;j++){
//			printf("%d ",Adj[i][j]);
//		}
//		printf("\n");
//	}
	for(i=0;i<cnt;i++){
		memset(visit,0,sizeof (visit));
		BFS(i);
		if(is_true())break;
	}
	if(i==cnt)printf("yes");
	else printf("no");
	return 0;
 } 
