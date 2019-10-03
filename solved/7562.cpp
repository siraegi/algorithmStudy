#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int visit[301][301];
int dx[8]={1,2,2,1,-1,-2,-2,-1};
int dy[8]={2,1,-1,-2,-2,-1,1,2};
int n; // 체스판 한 변의 길이
int bfs(int i, int j, int a, int b){
    queue <pair<int, int>> q;
    visit[i][j] = 0;
    q.push(make_pair(i,j));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x==a && y==b)
            return visit[a][b];
    
        for(int i=0;i<8;i++){
            int X = x + dx[i];
            int Y = y + dy[i];
            if(X>-1 && X<n && Y>-1 && Y<n){
                if(visit[X][Y]==-1){
                    visit[X][Y]=visit[x][y]+1;
                    q.push(make_pair(X,Y));
                }
            }
        }
    }
    return visit[a][b];
}
int main(){
    int testCase;
    cin >> testCase;
    int ax, ay, bx, by;
    for(int t=0;t<testCase;t++){
        memset(visit, -1, sizeof(visit));
        cin >> n;
        cin >> ax >> ay >> bx >> by;
        cout << bfs(ax, ay, bx, by) << endl;
    }
    return 0;
}