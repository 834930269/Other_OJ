#include<bits/stdc++.h>
using namespace std;

bool has_h(int h){
    if(h%10==7) return true;
    return false;
}
bool has_m(int m){
    if(m%10==7)return true;
    return false;
}

int main(){
    int n;
    while(~scanf("%d",&n)){
        int h,m,cnt;
        cin>>h>>m;
        for(cnt=0;;cnt++){
            int ad=cnt*n;
            int nh=h,nm=m;
            //¼õ
            if(ad<m+1){
                nm-=ad;
            }else{
                nm=59-((ad-m-1)%60);
                nh-=1;
                int mh=(ad-m-1)/60;
                if(mh<nh+1){
                    nh-=mh;
                }else{
                    nh=23-(mh-nh-1)%24;
                }
            }
            //printf("%d %d\n",nh,nm);
            if(has_h(nh)||has_m(nm)){
                printf("%d\n",cnt);
                break;
            }
        }
    }
    return 0;
}
