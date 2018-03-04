#include<bits/stdc++.h>
using namespace std;
const int maxn=10010,maxm=5010;
int N;
stack<char> st;
int main(){
    while(~scanf("%d\n",&N)){
        char qb;
        while(N--){
            int f=0;
            do{
                do{
                    qb=getchar();
                    if(isalpha(qb)) st.push(qb);
                }while(qb!=' ' && qb!='\n');
                if(f==0)f++;
                else printf(" ");
                while(!st.empty()){
                    printf("%c",st.top());
                    st.pop();
                }
            }while(qb!='\n');
            printf("\n");
        }
    }
    return 0;
}
