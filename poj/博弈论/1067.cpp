//Íþ×ô·ò²©ÞÄ
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        int k=max(n,m)-min(n,m);
        int ak=k*(1+sqrt(5))/2;
        int bk=ak+k;
        if(min(n,m)==ak&&max(n,m)==bk){
            printf("0\n");
        }else{
            printf("1\n");
        }
    }
    return 0;
}
