#include<bits/stdc++.h>
using namespace std;

int isPrime(int n){
	int i;
	if (n == 1||n == 0)
		return 0;
	for (i = 2; i * i <= n; i++) {
		if(n% i == 0)
			return 0;
	}
	return 1;
}

int main() {
	int n;
	cin>>n;
	if(n==5) {
		cout<<"4 1 3 5 2";
	} else if(n<5) {
		cout<<"-1";
	} else if(n==6) {
		cout<<"7 4 2 5 3 1";
	} else {
		if(n%2==0) {
			int u=n;
			for(int i=1; i<=n; i++) {
				if(i%2==1) {
					if(u-5>=1) {
						u-=5;
					} else {
						u=u-5+n;
					}
				} else {
					if(u+3<=n) {
						u+=3;
					} else {
						u=u+3-n;
					}
				}
                if(u==4) cout << "4 2 ";
				else if(u==2);
                else cout<<u<<" ";
			}
		} else {
            if(!isPrime(n-2)){
                cout << -1 ;
                return 0;
            }
			n=n+1;
			int u=n;
			for(int i=1; i<=n-1; i++) {
				if(i%2==1) {
					if(u-5>=1) {
						u-=5;
					} else {
						u=u-5+n;
					}
				} else {
					if(u+3<=n) {
						u+=3;
					} else {
						u=u+3-n;
					}
				}
                if(u==4) cout << "4 2 ";
				else if(u==2);
                else cout<<u<<" ";
			}
		}
	}
}