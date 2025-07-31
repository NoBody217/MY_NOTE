#include<bits/stdc++.h>
using namespace std;
    
/**
 * 000 2
 * 0110 1
 * 01110->10110->10101 2
 * 01011 2
 * 00000 2
 * 0000000->1100...->1010000->1010110->1010101
 * 11111->10011->10101 2
 * 1111111->0011111->0101111->0101001->0101010 4
 * 111 111 111
 */

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    s=' '+s;
    string s1=s,s2=s;
    int cnt1=0,cnt2=0;
    for(int i=1;i<n;i++){
        if(s1[i]!=i%2+'0'){
            cnt1++;
            s1[i]='1'-s1[i]+'0';
            s1[i+1]='1'-s1[i+1]+'0';
        }
    }
    if(s1[n]==s1[n-1]) cnt1=INT32_MAX;
    for(int i=1;i<n;i++){
        if(s2[i]!=(i+1)%2+'0'){
            cnt2++;
            s2[i]='1'-s2[i]+'0';
            s2[i+1]='1'-s2[i+1]+'0';
        }
    }
    if(s2[n]==s2[n-1]) cnt2=INT32_MAX;    

    // cout << s << endl << s1 <<endl << s2 << endl;
    int ans=min(cnt1,cnt2);
    cout << (ans==INT32_MAX?-1:ans) << endl;

    
    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}