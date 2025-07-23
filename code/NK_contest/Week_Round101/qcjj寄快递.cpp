#include<bits/stdc++.h>
#define pdd pair<double,double>
using namespace std;


pdd a[101010];
double dis2[101010];
double t[101010];
double cal(int x,int y){
    return fabs((a[x].first-a[y].first)*(a[x].first-a[y].first)+(a[x].second-a[y].second)*(a[x].second-a[y].second));
}
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i].first >> a[i].second;   
        if(i>=2){
            dis2[i]=cal(i,i-1);
            t[i]=2*max(0.0,(log2(log(2)*sqrt(dis2[i]))))+2*sqrt(dis2[i])/pow(2,max(0.0,(log2(log(2)*sqrt(dis2[i])))));
        }
    }
    double ans=0;
    for(int i=2;i<=n;i++){ans+=t[i];}
    printf("%.18lf",ans);

    return 0;
}