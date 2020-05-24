/*
    BOJ 2178.cpp
    미로찾기 - BFS
    https://www.acmicpc.net/problem/2178
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
bool miro[101][101];
int dist[101][101];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int BFS(int n, int m){
    queue<pair<int,int>> q;
    q.push(make_pair(1,1));
    dist[1][1] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>0 && ny>0 && nx<=n && ny<=m){
                if(miro[nx][ny]&&dist[nx][ny]==0){
                    q.push(make_pair(nx,ny));
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }
    }
    return dist[n][m];
}
int main(){
    int N, M;
    cin >> N >> M;
    char str[M+1]="";
    for(int i=1;i<=N;i++){
        cin >> str;
        for(int j=1;j<=M;j++){
            str[j-1] == '1'? miro[i][j] = true : miro[i][j] = false;
        }
    }
    cout << BFS(N, M);
    return 0;
}