#include <bits/stdc++.h>
using namespace std;

long long a[202020];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    //有可能中间的牌放完了但不够推倒最后一个
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<long long> mid;
        for (int i = 1; i < n - 1; i++) mid.push_back(a[i]);
        sort(mid.begin(), mid.end());
        long long cur = a[0];
        int used = 1;
        int i = 0;
        while (i<mid.size()&&cur*2<a[n - 1]) {
            int j=upper_bound(mid.begin(),mid.end(),2*cur)-mid.begin();
            if (j==i){
                used=-1;
                break;
            }
            cur=mid[j-1];
            used++;
            i=j;
        }
        if(used!=-1){
            if(cur*2<a[n-1])
                used=-1;
            else
                used++;
        }
        cout << used << '\n';
    }
    return 0;
}
