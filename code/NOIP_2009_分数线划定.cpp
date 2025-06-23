#include<bits/stdc++.h>

using namespace std;
#define pii pair<int,int>

int cmp(pii a,pii b){
    if(a.second==b.second)
        return a.first<b.first;
    else
        return a.second>b.second;
}

int main(){
    int n,m;
    cin >> n >> m;
    m=m*1.5;
    // cout << n << ' ' << m << endl ;
    pii a[10101];
    for(int i=0;i<n;i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a,a+n,cmp);
    // for(int i=0;i<n;i++)  cout << a[i].first << ' ' << a[i].second << endl;
    int cnt=0;
    while(a[cnt].second>=a[m-1].second){
        // cout << a[cnt].first << ' ' << a[cnt].second << endl;
        cnt++;
    }
    cout << a[cnt-1].second << ' ' << cnt << endl ;
    for(int i=0;i<cnt;i++){
        cout << a[i].first << ' ' << a[i].second << endl;
    }
    return 0;
}