#include<stdio.h>
#include<stdlib.h> 
#define N 11
#define R 10
typedef struct node{
	int data;
	struct node *next;
}NodeType;

int A[N]={0,6,12,458,5,4,28,19,1230,9,47};

void print(int A[]){
	printf("�����ṹ���£�\n");
	for(int i=1;i<N;i++){
		printf("%d ",A[i]);
	}
}

//ϣ�������㷨 
void ShellSort(int A[],int n){
	int d,i,j;
	for(d=n/2;d>=1;d=d/2){
		for(i=d+1;i<=n;i++){
			if(A[i]<A[i-d]){
				A[0]=A[i];
				for(j=i-d;j>0&&A[j]>A[0];j=j-d){
					A[j+d]=A[j];
				}
				A[j+d]=A[0];
			}
		}
	}
	print(A); 
}
// ���������㷨
int Partition(int A[],int low,int high){
	int pivot=A[low];
	while(low<high){
		while(low<high&&A[high]>=pivot) high--;
		A[low]=A[high];
		while(low<high&&A[low]<=pivot)low++;
		A[high]=A[low]; 
	}
	A[low]=pivot;
	return low;
}

void QuickSort(int A[],int low,int high){
	if(low<high){
		int pivotpos=Partition(A,low,high);
		QuickSort(A,low,pivotpos-1);
		QuickSort(A,pivotpos+1,high);
	}	
}
//������(����ѣ� 

//void swap(int * a,int * b){
//	int temp;
//	temp=*a;
//	*a=*b;
//	*b=temp;
//}

void swap(int &a,int &b){
	//���þ���ĳһ������Ŀ�꣩��һ�������������õĲ�����Ա���ֱ�Ӳ�����ȫһ����
	//���õ��������������ͱ�ʶ��&������=Ŀ���������
	//&�ڴ˲������ַ���㣬�������ʶ���á�
	int temp;
	temp=a;
	a=b;
	b=temp;
}

void MaxHeapAdjust(int A[],int k,int len){
	A[0]=A[k];
	for(int i=k*2;i<=len;i=i*2){
		if(i<len&&A[i]<A[i+1])i++;
		if(A[0]>=A[i])break;
		else{
			A[k]=A[i];
			k=i;
		}
	}
	A[k]=A[0];
}
void BuildMaxHeap(int A[],int len){
	for(int i=len/2;i>0;i--){
		MaxHeapAdjust(A,i,len);
	}
}
void MaxHeapSort(int A[],int len){
	BuildMaxHeap(A,len);
	for(int i=len;i>1;i--){
		swap(A[1],A[i]);
		MaxHeapAdjust(A,1,i-1);
	}
}
//������(С���ѣ�
void MinHeapAdjust(int A[],int k,int len){
	A[0]=A[k];
	for(int i=k*2;i<=len;i=i*2){
		if(i<len&&A[i]>A[i+1])i++;//�޸�Ѱ��������������С���Ǹ� 
		if(A[0]<=A[i])break;//������ڵ��������������С�Ǹ���С�ͽ���ѭ�� 
		else{
			A[k]=A[i];
			k=i;
		}
	}
	A[k]=A[0];
}
void BuildMinHeap(int A[],int len){
	for(int i=len/2;i>0;i--){
		MinHeapAdjust(A,i,len);
	}
}
void MinHeapSort(int A[],int len){
	BuildMinHeap(A,len);
	for(int i=len;i>1;i--){
		swap(A[1],A[i]);
		MinHeapAdjust(A,1,i-1);
	}
}
//�鲢����

void Merge(int A[],int low,int mid,int high){
	int *B=(int *)malloc(N*sizeof(int));
	int i,j,k;
	for(k=1;k<=N-1;k++){
		B[k]=A[k];
	}
	for(i=low,j=mid+1,k=i;i<=mid&&j<=high;k++){
		if(B[i]<=B[j]){
			A[k]=B[i++];
		}
		else{
			A[k]=B[j++];
		}
	}
	while(i<=mid)A[k++]=B[i++];
	while(j<=high)A[k++]=B[j++];
}
void MergeSort(int A[],int low,int high){
	if(low<high){
		int mid=(low+high)/2;
		MergeSort(A,low,mid);
		MergeSort(A,mid+1,high);
		Merge(A,low,mid,high);
	}
} 

//��������
int PosSearch(int x,int d){
	int i,pos=1,position=0;
	for(i=1;i<=d;i++){
		if(x!=0&&i==d){
			position=x%R;
		}
		pos*=R;
		x/=pos;
	}
	return position;
}

void RadioSort(NodeType *p,int r,int d){
	NodeType *head[N],*tail[N],*t;
	int i,j,k;
	int pos=1,cnt=0;
	for(i=0;i<=d-1;i++){
		for(j=0;j<r;j++)
			head[j]=tail[j]=NULL;
		while(p!=NULL){
			k=PosSearch(p->data,i+1);
			if(head[k]==NULL){
				head[k]=p;tail[k]=p;
			}
			else{
				tail[k]->next=p;tail[k]=p;
			}
			p=p->next;
		}
		p=NULL;
		for(j=0;j<r;j++)
			if(head[j]!=NULL){
				if(p==NULL){
					p=head[j];t=tail[j];
				}
				else{
					t->next=head[j];t=tail[j]; 
				}
			}
		t->next=NULL;
	}
	
}
PrintRadioSort(NodeType *head){
	for(NodeType *p=head;p;p=p->next){
		printf("%d ",p->data);
	}
}
int main()
{	
//	printf("ϣ�������\n"); 
//	ShellSort(A,N-1);

//	printf("���������\n"); 
//	int low,high;
//	low=1;high=N-1;
//	QuickSort(A,low,high);
//	print(A);

//	printf("�����򣨴���ѣ������\n"); 
//	MaxHeapSort(A,N-1);
//	print(A);

//	printf("������С���ѣ������\n"); 
//	MinHeapSort(A,N-1);
//	print(A);

//	printf("���������\n"); 
//	int low,high;
//	low=1;high=N-1;
//	MergeSort(A,low,high);
//	print(A);
	NodeType *head=NULL,*tail;
	int posmax=0;
	for(int i=1;i<N;i++){
		int temp=A[i];
		int pos=0;
		while(temp!=0){
			temp/=10;
			pos++;
		}
		if(posmax<pos){
			posmax=pos;
		}
	}
	int d=posmax;
	for(int i=1;i<N;i++){
		NodeType *p=(NodeType *)malloc(sizeof(NodeType));
		p->next=NULL;
		p->data=A[i];
		
		if(i==1){
			head=p;
			tail=p;
			
		}
		else{
			tail->next=p;
			tail=p;
		}
	}
	RadioSort(head,R,d);
	PrintRadioSort(head);
 } 
