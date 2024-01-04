#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_Size 100
typedef struct node{
	int data;
	struct node* next;
}Node;
void print(Node *head){
	Node *p;
	for(p=head;p;p=p->next){
		if(p==head)printf("%d",p->data);
		else printf(" -> %d",p->data);
	}
}
void solve(Node *p,int n){
	Node *head1=NULL,*t1,*head2=NULL,*t2;
	for(int i=1;i<=n;i++){
		if(i%2==0){
			if(head1==NULL){
				head1=p;
				t1=p;
			}
			else{
				t1->next=p;
				t1=p;
			}
		}
		else{
			if(head2==NULL){
				head2=p;
				t2=p;
			}
			else{
				t2->next=p;
				t2=p;
			}
		}
		p=p->next;		
	}
	if(n%2!=0){
		t1->next=NULL;
	}
	else{
		t2->next=NULL;
	}
	printf("L1 = ");
	print(head1);
	printf("£¬L2 = ");	
	print(head2);
} 

int main()
{
	int n;
	Node *head=NULL,*tail;
	scanf("%d",&n);
	int num;
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		Node *p=(Node *)malloc(sizeof(Node));
		p->data=num;
		p->next=NULL;
		if(head==NULL){
			head=p;
			tail=p;
		}
		else{
			tail->next=p;
			tail=p;
		}
	}
	solve(head,n);
	return 0;
 } 
