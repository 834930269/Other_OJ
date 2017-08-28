#include<bits/stdc++.h>
using namespace std;
const int maxn=110;

int p,r,u,q;

struct Edge{
    string a;
    int le;
};

struct star{
    vector<Edge> cs;
};

struct per{
    map<string,int> gra;
};

string sr;
map<string,int> gran;
map<string,star> vv;
map<string,per> pp;

int main(){
    scanf("%d",&p);
    for(int i=0;i<p;++i){
        cin>>sr;
        int len=sr.length();
        if(isdigit(sr[len-1])){
            int nnn=sr[len-1]-'0';
            string qb=sr.substr(0,len-2);
            if(gran.count(qb)>0) nnn=max(gran[qb],nnn);
            gran[qb]=nnn;
        }else{
            gran[sr]=-1;
        }
    }
    string st,stt;
    int ss;
    scanf("%d",&r);
    for(int i=0;i<r;++i){
        cin>>st>>ss;
        for(int j=0;j<ss;++j){
            cin>>stt;
            int len=stt.length();
            if(isdigit(stt[len-1])){
                int nnn=stt[len-1]-'0';
                string qb=stt.substr(0,len-2);
                vv[st].cs.push_back((Edge){qb,nnn});
            }else{
                vv[st].cs.push_back((Edge){stt,-1});
            }
        }
    }
    scanf("%d",&u);
    for(int i=0;i<u;++i){
        cin>>st>>ss;
        for(int j=0;j<ss;++j){
            cin>>stt;
            vector<Edge>& reg=vv[stt].cs;
            map<string,int>& png=pp[st].gra;
            for(int t=0;t<reg.size();++t){
                int nnn=reg[t].le;
                if(png.count(reg[t].a)>0) nnn=max(nnn,png[reg[t].a]);
                png[reg[t].a]=nnn;
            }
        }
    }
    scanf("%d",&q);
    for(int i=0;i<q;++i){
        cin>>st>>stt;
        int len=stt.length();
        if(pp.count(st)<=0) {puts("false");continue;}
        map<string,int>& qq=pp[st].gra;
        if(isdigit(stt[len-1])){
            int ll=stt[len-1]-'0';
            string tt=stt.substr(0,len-2);
            if(qq.count(tt)>0){
                int nm=qq[tt];
                if(nm==-1) puts("true");
                else if(nm>=ll) puts("true");
                else puts("false");
            }else puts("false");
        }else{
            int ll=-1;
            if(qq.count(stt)>0){
                int nm=qq[stt];
                if(nm>=0)printf("%d\n",nm);
                else puts("true");
            }
            else puts("false");
        }
    }
    return 0;
}
