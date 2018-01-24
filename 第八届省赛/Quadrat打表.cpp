#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;

const int num[5]={1,10,100,1000,10000};
int a[15][15];
void init(){
    memset(a, 0, sizeof(a));
    for(int i = 0; i <= 9; ++i){
        for(int j = 0; j <= 9; ++j){
            a[i][j] = abs(i-j);
            if(a[i][j] > 5) a[i][j] = 10 - a[i][j];
        }
    }
}

bool judge(int i,int digit,int d){
    int res=i*i;
    for(int j=1;j<=digit;++j){
        int b=i%10;
        int c=res%10;
        i/=10;res/=10;
        if(a[b][c]>d) return false;
    }
    return true;
}

int check(int nb,int d){
    int cnt=0;
    for(int i=0;i<num[nb];++i){
        if(judge(i,nb,d))
            cnt++;
    }
    return cnt;
}

int main(){
    init();
    for(int i=1;i<=4;++i){
        printf("%d:",i);
        for(int j=0;j<4;++j){
            printf(" %d",check(i,j));
        }
        printf("\n");
    }
    return 0;
}
