#include<stdio.h>
#include<string.h>//memset
#define MAX_Size 100
#define LEN 2
int MG[MAX_Size][MAX_Size];
int result[MAX_Size];
int k=0;
typedef struct {
	int data[MAX_Size][LEN];
	int front,rear;	
}queue; //typedef
int N,M;
void is_path(int x,int y,int x1,int y1,int &cnt){
	if(x==x1&&y==y1){
		result[k++]=cnt;
	}
	else{
		if(MG[x][y]==0)
		{
				int xi,yi,d;
				for(d=0;d<4;d++){
					cnt++;
					if(d==0){
						xi=x-1;yi=y;
					}
					else if(d==1){
						xi=x;yi=y-1;
					}
					else if(d==2){
						xi=x+1;yi=y; 
					}
					else{
						xi=x;yi=y+1;
					}
					MG[x][y]=1;
					is_path(xi,yi,x1,y1,cnt);//递归 
					
					cnt--;
					MG[x][y]=0;
				}
		}
	}
}
int is_Empty(queue q){
	return (q.front==q.rear);
}
void enqueue(queue &q,int x,int y){
	if(q.rear==MAX_Size-1)return ;
	q.rear++;
	q.data[q.rear][0]=x;
	q.data[q.rear][1]=y;
}
void dequeue(queue &q,int &x,int &y){
	if(q.rear==q.front)return;
	q.front++;
	x=q.data[q.front][0];
	y=q.data[q.front][1];
}
int visit[MAX_Size][MAX_Size];
void BFS(int x,int y,int x1,int y1,int &cnt){
	queue q;
	int xt=0,yt=0,xi=0,yi=0;
	q.front=q.rear=-1;
	memset(visit,0,sizeof (visit));
	enqueue(q,x,y);
	while(q.front!=q.rear){
		dequeue(q,xt,yt);
		if(xt==x1&&yt==y1){
			break;
		}
		for(int d=0;d<4;d++){
			if(d==0){
				xi=xt-1;yi=yt;
			}
			else if(d==1){
				xi=xt;yi=yt-1;
			}
			else if(d==2){
				xi=xt+1;yi=yt; 
			}
			else{
				xi=xt;yi=yt+1;
			}
			if(MG[xi][yi]==1)continue;
			if(visit[xi][yi]==0){
				visit[xi][yi]=visit[xt][yt]+1;
				enqueue(q,xi,yi);
			}
		}
			
	}		
}
int main()
{
	int i,j,start_x,start_y,end_x,end_y,cnt=0;
	scanf("%d %d",&N,&M);
	
	//迷宫初始化 
	for(i=0;i<M+2;i++)
		for(j=0;j<N+2;j++)
			MG[i][j]=1;
			
	for(i=0;i<N;i++)
		for(j=0;j<M;j++)
			scanf("%d",&MG[i+1][j+1]);
	scanf("%d %d %d %d",&start_x,&start_y,&end_x,&end_y);
	BFS(start_x,start_y,end_x,end_y,cnt); 
	printf("BFS求得最短路径是%d\n",visit[end_x][end_y]);	
	
//	printf("递归算法：\n"); 
	is_path(start_x,start_y,end_x,end_y,cnt);
//	for(i=0;i<N+2;i++){
//		for(j=0;j<M+2;j++)
//			printf("%d ",MG[i][j]);
//		printf("\n");		
//	}
	
	int min_len=result[0];
	for(i=1;i<k;i++){
		if(min_len>result[i])min_len=result[i];
	}
	printf("递归求得最短路径是%d",min_len);
	return 0;
 } 
