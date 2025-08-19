/**
 * 题意：
 * n*n棋盘，白皇后在(1,1)黑皇后在(1,n)，其余位置是中立棋
 * 皇后可以水平，垂直，斜向吃子，无法吃子的一方输
 * 白先黑后
 * 如果白方能赢，给出第一步往哪走
 * 思路：
 * 如果奇数，无论白棋怎么走，黑棋都对称的走，最后一定会两方之间只剩下1列中立棋，此时该白方走，然后黑方可以直接吃
 * 如果偶数，白方向右走一步就变成黑方先手的奇数情况，白方必胜
 */

 #include<bits/stdc++.h>

 using namespace std;

 int main(){
    int n;
    cin >> n ;
    if(n%2){
        cout << "black" << endl;
    }else{
        cout << "white" << endl;
        cout << "1 2" << endl;
    }
    return 0;
 }