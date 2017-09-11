#include<bits/stdc++.h>
using namespace std;
int N,M;
int matrix[50][50];
bool row_del[50][50],col_del[50][50];

void dfs_row(int r,int c,int cnt){
    if(row_del[r][c]) return;
    for(int i=r+1;i<N;++i){
        if(matrix[i][c]==matrix[r][c]){
            cnt++;
        }else break;
    }
    if(cnt>=3){
        for(int i=r;i<cnt+r;++i)
            row_del[i][c]=true;
    }
}

void dfs_col(int r,int c,int cnt){
    if(col_del[r][c]) return;
    for(int i=c+1;i<M;++i){
        if(matrix[r][i]==matrix[r][c]){
            cnt++;
        }else break;
    }
    if(cnt>=3){
        for(int i=c;i<cnt+c;++i)
            col_del[r][i]=true;
    }
}

int main(){
    memset(row_del,false,sizeof(row_del));
    memset(col_del,false,sizeof(col_del));
    cin>>N>>M;
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            cin>>matrix[i][j];
        }
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            dfs_row(i,j,1);
            dfs_col(i,j,1);
        }
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            if(row_del[i][j] || col_del[i][j]){
                printf("0 ");
            }else printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
