#include<stdio.h>
#include <vector>
#define MAX_Size 100
using namespace std;//vectorһ���� 
int source;
int Matrix[MAX_Size][MAX_Size]={0};
int indegree[MAX_Size]={0},outdegree[MAX_Size]={0};
int n,m;

void SearchSource(){
	int i;
	for(i=0;i<n;i++){
		if(indegree[i]==0)break;
	}
}
vector<int> t;
vector<int> suc[MAX_Size];//>>��> >������ 
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

vector<vector<int> > path;  // ��ʼ��С��Ϊ0,
vector<int> temp_path;
void recordLongestPath(int source, vector<vector<int> >& path, vector<int> temp_path) {
    vector<int> now_suc = suc[source];  // ��õ�ǰ�ڵ�ĺ�̽�㼯��
    temp_path.push_back(source);
    if(now_suc.empty()) {   // û�н��
        path.push_back(temp_path);
        return;
    }
    // ��Ϊ�գ���ô���Ѻ�̽�㣬�õ�·��
    for(int i = 0; i < now_suc.size(); i++) {
        int source2 = now_suc[i];   // �����е�һ����
        recordLongestPath(source2, path, temp_path);
    }
}

void printAllPath(vector<vector<int> > &path) {
    int k = path.size();    // ·��������
    for(int i = 0; i<k; i++) {
        for(int j = 0; j <path[i].size() ; j++) {
        	printf("%d ",path[i][j]);
        }
		printf("\n"); 
    }
}

int main()
{
	
	int x,y,weight;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&x,&y,&weight);
		Matrix[x][y]=weight;
		indegree[y]++;
		outdegree[x]++;	
	}

//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			printf("%d ",Matrix[i][j]);
//		}
//		printf("\n");
//	}
	SearchSource();
//	printf("%d %d",source,target);
	DP(source);
//	for(int i=0;i<n;i++){
//		printf("%d->",i);
//		for(int j=0;j<suc[i].size();j++){
//			printf("%d ",suc[i][j]);
//		}
//		printf("\n");
//	}
	recordLongestPath(source,path,temp_path);
	printAllPath(path);
	return 0;
 } 
 

