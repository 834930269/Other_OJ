#include<bits/stdc++.h>
using namespace std;
int T;
char str[1000];
int main(){
    cin>>T;
    while(T--){
        int N,M;
        cin>>N>>M;
        int c=0,m=0,o=0,b=0;
        getchar();
        for(int i=0;i<N;++i){
            gets(str);
            if(str[0]=='C'){
                c++;
            }else if(str[0]=='M'){
                m++;
            }else if(str[0]=='O'){
                o++;
            }else if(str[0]=='B'){
                b++;
            }
        }
        int ans=o*(2+(N-1)+m*2)+b*(2+m*2);
        if(ans>=M){
            puts("Mrghllghghllghg!");
        }else puts("Tell you a joke, the execution of Paladin.");
    }
    return 0;
}
