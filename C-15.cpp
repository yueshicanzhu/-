#include<stdio.h>
#include<string.h>
#define MAX_Size 100
int num1[MAX_Size],num2[MAX_Size];
int num[MAX_Size];//count1和count2用在不同的循环里。 
int count1=0,count2=0,flag,cnt1=0;//全局变量和局部变量冲突，        
void judge(int cnt){
	if(cnt==count1+1){
		int i;
		if(cnt1!=count2)return ;
		for(i=0;i<count2;i++){
			if(num[i]!=num2[i]){
				break;
			}
		}
		if(i==count2)flag=1;
		return ;
	}
	num[cnt1++]=num1[cnt];
	judge(cnt+1);
	num[cnt1--]=num1[cnt];
	judge(cnt+1);
}
int main()
{
	char str1[MAX_Size],str2[MAX_Size];
	gets(str1);
	gets(str2);
	int len1=strlen(str1);
	int len2=strlen(str2);
	int i;
	for(i=0;i<len1;i=i+3){
		num1[count1++]=str1[i]-'0';
	}
	for(i=0;i<len2;i=i+3){
		num2[count2++]=str2[i]-'0';
	}
//	for(i=0;i<count2;i++){
//		printf("%d ",num2[i]);
//	}
	flag=0;
	judge(0);
	if(flag==1)printf("是子序列");
	else printf("不是子序列");
	return 0;
}
