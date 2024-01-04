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

//对字符进行处理，
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
        int i_mirror=2*c-i;//找到关于i关于中心点c (center) 对称的  r半径上的前一个对称点 
        //两种情况 i < r 和 i > =r
		// 第 1 种 i < r，分为 P[i_mirror]+ i <r 和 P[i_mirror]+ i> r 
        if(i < r) {
            P[i] = ((r-i)<P[i_mirror])?(r-i):P[i_mirror];//这里是第一种情况，（i所对应的P[i]是未知的）无论如何都取最小的那个 将为 P[i]的值，这里是暂时的P[i]值，如果存在回文串会更新。 
        } else {
            P[i] = 0;//第二种情况，需要暴力求解 
        }
		//暴力求解 
        while(Str[i + P[i] + 1] == Str[i - P[i] - 1]) {
            P[i]++;//这里用一个变量模拟移动两个指针 i 和 j ,简化为一个P[i], 同时也是为了更新P[i]的值 
        }
        //第 2 种情况更新 
        if(P[i] + i > r) {
            r = i + P[i];//更新半径 
            c = i;//更新中心点c 
        }
    }
    //找P[i]最大值 
    int imax = 0;
    for(int i = 1; i<len1; i++) {
        if(P[i] > maxlen) {
            maxlen=P[i];
            imax=i;
        }
    }
    start=(imax - maxlen)/2;//注意这里是原来字符数组 str[]的位置，并非增加 '#' 后的Str[] ，同时向下取整。（P[i]-1为原来字符串的长度） 
}
    
int main()
{
	char str[MAX_Size];
	scanf("%s",str);
	int length=strlen(str);
	BF_search(str,length);
	manacher(str,length);
//	printf("最长回文子序列:");
//	for(int i=max_i;i<=max_j;i++){
//		printf("%c",str[i]);
//	}
	for(int i=start;i<start+maxlen;i++){
		printf("%c",str[i]);
	}
	return 0;
}
