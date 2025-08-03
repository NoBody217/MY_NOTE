#include<bits/stdc++.h>
using namespace std;

int matrix[220][220];
vector<int> ele;
int deal(int x){
    ele.push_back(x);
    x/=2;
    int flg=1;
    while(x){
        if(ele.back()<0&&2*x+ele.back()<0) x++;
        ele.push_back(x*(flg?-1:1));
        ele.push_back(x*(flg?-1:1));
        x/=2;
        flg=1-flg;
    }
    if(flg==0) ele.push_back(1);
    return ele.size();
}

int main(){
    int n;
    cin >> n;
    int siz=deal(n);
    cout << siz << endl;
    for(int i=siz;i>=1;i--){
        matrix[i][siz]=ele[siz-i];
        if(i!=siz) matrix[i][i]=1;
    }

    if(siz%2){
        for(int i=siz;i>=3;i--){
            int lid=(i+1)/2*2;
            for(int j=1;j<=siz;j++){
                matrix[i][j]+=matrix[lid-2][j]+matrix[lid-3][j];
            }
        }
    }else{
        for(int i=siz;i>=4;i--){
            if(i%2==0){
                for(int j=1;j<=siz;j++){
                    matrix[i][j]+=matrix[i-1][j]+matrix[i-2][j];
                }                
            }else{
                for(int j=1;j<=siz;j++){
                    matrix[i][j]+=matrix[i-2][j]+matrix[i-3][j];
                }                
            }
        }
        for(int i=1;i<=siz;i++){
            matrix[2][i]+=matrix[1][i];
            matrix[3][i]+=matrix[1][i];
        }         
    }



    for(int i=1;i<=siz;i++){
        for(int j=1;j<=siz;j++){
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}