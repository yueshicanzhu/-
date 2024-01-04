#include<stdio.h>
#define MAX_Size 4
int change[MAX_Size]={25,10,5,1};
int Num[MAX_Size];
int main()
{
	int money,num,i;
	scanf("%d",&money);
	for(i=0;i<MAX_Size;i++){
		num=0;
		num=money/change[i];
		if(money==num*change[i]){
			Num[i]=num;			
			break;
		}
		Num[i]=num;
		money=money-num*change[i];
	}
	for(int j=0;j<=i;j++){
		if(Num[j]==0)continue;
		if(i==0||j==i)printf("%d个%d分硬币",Num[j],change[j]);
		else if(j<i)printf("%d个%d分和",Num[j],change[j]);
	}
	return 0;
 } 
