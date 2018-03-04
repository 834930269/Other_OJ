#include<bits/stdc++.h>
using namespace std;
const int maxn=310;
struct Point{
    int x,y;
    bool operator < (const Point& a)const{
        if(x<a.x) return true;
        else if(x==a.x && y<a.y) return true;
        return false;
    }
    bool operator == (const Point& a)const{
        if(x==a.x && y==a.y) return true;
        return false;
    }

};
int N,kase=1;

int xx,yy;
char opt[10];

map<Point,bool> G;//x点集0,true为未删除,false为删除
map<Point,bool>::iterator it;

void init(){
    G.clear();
}

void add(){
    G[(Point){xx,yy}]=true;
}

void find_(int a,int b){
    it=G.upper_bound((Point){a,b});
    if(it==G.end()){
        printf("-1\n");
        return;
    }
    Point nw=it->first;
    if(it->second && nw.x>xx && nw.y>yy){
        printf("%d %d\n",nw.x,nw.y);
    }else{
        do{
            it++;
            if(it==G.end()){printf("-1\n");return;}
            if(it->second && (it->first).x>xx && (it->first).y>yy){
                printf("%d %d\n",(it->first).x, (it->first).y);
                return;
            }
        }while(1);
    }
}

void remove_(){
    G[(Point){xx,yy}]=false;
}

int main(){
    while(~scanf("%d",&N) && N){
        init();
        printf("Case %d:\n",kase++);
        for(int i=0;i<N;++i){
            scanf("%s %d %d",opt,&xx,&yy);
            if(opt[0]=='a'){
                add();
            }else if(opt[0]=='f'){
                find_(xx,yy);
            }else{
                remove_();
            }
        }
        printf("\n");
    }
    return 0;
}
