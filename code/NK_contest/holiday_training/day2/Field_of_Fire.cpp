#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> dis1(2e5);
vector<int> dis2(2e5);
signed main(){
    int t;
    cin >> t;
    while(t--){
        dis1.clear();
        dis2.clear();
        int n,ddl;
        cin >> n >> ddl;
        int cnt=0;
        string s;
        cin >> s;
        int mx=0,mxid=0;
        for(int i=0;i<2*n;i++){
            if(s[i%n]=='0'){
                cnt++;
            }else{
                cnt=0;
            }
            dis1[i%n]=cnt;
            if(dis1[i%n]>mx){
                mxid=i%n;
                mx=dis1[i%n];
            }
        }
        cnt=0;
        s[mxid]='1';
        for(int i=2*n-1;i>=0;i--){
            if(s[i%n]=='0'){
                cnt++;
            }else{
                cnt=0;
            }
            dis2[i%n]=cnt;
        }
        // cout << mxid << endl;
        for(int i=2*n-1;i>=0;i--){
            if(i%n==mxid){
                i--;
                while(s[i%n]!='1'&&i>=0){
                    dis2[i%n]=0x7f7f7f7f;
                    i--;
                }
            }
        }        
        int ans=0;
        // for(int i=0;i<n;i++){cout << dis1[i] << ' ';}
        // cout << endl;
        // for(int i=0;i<n;i++){cout << dis2[i] << ' ';}
        // cout << endl;
        for(int i=0;i<n;i++){
            if(dis1[i]>ddl&&dis2[i]>ddl) ans++;
        }
        cout << ans<< endl;
    }
    return 0;
}