#include<bits/stdc++.h>
using namespace std;
using ll =long long ;
const int p=998244353;
/**
 * 对于一个子序列，可被唯一合法还原的条件是：
 * 必须是若干个'('在前，然后若干个')'，因为只要存在')('，将这两个交换必然合法，存在多种方案
 * 交换最后一个'('和第一个')'前缀和序列存在负值(非法情况)
 * 
 * 滑动窗口
 * 枚举l表示最后一个被变成'?'的'('的位置，然后找r为第一个被变成'?'的')'的位置
 */

ll qpow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=ans*a%p;
        a=a*a%p;
        b>>=1;
    }
    return ans;
}

ll ans=0;
ll a[1010101],pre[1010101],suf[1010101],sum[1010101];
int main(){
    string s;
    cin >> s;
    s=' '+s;
    for(int i=1;i<s.length();i++) {
        a[i]=(s[i]=='('?1:-1);
        sum[i]=a[i]+sum[i-1];
        // cout << sum[i] << ' ' ;
    }
    // cout << endl;
    for(int i=1;i<s.length();i++) pre[i]=pre[i-1]+(a[i]==1);
    for(int i=s.length()-1;i>=1;i--) suf[i]=suf[i+1]+(a[i]==-1);

    for(int l=1,r=1;l<s.length();l++){
        while(r<s.length()&&(sum[r]>1||r<l)) r++;
        if(r==s.length())break;
        if(a[l]==1){
            // cout << l << ' ' << r << ' ' << pre[l-1] << ' ' << suf[r+1] << endl;
            ans=(ans+(qpow(2,pre[l-1])*qpow(2,suf[r+1])%p))%p;
            // cout << ans << endl;
        }
    }

    ans=(ans+qpow(2,(s.length()/2))%p);
    
    // cout << ans << endl;
    ll inv=qpow(qpow(2,s.length()-1),p-2);
    cout << (ans*inv)%p << endl;
    return 0;
}


