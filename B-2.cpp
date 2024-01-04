#include<stdio.h>
#include<string.h>
#define MAX_Size 100
#define INF 0x3f3f3f3f

int path[MAX_Size];
int n,m,s;
int PathCopy[MAX_Size];
typedef struct 
{
    int x,y,weight;
}Edge;

Edge edge[MAX_Size];

void bellman_ford(int s)
{
    memset(path,0x3f3f3f3f,sizeof path);
    path[s]=0;
    for(int i=0;i<n-1;i++)
    {
        //备份，避免发生串联
        memcpy(PathCopy,path,sizeof path);
        for(int j=0;j<m;j++)
        {
            int x=edge[j].x,y=edge[j].y,weight=edge[j].weight;
            path[y]= path[y] > PathCopy[x]+weight?PathCopy[x]+weight:path[y];
        }
    }
}
//void BellmanFord()
//{
//    memset(path,INF,sizeof(path));
//    path[2] = 0;
//
//	for(int x = 1; x <= n; x++)
//	    {
//	    	
//	        for(int y = 1; y <=n; y++)
//	        {
//	            if(path[x]!=INF&&path[y] > path[x] + Matrix[x][y])
//	            {	
//	            
//	            	printf("%d %d %d %d %d\n",x,y,path[y],path[x],Matrix[x][y]);
//	                path[y] = path[x] + Matrix[x][y];
//	            }
//	        }
//	    }
////    return path[0];
//}

int main()
{
	int x,y,weight;
	scanf("%d %d",&n,&m);
//	memset(Matrix,INF,sizeof(Matrix));
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(i==j)Matrix[i][j]=0;
//		}
//	}

	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&x,&y,&weight);
		edge[i].x=x;
		edge[i].y=y;
		edge[i].weight=weight;
	}
	scanf("%d",&s);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(Matrix[i][j]==INF)printf("INF ");
//			else printf("%d ",Matrix[i][j]);
//		}
//		printf("\n");
//	}
//	BellmanFord();
	bellman_ford(s);
	for(int i=1;i<=n;i++){
		if(path[i]==INF)  printf("INF ");
		else printf("%d ",path[i]);
	}
//	printf("%d",BellmanFord());
//	for(int i=1;i<=n;i++){
//		if(path[i]==INF)printf("INF\n");
//		else printf("%d\n",path[i]);
//	}
	return 0;
 } 
