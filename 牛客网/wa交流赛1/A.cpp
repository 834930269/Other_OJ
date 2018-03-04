#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
    scanf("%d",&T);
    while(T--){
        int p,q;
        cin>>p>>q;
        int ans;
        if(p==0){printf("-1\n");continue;}
        int md=abs(p)%abs(q);
        double c=1.0*p/q;
        int cc=p/q;
        if(md){
            if(c>0)
                printf("%d\n",cc);
            else printf("%d\n",cc-1);
        }else{
           printf("%d\n",cc-1);
        }
    }
    return 0;
}
