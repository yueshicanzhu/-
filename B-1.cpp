#include<stdio.h>
#include<string.h>
#define MAX_Size 100
char longest_str[MAX_Size],temp[MAX_Size];
int max_i=0,max_j=0;
char Str[MAX_Size]="^#";

void BF_search(char str[],int len){
	int i,j,Pal_len,max_len=0;
	for(i=0;i<len;i++){
		for(j=i;j<len;j++){
			int ii=i,jj=j;
			while(ii<jj){
				if(str[ii]!=str[jj])break;
				ii++;
				jj--;
			}
			if(ii>=jj){
				Pal_len=j-i;
				if(max_len<Pal_len){
					max_i=i;
					max_j=j;
					max_len=Pal_len;
				}
			}
		}
	}
}

//���ַ����д���
int expend_deal(char str[],int len) {
	int i,j=2;
	for(i=0;i<len;i++){
		Str[j++]=str[i];
		Str[j++]='#';
	}
	Str[j]='\0';
	return j;
}
int start,maxlen=0;

void manacher(char str[],int len) {
	int len1=expend_deal(str,len);
	int max;
	int P[MAX_Size]={0};
    int c = 0, r = 0;
    for(int i = 1; i<len1;i++) {
        int i_mirror=2*c-i;//�ҵ�����i�������ĵ�c (center) �ԳƵ�  r�뾶�ϵ�ǰһ���ԳƵ� 
        //������� i < r �� i > =r
		// �� 1 �� i < r����Ϊ P[i_mirror]+ i <r �� P[i_mirror]+ i> r 
        if(i < r) {
            P[i] = ((r-i)<P[i_mirror])?(r-i):P[i_mirror];//�����ǵ�һ���������i����Ӧ��P[i]��δ֪�ģ�������ζ�ȡ��С���Ǹ� ��Ϊ P[i]��ֵ����������ʱ��P[i]ֵ��������ڻ��Ĵ�����¡� 
        } else {
            P[i] = 0;//�ڶ����������Ҫ������� 
        }
		//������� 
        while(Str[i + P[i] + 1] == Str[i - P[i] - 1]) {
            P[i]++;//������һ������ģ���ƶ�����ָ�� i �� j ,��Ϊһ��P[i], ͬʱҲ��Ϊ�˸���P[i]��ֵ 
        }
        //�� 2 ��������� 
        if(P[i] + i > r) {
            r = i + P[i];//���°뾶 
            c = i;//�������ĵ�c 
        }
    }
    //��P[i]���ֵ 
    int imax = 0;
    for(int i = 1; i<len1; i++) {
        if(P[i] > maxlen) {
            maxlen=P[i];
            imax=i;
        }
    }
    start=(imax - maxlen)/2;//ע��������ԭ���ַ����� str[]��λ�ã��������� '#' ���Str[] ��ͬʱ����ȡ������P[i]-1Ϊԭ���ַ����ĳ��ȣ� 
}
    
int main()
{
	char str[MAX_Size];
	scanf("%s",str);
	int length=strlen(str);
	BF_search(str,length);
	manacher(str,length);
//	printf("�����������:");
//	for(int i=max_i;i<=max_j;i++){
//		printf("%c",str[i]);
//	}
	for(int i=start;i<start+maxlen;i++){
		printf("%c",str[i]);
	}
	return 0;
}
