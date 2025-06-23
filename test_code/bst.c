#include<stdio.h>
#include<string.h>
#include<math.h>

int BST[202020];

void insert(int x,int pos){
	if(BST[pos]==-1) BST[pos]=x;
	else{
		if(x<BST[pos]) insert(x,pos*2);
		else if(x>BST[pos]) insert(x,pos*2+1);
	}
}
int main(){
    int n;
    memset(BST,-1,202020);
    scanf("%d",&n);
    printf("%d",n);
    for(int i=1;i<=n;i++){
        int tp;
        scanf("%d",&tp);
        insert(tp,1);
    }
    for(int i=1;i<=n;i++){
        if(BST[2*i]==-1&&BST[2*i+1]==-1){
            printf("%d\n",BST[i]);
        }
    }
    return 0;
}