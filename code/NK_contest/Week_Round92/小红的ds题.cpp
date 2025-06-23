#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a[2020]={0};
    cin >> n ;
    int sum=1;
    int idx=1;
    vector<int>now;
    vector<int>pst(1,1);
    unordered_map<int,int> L,R;
    for(int i=1;i<=n;i++){
        int num;
        cin >> num ;
        if(i==1) continue;
        sum+=num;
        for(auto j:pst){
            if(num>=2){
                now.push_back(++idx);
                L[j]=idx;
                now.push_back(++idx);
                R[j]=idx;
                num-=2;
            }else if(num>=1){
                now.push_back(++idx);
                L[j]=idx;
                R[j]=-1;
                num--;
            }else{
                L[j]=-1;
                R[j]=-1;
            }
        }
        pst=now;
        now.clear();        
    }
    for(auto i:pst){
        L[i]=-1;R[i]=-1;
    }
    cout << 1 << endl;
    for(int i=1;i<=sum;i++){
        cout << L[i] << ' ' << R[i] << endl;
    }

    return 0;
}