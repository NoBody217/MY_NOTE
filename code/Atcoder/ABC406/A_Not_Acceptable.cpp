#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a<c) cout << "No\n";
    else if(a>c) cout << "Yes\n";
    else{
        if(b>d) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}