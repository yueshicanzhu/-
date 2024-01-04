#include<stdio.h>
#include<string.h>
#define MAX_Size 100
int A[MAX_Size][MAX_Size]={0};
int B[MAX_Size][MAX_Size]={0};
int C[MAX_Size][MAX_Size]={0};
int main()
{
	int n1,n2;
	int i,j,value;
	scanf("%d",&n1);
	for(int k=0;k<n1;k++){
		scanf("%d %d %d",&i,&j,&value);
		A[i][j]=value;
	}
	scanf("%d",&n2);
	for(int k=0;k<n2;k++){
		scanf("%d %d %d",&i,&j,&value);
		B[i][j]=value;
	}
	int sum=0;
	for(int i=0;i<n1;i++){
		for(int j=0;j<n2;j++){
			sum+=A[i][j]*B[j][i];
			C[i][j]=A[i][j]+B[i][j];
		}
	}
	printf("A和B相乘的结果为%d\n",sum);
	printf("A和B相加的结果为\n");
	for(int i=0;i<n1;i++){
		for(int j=0;j<n2;j++){
			printf("%d ",C[i][j]);
		}
		printf("\n");
	} 
	return 0;
}
