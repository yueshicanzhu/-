#include<stdio.h>
#include<string.h>
#define MAX_Size 100

int main()
{
	int cnt=0,i,flag=0,flag1=0;
	char ch,str[MAX_Size];
	while((ch=getchar())!='\n'){
		if(ch==' '&&i==0){
			continue;
		}
		if(ch!=' '){
			str[i++]=ch;
			flag=1;
		}
		else if(flag==1&&ch==' '){
			str[i++]=ch;
			flag=0;
		}
	}
	if(str[i-1]==' '){
		str[i-1]='\0';
	}
	str[i]='\0';
	puts(str);
	return 0;
 } 
