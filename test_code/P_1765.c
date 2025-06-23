#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[220];
int mp1[30]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
int mp2[30]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
int main(){
    // gets(s);
    fgets(s,210,stdin);
    // //……\n
    s[strlen(s)-1]='\0';
    int ans=0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]==' ') printf("0");
        else{
            for(int j=0;j<mp1[s[i]-'a'];j++){
                printf("%d",mp2[s[i]-'a']);
            }
        }
    }
    return 0;
}


