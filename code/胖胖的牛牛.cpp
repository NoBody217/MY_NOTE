#include<bits/stdc++.h>
using namespace std;
//太痛了，01bfs用vis可能会劣势路抢占优势路
char mp[120][120];
int dis[120][120][4];
int mv[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

struct ty{
    int x, y, dir, dis;
    bool operator < (const ty &a) const {
        return dis > a.dis;
    }
};

int main(){
    int n, sx, sy, ex, ey;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> mp[i][j];
            if(mp[i][j] == 'A') sx = i, sy = j;
            if(mp[i][j] == 'B') ex = i, ey = j;
        }
    }
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<ty> q;

    for(int i = 0; i < 4; i++){
        dis[sx][sy][i] = 0;
        q.push({sx, sy, i, 0});
    }

    while(!q.empty()){
        ty tmp = q.top(); q.pop();
        if(tmp.dis > dis[tmp.x][tmp.y][tmp.dir]) continue;

        for(int i = 0; i < 4; i++){
            int tx = tmp.x + mv[i][0];
            int ty = tmp.y + mv[i][1];
            if(tx<1||tx>n||ty<1||ty>n||mp[tx][ty]=='x') continue;
            int nd = tmp.dis + (i != tmp.dir);
            if(dis[tx][ty][i] > nd){
                dis[tx][ty][i] = nd;
                q.push({tx, ty, i, nd});
            }
        }
    }
    int ans = INT_MAX;
    for(int i = 0; i < 4; i++) ans = min(ans, dis[ex][ey][i]);
    cout << (ans == 0x3f3f3f3f ? -1 : ans) << endl;
    return 0;
}
