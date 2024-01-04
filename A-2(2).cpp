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
typedef struct node{
	double key;
	UserTable user;
	struct node *next;
}Node;
typedef struct{
	Node *firstp;
}HashTable; 


//int�����ݷ�Χ�� -2147483648~2147483647[-2^31~2^31-1]����10λ�� 
double telephone[MAX]={7868195560, 13633767067,13703444399,15159488858,13498313081,19881138788,17203551499,13891072941,13770353566,13538846854};
char name[MAX][MAX_LEN]={{"��ѧ��"},{"������"},{"�̸ߴ�"},{"�ۼ���"},{"�׺��"},{"������"},{"����ï"},{"�ܺ�ƽ"},{"ҶӢ��"},{"��Ԫγ"}};
char address[MAX][MAX_LEN]={{"����"},{"����"},{"�㽭"},{"�㶫"},{"����"},{"����"},{"�Ĵ�"},{"����"},{"����"},{"����"}};
HashTable ha[HashTableSize];
	
void InsertHTByChain(HashTable ha[],int &n,int p,double telephone,char name[],char address[]){
	int i,adr,cnt;
	adr=(int)(telephone/10)%p;
	Node *q;
	q=(Node *)malloc(sizeof(Node));
	q->key=telephone;
	strcpy(q->user.name,name);
	strcpy(q->user.address,address);
	q->next=NULL;
	if(ha[adr].firstp==NULL){
		ha[adr].firstp=q;
	}
	else{
		q->next=ha[adr].firstp;
		ha[adr].firstp=q;
	}
	
	n++;
} 	
void CreateHT(HashTable ha[],int &n,int p){
	for(int i=0;i<HashTableSize;i++){
		ha[i].firstp=NULL;
	} 
	n=0;
	for(int i=0;i<user_number;i++){
		InsertHTByChain(ha,n,p,telephone[i],name[i],address[i]);
	}
}
void ASLByChain(HashTable ha[],int n){
	int succ=0,unsucc=0,s;
	Node *q;
	for(int i=0;i<HashTableSize;i++){
		s=0;
		q=ha[i].firstp;
		while(q!=NULL){
			q=q->next;
			s++;
			succ+=s;
		}
		unsucc+=s;
	}
	printf("�ɹ������ASL(%d)=%g\n",n,succ*1.0/n);
	printf("���ɹ������ASL(%d)=%.1f\n",n,unsucc*1.0/HashTableSize);//������m 
}
void print(HashTable ha[]){
	Node *q;
	for(int i=0;i<HashTableSize;i++){
		q=ha[i].firstp;
		if(q==NULL)printf("-1\n");
		while(q){
		printf("%s",q->user.name);
		printf(" %.0f",q->key);
		printf(" %s\n",q->user.name);
		q=q->next;	
		}

	}
}
int main()
{
	//mΪ��ϣ�����鳤�ȣ�nΪʵ�ʳ��ȣ�pΪȡ������ 
	int HashCount,p=10;
	CreateHT(ha,HashCount,p);
	//double search=17203551499; 
	//SearchHT(ha,p,search);
	//print(ha);
	printf("�����������ܷ���\n"); 
	ASLByChain(ha,HashCount);
	
	return 0;
 } 
