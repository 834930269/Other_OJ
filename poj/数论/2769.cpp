/*
����Ϊ������й�ʽ...
˭֪����Ҫ������???
����ÿ��ö��ǰ��memset????
���Ӷ���Ŀ���ô...
*/

#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1000000+100;

bool exist[100010];
int num[maxn];
int T;

int main(){
    scanf("%d",&T);
    while(T--){
        int N;
        scanf("%d",&N);
        for(int i=1;i<=N;++i){
            scanf("%d",&num[i]);
        }
        for(int j=1;;++j){
            bool is=true;
            memset(exist,false,sizeof(exist));
            for(int k=1;k<=N;++k){
                if(exist[num[k]%j]){
                    is=false;
                    break;
                }
                exist[num[k]%j]=true;
            }
            if(is){
                printf("%d\n",j);
                break;
            }
        }
    }
    return 0;
}
