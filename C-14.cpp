#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAX_Size 100
int Num[MAX_Size];
int num[MAX_Size];
int cnt1=0,max_size=0;
void dfs(int cnt,int count){
	if(cnt==count+1){
		int i,temp;
		for(i=0;i<count-1;i++){
			if(i==0){
				temp=num[i+1]-num[i];
			}
			else{
				if(temp>0&&num[i+1]-num[i]>0||temp<0&&num[i+1]-num[i]<0){
					break;
				}
				temp=num[i+1]-num[i];
			}
		}
		if(i==count-1)max_size=max(max_size,cnt1);
		return ;
	}
	num[cnt1++]=Num[cnt];
	dfs(cnt+1,count);
	num[cnt1--]=Num[cnt];
	dfs(cnt+1,count);
	
}
int main()
{
	int num,count=0,i,temp;
	char str[MAX_Size];
	gets(str);
	int len=strlen(str);
	for(i=0;i<len;i=i+3){
		Num[count++]=str[i]-'0';
	}
//	for(i=0;i<count;i++){
//		printf("%d ",Num[i]);
//	}
	for(i=0;i<count-1;i++){
		if(i==0){
			temp=Num[i+1]-Num[i];
			
		}
		else{
			if(temp>0&&Num[i+1]-Num[i]>0||temp<0&&Num[i+1]-Num[i]<0){
				break;
			}
			temp=Num[i+1]-Num[i];
		}
	}
	if(i==count-1)printf("是摆动序列\n");
	else{
		dfs(0,count);
		printf("非摆动序列，需要删除 %d 个元素",count-max_size+1);
		
	}
	return 0;
}
