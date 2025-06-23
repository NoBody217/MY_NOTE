#include<bits/stdc++.h>
using namespace std;

vector<pair<char,long long>> b(303030);
int a[303030];
int main(){
    int n;
    cin >> n ;
    for(int i=1;i<=n;i++){
        cin >> a[i] ;
    }
    int pos=0;
    for(int i=1;i<=n;i++){
        if(a[i]<a[i+1]){
            if(b[pos].first!='i') b[++pos].first='i';
            b[pos].second++;
        }else{
            if(b[pos].first!='d') b[++pos].first='d';
            b[pos].second++;
        }
    }
    long long ans=0;
    for(int i=1;i<=pos;i++){
        if(b[i].first=='d'&&b[i-1].first=='i'&&b[i+1].first=='i'){
            ans+=b[i-1].second*b[i+1].second;
        }
    }
    cout << ans << endl;

    return 0;
}