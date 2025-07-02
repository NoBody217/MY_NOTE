#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+7;
int a[N];
int main (){
    int t;
    cin >> t;
    while(t--){
        int n,m=0;
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        int A=a[1],B=a[n];
        if(A*2>=B){ cout << 2 << endl; continue; }

        for(int i=1;i<=n;i++){
            if(a[i]>A&&a[i]<B) a[++m]=a[i];
        }

        sort(a+1,a+m+1);
        int ans=2,cur=A;

        for(int i=1;i<=m;){
            if(a[i]>2*cur){ ans=-1; break; }
            int j=i;
            while(j<m&&a[j+1]<=2*cur)j++;
            cur=a[j];
            ans++;
            if(cur*2>=B) break;
            i=j+1;
        }
        if(cur*2<B) ans=-1;
        cout << ans  << endl;
    }
    return 0;
}