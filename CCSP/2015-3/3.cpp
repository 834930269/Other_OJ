#include<cstdio>
#include<iostream>
using namespace std;
///1850/1/1   2
///闰年366天,非闰年365天
const int maxn=3000;
int s[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int od[maxn];
int a,b,c,y1,y2;

bool isleap(int y){
    if(y%400==0 || y%100 && y%4==0) return 1;
    return 0;
}

void init(){
    for(int i=0;i<1000;++i){
        int year=1850+i;
        od[i]=((year-1)+((year-1)>>2)-(year/100)+(year/400)+1) %7;
    }
}

int main(){
    init();
    cin>>a>>b>>c>>y1>>y2;
    if(c==7) c=0;
    for(int i=y1-1850;i<=y2-1850;++i){
        int now=i+1850;
        if(isleap(now)){
            s[2]=29;
        }else{
            s[2]=28;
        }
        int pre=0;
        for(int j=1;j<=a-1;++j){
            pre+=s[j];
        }
        int nweek=(pre+od[i])%7;
        //printf("%d %d\n",nweek,od[i]);
        int cnt=0,flag=0;
        for(int j=0;j<s[a];++j){
            int nw=(nweek+j)%7;
            if(nw==c)++cnt;
            if(cnt==b && nw==c){
                printf("%d/%02d/%02d\n",i+1850,a,j+1);
                flag=1;
                break;
            }
        }
        if(!flag){
            puts("none");
        }
    }
    return 0;
}
