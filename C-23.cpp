#include<stdio.h>
#define MAX_Size 16
char scale[MAX_Size]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
void modify(int y,int x){	
	if(y/x==0){
		printf("%c",scale[(y%x)]);
		return;
	}	
	modify(y/x,x);
	printf("%c",scale[(y%x)]);
}

int main()
{
	int n;
	while(~(scanf("%d",&n))){
		printf("������\"");
		modify(n,2);
		printf("\"���˽��� \"");
		modify(n,8);
		printf("\"��ʮ������ \"");
		modify(n,16);
		printf("\"\n");
	}
	return 0;
 } 
