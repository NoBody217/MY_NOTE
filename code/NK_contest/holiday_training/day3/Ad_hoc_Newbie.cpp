#include<bits/stdc++.h>
using namespace std;

int a[2020];
int maze[2020][2020];
void solve(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i] ;
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(j==i)maze[i][j]=(a[j]==1?0:1);
            else{
                maze[i][j]=(a[j]!=i+2?i+2:0);
                maze[j][i]=(a[j]!=i+2?i+2:0);                
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << maze[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}