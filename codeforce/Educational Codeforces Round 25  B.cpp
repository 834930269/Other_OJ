#include<bits/stdc++.h>
using namespace std;
char mp[11][11];
bool re;
int d[8][3]={{0,1},{1,0},{1,1},{1,-1},{-1,1},{-1,-1},{0,-1},{-1,0}};

bool check(int x,int i,int y,int j){
    if(x+i>=0&&x+i<10&&y+j>=0&&y+j<=10)
        return true;
    else return false;
}

void dfs(int x,int y,int win,int ct,int dir){
 //   if(dir==3)
 //       printf("(%d,%d):%d %d\n",x,y,win,dir);
    if(win==5 || re){re=true;return;}
    int i=d[dir][0],j=d[dir][1];
    if(check(x,i,y,j)){
        if(mp[x+i][y+j]=='X') dfs(x+i,y+j,win+1,ct,dir);
        if(mp[x+i][y+j]=='.' && ct==0) dfs(x+i,y+j,win+1,1,dir);
    }
}

int main(){
    re=false;
    for(int i=0;i<10;++i)
        gets(mp[i]);
    for(int i=0;i<10;++i){
        if(re)break;
        for(int j=0;j<10;++j){
            if(mp[i][j]=='X'){
                for(int k=0;k<8;++k){
                    dfs(i,j,1,0,k);
                    if(re)break;
                }
                if(re)break;
            }
        }
    }
    if(re)printf("YES\n");
    else printf("NO\n");
    return 0;
}

/**
....X.....
...X.OOOO.
..X.......
.X........
..........
..........
..........
..........
..........
..........
**/
