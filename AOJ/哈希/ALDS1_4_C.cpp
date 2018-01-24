/*
//alds1_4_c:Dictionary
//�㷨:���ŵ�ַ��ɢ�б�
//Time: 2018/1/8 ����һ
*/
#include<stdio.h>
#include<string.h>

const int M=1000003;
const int L=14;

char H[M][L];

//����ÿ���ַ����صĶ���ֵ
int getChar(char ch){
    if(ch=='A') return 1;
    if(ch=='C') return 2;
    if(ch=='D') return 3;
    if(ch=='T') return 4;
    return 0;
}
//�����ַ������صĳ�ʼɢ��ֵ
long long getKey(char str[]){
    long long len=strlen(str),sum=0,p=1;
    for(int i=0;i<len;++i){
        sum+=p*getChar(str[i]);
        //ÿ�λ�ȡ����ֵ��p*5,�൱��ת���������,�����ͻ
        p*=5;
    }
    return sum;
}

//����ʽɢ��ֵ����ʽ: h(k,i)=(h1(k)+i*h2(k))%M
int h1(int key){
    return key%M;
}
//Ϊ�˱�֤����ݹ��ͻ(����������ʼ����ͬ),����ʹh2(key)��M����
//TLE��õ�������Ǹ��������= =
//Ŀǰ����AC��: 1+(key%(M-1))
//(1+key)%(M-1)
int h2(int key){
    return (1+key)%(M-1);
}

//����
//-1��ʾ�ҵ�
//h��ʾ�ҵ���һ���ɲ����
int find(char str[]){
    long long key=getKey(str),i,h;
    for(i=0;;++i){
        h=(h1(key)+i*h2(key))%M;
        if(strcmp(H[h],str)==0) return -1;
        else if(strlen(H[h])==0) return h;
    }
    return 0;
}

//����
void insert(char str[]){
    int key=find(str);
    if(key!=-1) strcpy(H[key],str);
}

int main(){
    for(int i=0;i<M;++i) H[M][0]='\0';
    char str[L],com[L];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%s %s",com,str);

        if(com[0]=='i'){
            insert(str);
        }else{
            if(find(str)==-1)
                printf("yes\n");
            else
                printf("no\n");
        }
    }

    return 0;
}
