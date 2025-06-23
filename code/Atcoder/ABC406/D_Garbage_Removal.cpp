#include<bits/stdc++.h>
using namespace std;
set<int>a[202020],b[202020];
int main(){
    int n,h,w;
    cin >> h >> w >> n ;
    for(int i=0;i<n;i++){
        int  x,y ;
        cin >> x >> y ;
        a[x].insert(y);
        b[y].insert(x);
    }
    int q;
    cin >> q ;
    for(int i=0;i<q;i++){
        int op,t;
        cin >> op >> t;
        if(op==1){
            cout << a[t].size() << endl ;
            for(auto j:a[t]){
                b[j].erase(t);
            }
            a[t].clear();
        }else{
            cout << b[t].size() << endl ;
            for(auto j:b[t]){
                a[j].erase(t);
            }
            b[t].clear();            
        }

    }
    return 0;
}