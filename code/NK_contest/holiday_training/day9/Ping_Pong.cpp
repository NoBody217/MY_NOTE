#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n),cnt(n);
    map<int,int>mp;
    for(int i=0;i<n;i++){
        cin >> a[i];
        mp[a[i]]=i;
    }
    vector<int> b=a;
    sort(b.begin(),b.begin()+n,greater());

    int max1=b[0],max2=b[1],fa=a[0],win1=0;
    
    deque<int> q;
    for(int i=1;i<n;i++){
        q.push_back(a[i]);
    }
    while(k){
        // cout << k << ' ' << fa << ' '<< q.front() << ' ' ;
        // for(int i=0;i<n;i++){
        //     cout << cnt[i] << ' ' ;
        // }
        // cout << endl;
        if(k>=2*(n-1)&&fa==max1&&q.back()==max2&&win1==1){
            int val=k/(2*(n-1));
            cnt[mp[max1]]+=val*(n-2);
            cnt[mp[max2]]+=val*(n-2);
            for(int i=0;i<n;i++){
              cnt[i]+=2*val;
            }
            k %=2*(n - 1);
          }else{
            cnt[mp[fa]]++;
            cnt[mp[q.front()]]++;
            if(fa>q.front()){
              win1++;
              if(win1==n){
                q.push_back(fa);
                fa = q.front();
                q.pop_front();
                win1 = 1;
              }else{
                q.push_back(q.front());
                q.pop_front();
              }
              k--;
            }else{
              q.push_back(fa);
              fa=q.front();
              q.pop_front();
              win1=1;
              k--;
            }
          }
    }
    for(int i=0;i<n;i++){
        cout << cnt[i] << ' ' ;
    }
    cout << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}