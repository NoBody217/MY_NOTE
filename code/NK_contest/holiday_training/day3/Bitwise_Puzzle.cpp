#include<bits/stdc++.h>
using namespace std;

int geth(int x){
    if(x==0) return -1;
    int cnt=0;
    while(x){
        cnt++;
        x>>=1;
    }
    return cnt;
}

int a,b,c;
vector<int> path;
void op1(){ path.push_back(1); a<<=1; }
void op2(){ path.push_back(2); b>>=1; }
void op3(){ path.push_back(3); a^=b; }
void op4(){ path.push_back(4); b^=a; }

/**
 * c:10001010
 * a:00010101
 * b:00011000
 */
void solve(){
    path.clear();
    cin >> a >> b >> c;
    int ha=geth(a),hc=geth(c),hb=geth(b);
    if(a==b&&a==0){
        if(c==0){ cout << 0 << endl; return ;}
        else{ cout << -1 << endl; return ;}
    }
    //总保证a和b最高位相同
    if(ha>hb){op4();hb=ha;}
    if(hb>ha){op3();ha=hb;}
    
    if(ha>=hc){
        for(int i=ha-1;i>=0;i--){
            if(((a>>i)&1)!=((c>>i)&1)){
                op3();
            }
            op2();
        }
        op4();
    }else{
        int cnt=1;
        while(ha<hc){
            if(((a>>(ha-cnt))&1)!=((c>>(hc-cnt))&1)){
                op3();
            }
            cnt++;
            ha++;
            op1();
        }
        while(hb){
            if(((a>>(hb-1))&1)!=((c>>(hb-1))&1)){
                op3();
            }
            hb--;
            op2();
        }
        op4();
    }
    cout << path.size() << endl;
    for(auto x:path){
        cout << x << ' ';
    }
    cout << endl;
}


int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}