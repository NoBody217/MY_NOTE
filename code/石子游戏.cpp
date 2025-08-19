#include<bits/stdc++.h>
using namespace std;
/**
 * 如果没有偶数且奇数不全是1，A分解，B分解，A合并，B分解——A必胜
 * 如果有偶数，所有奇数没有贡献，能合并cnt_even-1次
 */
int main(){
    int n;
    cin >> n;
    int cnt=0;
    int flg=0;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        if(tmp%2==0) cnt++;
        else if(tmp>=3) flg=1;
    }
    if(cnt>0){
        cout << ((cnt-1)%2?"Alice":"Bob") << endl;
    }else{
        cout << (flg?"Alice":"Bob") << endl;
    }
    return 0;
}