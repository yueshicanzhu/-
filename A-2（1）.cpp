#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAX 10
#define MAX_LEN 100
#define user_number 10
#define HashTableSize 20
typedef struct{
	char name[MAX_LEN];
	char address[MAX_LEN];
}UserTable;
typedef struct{
	double key;
	UserTable user;
	int count;
}HashTable;


//int型数据范围是 -2147483648~2147483647[-2^31~2^31-1]，共10位数 
double telephone[MAX]={7868195560, 13633767067,13703444399,15159488858,13498313081,19881138788,17203551499,13891072941,13770353566,13538846854};
char name[MAX][MAX_LEN]={{"金学文"},{"戴晗昱"},{"蔡高达"},{"邵嘉良"},{"孔和璧"},{"蒋翰林"},{"曾嘉茂"},{"周和平"},{"叶英豪"},{"蒋元纬"}};
char address[MAX][MAX_LEN]={{"河南"},{"福建"},{"浙江"},{"广东"},{"广西"},{"重庆"},{"四川"},{"宁夏"},{"湖北"},{"湖南"}};
HashTable ha[HashTableSize];
	

void InsertHT(HashTable ha[],int &n,int p,double telephone,char name[],char address[]){
	int i,adr,cnt;
	adr=(int)(telephone/10)%p;
	if(ha[adr].key==-1){
		ha[adr].key=telephone;
		ha[adr].count=1;
	}
	else{
		cnt=1;
		do{
			adr=(adr+1)%HashTableSize;
			cnt++;
		}while(ha[adr].key!=-1);
		ha[adr].key=telephone;
		ha[adr].count=cnt;
	}
	strcpy(ha[adr].user.name,name);
	strcpy(ha[adr].user.address,address);
	n++;
} 

void InsertHTBySquare(HashTable ha[],int &n,int p,double telephone,char name[],char address[]){
	int i,adr,cnt,ii,jj=1;
	adr=(int)(telephone/10)%p;
	if(ha[adr].key==-1){
		ha[adr].key=telephone;
		ha[adr].count=1;
	}
	else{
		cnt=1;
		do{
			ii=pow(cnt,jj);
			adr=(adr+ii)%HashTableSize;
			cnt++;
			if(cnt!=1&&cnt%2==1)jj++;
			if(cnt%2==0)ii=-ii;
		}while(ha[adr].key!=-1);
		ha[adr].key=telephone;
		ha[adr].count=cnt;
	}
	strcpy(ha[adr].user.name,name);
	strcpy(ha[adr].user.address,address);
	n++;
} 
void CreateHT(HashTable ha[],int &n,int p){
	for(int i=0;i<HashTableSize;i++){
		ha[i].key=-1;
		ha[i].count=0;
	} 
	n=0;
	for(int i=0;i<user_number;i++){
		InsertHT(ha,n,p,telephone[i],name[i],address[i]);
//		InsertHTBySquare(ha,n,p,telephone[i],name[i],address[i]);
	}
}
void SearchHT(HashTable ha[],int p,double telephone){
	int cnt=1,adr,k1;
	int k=(int)(telephone/10);
	adr=k%p;
	while(ha[adr].key!=-1&&ha[adr].key!=telephone){
		cnt++;
		adr=(adr+1)%HashTableSize; 
	}
	k1=(int)(ha[adr].key/10);
	if(k==k1){
		printf("成功：关键字%.0f,比较%d次\n",ha[adr].key,cnt);
	} 
	else printf("失败：关键字%.0f,比较%d次\n",ha[adr].key,cnt); 
}
void print(HashTable ha[]){
	for(int i=0;i<HashTableSize;i++){
		printf("%s",ha[i].user.name);
		printf(" %.0f",ha[i].key);
		printf(" %s",ha[i].user.name);
		printf(" %d\n",ha[i].count);
	}
}
void ASL(HashTable ha[],int n,int p){
	int i,j;
	int succ=0,unsucc=0,s;
	for(i=0;i<HashTableSize;i++){
		if(ha[i].key!=-1){
			succ+=ha[i].count;
		}
	}
	printf("成功情况下ASL(%d)=%g\n",n,succ*1.0/n);
	for(i=0;i<p;i++){
		s=1;j=i;
		while(ha[j].key!=-1){
			s++;
			j=(j+1)%HashTableSize;
		}
		unsucc+=s;
	}
	printf("不成功情况下ASL(%d)=%.1f\n",n,unsucc*1.0/p);
}
void CountConflict(HashTable ha[]){
	int ConflictSum=0;
	int InsertSum=0;
	for(int i=0;i<HashTableSize;i++){
		InsertSum+=ha[i].count;
		if(ha[i].count>1)ConflictSum+=(ha[i].count-1);
	}
	double output=1.0*ConflictSum/InsertSum;
	printf("冲突率=%.2f\n",output);
}
int main()
{
	//m为哈希表数组长度，n为实际长度，p为取余质数 
	int HashCount,p=10;
	CreateHT(ha,HashCount,p);
//	double search=17203551499; 
//	SearchHT(ha,p,search);
//	print(ha);
//	printf("线性探测法的性能分析\n");
//	printf("平方探测法的性能分析\n"); 
	ASL(ha,HashCount,p);
	CountConflict(ha); 
	return 0;
 } 
