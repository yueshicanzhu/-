#include<stdio.h>
#include<string.h>
#define MAX_Size 100
#define INF 0x3f3f3f3f

int Matrix[MAX_Size][MAX_Size]={0};
int path[MAX_Size][MAX_Size];
int cnt;
void Floyd(int n){
	int i,j,k,temp;
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(Matrix[i][k]==INF||Matrix[k][j]==INF)continue;
				else{
					if(Matrix[i][j]>Matrix[i][k]+Matrix[k][j]){
						Matrix[i][j]=Matrix[i][k]+Matrix[k][j];
					}
				}
			}
		}
	}
}
int FloydTravese(int v1,int v2,int cnt){
	int k=path[v1][v2];
	if(k!=-1){
	FloydTravese(v1,k,cnt+1);
	FloydTravese(k,v2,cnt+1);		
	}
	else return cnt;	
}

int main()
{
	int v,e,x,y,weight;
	scanf("%d %d",&v,&e);
	memset(Matrix,INF,sizeof(Matrix));
	for(int i=1;i<=v;i++){
		for(int j=1;j<=v;j++){
			if(i==j)Matrix[i][j]=0;
		}
	}
	for(int i=1;i<=e;i++){
		scanf("%d %d %d",&x,&y,&weight);
		Matrix[x][y]=weight;
	}
	int s;
	scanf("%d",&s);
	Floyd(v);
//	for(int i=1;i<=v;i++){
//		for(int j=1;j<=v;j++){
//			if(Matrix[i][j]==INF)printf("INF ");
//			else printf("%d ",Matrix[i][j]);
//		}
//		printf("\n");
//	}
	for(int i=1;i<=v;i++){
		if(Matrix[s][i]==INF)printf("INF\n");
		else printf("%d\n",Matrix[s][i]);
	}
	return 0;
 } 
