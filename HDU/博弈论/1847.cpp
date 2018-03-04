//SG函数
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

bool game[1001];

void init(){
    memset(game,false,sizeof(game));
    for(int i=1;i<=1000;++i){
        int t=1;
        while(i-t>=0){
            //如果i-t是奇异局势,则先手必胜
            if(!game[i-t]){
                game[i]=true;
                break;
            }
            t<<=1;
        }
    }
}

int main(){
    init();
    int n;
    while(~scanf("%d",&n)){
        if(game[n]){
            printf("Kiki\n");
        }else{
            printf("Cici\n");
        }
    }
    return 0;
}
