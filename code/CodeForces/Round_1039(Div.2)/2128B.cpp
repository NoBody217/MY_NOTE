#include<bits/stdc++.h>
using namespace std;

int a[100010];
vector<int> result;
string path;
int n;

bool check() {
    int len = result.size();
    if(len < 5) return false;
    bool inc = true, dec = true;
    for(int i = len-4; i < len; i++) {
        if(result[i-1] >= result[i]) inc = false;
        if(result[i-1] <= result[i]) dec = false;
    }
    return inc || dec;
}

bool dfs(int l, int r) {
    if(l > r) return true;

    result.push_back(a[l]);
    path += "L";
    if(!check() && dfs(l+1, r)) {
        return true;
    }
    result.pop_back();
    path.pop_back();
    
    result.push_back(a[r]);
    path += "R";
    if(!check() && dfs(l, r-1)) {
        return true;
    }
    result.pop_back();
    path.pop_back();
    
    return false;
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    result.clear();
    path = "";
    dfs(1, n);
    cout << path << endl;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}