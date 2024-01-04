#include<stdio.h>
#include<string.h>
#define MAX_Size 100
char str1[MAX_Size],str2[MAX_Size];
void GetNext(int next[],int len2){
	int j=0,k=-1;
	next[0]=-1;
	while(j<len2-1){//这里还有减一 
		if(k==-1||str2[j]==str2[k]){
			j++;k++;
			next[j]=k;//这边还有一句 
		}
		else k=next[k];
	}
}
int KMP(int len1,int len2){
	int i=0,j=0;
	int next[MAX_Size];
	GetNext(next,len2);
	while(i<len1&&j<len2){
		if(j==-1||str1[i]==str2[j]){
			i++;j++;
		}
		else j=next[j];
	}
	if(j>=len2)return i-len2;
	else return -1;
}
int main()
{
	gets(str1);
	gets(str2);
	int len1=strlen(str1);
	int len2=strlen(str2);
	printf("%d",KMP(len1,len2));
	return 0;
}
