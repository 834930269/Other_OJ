#include<bits/stdc++.h>
using namespace std;

int m,n,q,ct;
char mp[200][200];
int res[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

void fill_c(int x,int y,char c){
    if(x<0||x>=n||y<0||y>=m||mp[x][y]=='-'||mp[x][y]=='|'||mp[x][y]=='+' || mp[x][y]==c)
        return;
    mp[x][y]=c;
    for(int i=0;i<4;++i){
        fill_c(x+res[i][0],y+res[i][1],c);
    }
}

void fill_l(int x1,int y1,int x2,int y2){
    if(x1==x2){
        int d=min(y1,y2),l=max(y1,y2);
        for(int i=d;i<=l;++i){
            if(mp[x1][i]=='|'||mp[x1][i]=='+')
                mp[x1][i]='+';
            else mp[x1][i]='-';
        }
    }else{
        int d=min(x1,x2),l=max(x1,x2);
        for(int i=d;i<=l;++i){
            if(mp[i][y1]=='-'||mp[i][y1]=='+')
                mp[i][y1]='+';
            else mp[i][y1]='|';
        }
    }
}

int main(){
    cin>>m>>n>>q;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            mp[i][j]='.';
        }
    }
    for(int i=0;i<q;++i){
        cin>>ct;
        if(ct==1){
            int x,y;
            char c;
            cin>>x>>y>>c;
            fill_c(y,x,c);
        }else{
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            fill_l(y1,x1,y2,x2);
        }
    }
    for(int i=n-1;i>=0;--i){
        for(int j=0;j<m;++j){
            printf("%c",mp[i][j]);
        }
        printf("\n");
    }
    return 0;
}
