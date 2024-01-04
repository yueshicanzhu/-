#include<stdio.h>
#include <vector>
#define MAX_Size 100
using namespace std;//vector一起用 

int source;
int Matrix[MAX_Size][MAX_Size]={0};
int indegree[MAX_Size]={0};
int n;
int visit[MAX_Size]={0};
void push(int x){
	int i;
	for(i=0;i<n;i++){
		if(visit[i]==x)break;
	}
	if(visit[x]==0){
		visit[x]=1;
		n++;
	} 	
}
void SearchSource(){
	int i;
	for(i=0;i<n;i++){
		if(indegree[i]==0)break;
	}
}

vector<int> t;
vector<int> suc[MAX_Size];//>>和> >的区别 
int dp[MAX_Size]={0};
int DP(int i){
	if(dp[i] > 0) return dp[i];
	for(int j =0;j<n;j++){
		if(Matrix[i][j] != 0){
			int temp = DP(j)+Matrix[i][j];
			if(temp>dp[i]){
				dp[i] = temp;
				suc[i].clear();
				suc[i].push_back(j);
			}
			else if(temp==dp[i]){
				suc[i].push_back(j);
			}
		}
	}
	return dp[i];
}
int Count(){
	int max=0;
	for(int i=0;i<n;i++){
		if(max<suc[i].size()){
			max=suc[i].size();
		}
	}
	return max;
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
			Matrix[x][y]=str[8]-'0';
			indegree[y]++;
		}
	}
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			printf("%d ",Matrix[i][j]);
//		}
//		printf("\n");
//	}
	SearchSource();
	DP(source);
	printf("%d",Count());
	return 0;
 } 
 

