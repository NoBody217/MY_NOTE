#include<bits/stdc++.h>

using namespace std;

const int p=998244353;

int a[505050];
int day[505050][2],cnt[505050][2];
/**
 * 当前位是0,对方案数和天数都不会影响
 * 当前位是1,上一位是0的时候天数增加总方案数，上一位是1天数不变
 * 总方案数不变
 * 当前位是-1,天数和方案数是前两种情况加和
 */
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n ;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        if(a[1]==1){
            day[1][1]=1;day[1][0]=0;
            cnt[1][1]=1;cnt[1][0]=0;
        }else if(a[1]==0){
            day[1][1]=0;day[1][0]=0;
            cnt[1][1]=0;cnt[1][0]=1;            
        }else{
            day[1][1]=1;day[1][0]=0;
            cnt[1][1]=1;cnt[1][0]=1;   
        }
        for(int i=2;i<=n;i++){
            if(a[i]==1){
                day[i][1]=(day[i-1][0]+cnt[i-1][0]+day[i-1][1])%p;
                day[i][0]=0;
                cnt[i][1]=(cnt[i-1][0]+cnt[i-1][1])%p;
                cnt[i][0]=0;
            }else if(a[i]==0){
                day[i][0]=(day[i-1][0]+day[i-1][1])%p;
                day[i][1]=0;
                cnt[i][0]=(cnt[i-1][0]+cnt[i-1][1])%p;
                cnt[i][1]=0;
            }else{
                day[i][1]=(day[i-1][0]+cnt[i-1][0]+day[i-1][1])%p;
                day[i][0]=(day[i-1][0]+day[i-1][1])%p;
                cnt[i][1]=(cnt[i-1][0]+cnt[i-1][1])%p;
                cnt[i][0]=(cnt[i-1][0]+cnt[i-1][1])%p;
            }
        }
        cout << ((day[n][1]+day[n][0])%p) << endl;
    }
    return 0;
}
