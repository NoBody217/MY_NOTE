#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,f=0;
    cin >> n >> m ;
    if(n>m){
        swap(n,m);
        f=1;
    }
    vector<vector<int>> g(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++){
        g[i][i]=i;
    }
    for(int i=n+1;i<m;i++){
        g[n][i]=i;
    }
    int lie_sum=m;
    for(int i=1;i<n;i++){
        g[i][m]=i^(i+m);
        lie_sum^=g[i][m];
    }
    g[n][m]=lie_sum;
    for(int i=1;i<m;i++){
        lie_sum^=g[n][i];
    }
    if(lie_sum!=n+m) cout << -1 << endl;
    else{
        if(f==0){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    cout << g[i][j] << " \n"[j==m] ;
                }
            }
        }else{
            for(int i=1;i<=m;i++){
                for(int j=1;j<=n;j++){
                    cout << g[j][i] << " \n"[j==n] ;
                }
            }
        }

    }

    return 0;
}