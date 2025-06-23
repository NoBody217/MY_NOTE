#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define int long long
typedef struct {
    char name[20];
    int x;
}REN;

REN H[101010],S[101010];

int cmp(const void* a,const void* b){
    REN *aa,*bb;
    aa=(REN*)a;
    bb=(REN*)b;
    return aa->x>bb->x?-1:1;
}
int cnt1,cnt2;
signed main(){
    int n,m;
    scanf("%d%d",&n,&m);
    //读入
    for(int i=0;i<n+m;i++){
        char nm[20],zy;
        int tp;
        scanf(" %s %c %lld",nm,&zy,&tp);
        if(zy=='H'){
            H[cnt1].x=tp;
            strcpy(H[cnt1].name,nm);
            cnt1++;
        }else{
            S[cnt2].x=tp;
            strcpy(S[cnt2].name,nm);
            cnt2++;            
        }
    }
    //处理
    qsort(H,m,sizeof(REN),cmp);
    qsort(S,n,sizeof(REN),cmp);
    printf("%s\n",H[2].name);
    for(int i=5;i<=8;i++){
        printf("%s\n",S[i].name);
    }
    return 0;
}