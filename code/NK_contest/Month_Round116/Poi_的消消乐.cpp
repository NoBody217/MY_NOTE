#include<bits/stdc++.h>
using namespace std;
/**
 * 共计三种情况
 * 全都是一种字母：压缩为只有一个
 * 前半段是第一种字母，后半段是第二种字母：一定可以压缩为前半段只剩1个，后半段最多3个
 * 超过两段：ABAB……，从第二个A之后的所有A都可以被压缩掉
 * 前面的A可以压缩至第一个B后面的唯一一个A，变为BAB，A后面的B可以全压缩掉，最后变为BA
 * 
 */
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n ;
        string s;
        cin >> s ;
        int a=count(s.begin(),s.end(),s[0]);
        int b=0;
        for(int i=0;i<n;i++){
            if(s[i]==s[0]) b++;
            else break;
        }
        if(a==b) cout << 1+min(n-a,3) << endl ;//前两种情况
        else cout << 2 << endl;

    }
    return 0;
}