#include<bits/stdc++.h>
using namespace std;
int main(){
    double a,b;
    int t;
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(a<0.0) a=M_PI+a;
        if(b<0.0) b=M_PI+b;
        double rg=a-b,rt=abs(rg);
        if(rt>M_PI){
            if(rg>0.0){
                printf("counterclockwise\n");
            }else{
                printf("clockwise\n");
            }
        }else{
            if(rg>0.0){
                printf("clockwise\n");
            }else{
                printf("counterclockwise\n");
            }
        }
    }
    return 0;
}
