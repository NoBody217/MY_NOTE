#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;

std::mt19937 rng;
int rand(int l,int r){//int随机数生成
    std::uniform_int_distribution<int> distribution(l,r);
    return(distribution(rng));
}


vector<int> a(252525);
vector<int> sum1(252525);
vector<int> sum2(252525);
vector<int> ha(252525);
vector<int> pre(252525);
signed main(){
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sum1[i]=sum1[i-1]+a[i];
        sum2[i]=sum2[i-1]+a[i]*a[i];
    }

    for(int i=1;i<=202020;i++){
        ha[i]=rand(1,1e18);
    }

    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]^ha[a[i]];
    }

    while(q--){
        bool ok=1;
        int l,r;
        cin >> l >> r;
        int len=r-l+1;
        if(len%2){
            cout << "No" << endl;
            continue;
        }else{
            len/=2;
            if(len<=500){
                vector<int> cnt(len+1);
                bool ok=1;

                for(int i=l;i<=r;i++){
                    if(a[i]>len){
                        ok=false;
                        break;
                    }
                    cnt[a[i]]++;
                }
                if(!ok){
                    cout << "No" << endl;
                    continue;
                }

                for(int i=1;i<=len;i++){
                    if(cnt[i]!=2){
                        ok=false;
                        break;
                    }
                }
                cout << (ok?"Yes":"No") << endl;
            }else{
                if(pre[l-1]^pre[r]){
                    cout << "No" << endl;
                    continue;
                }
                int jg1=len*(len+1);
                if(sum1[r]-sum1[l-1]!=jg1){
                    cout << "No" << endl;
                    continue;
                }
                int jg2=len*(len+1)*(2*len+1)/3;
                if(sum2[r]-sum2[l-1]!=jg2){
                    cout << "No" << endl;
                    continue;
                }
                cout << "Yes" << endl;
            }
        }
    }
    return 0;
}