#include<bits/stdc++.h>
using namespace std;


char mp[1010][1010];
int main(){
    int n,m;
    int nx,ny;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> mp[i][j];
            if(mp[i][j]=='#'){
                nx=i;ny=j;
            }
        }
    }
    if(nx==1||ny==m){
        for(int i=0;i<n-1;i++) cout << 'S' ;
        for(int i=0;i<m-1;i++) cout << 'D' ;
    }else{
        for(int i=0;i<m-1;i++) cout << 'D' ;
        for(int i=0;i<n-1;i++) cout << 'S' ;        
    }
    return 0;
}