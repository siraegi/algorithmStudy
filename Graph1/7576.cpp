/*
    BOJ 7576.cpp
    토마토 - BFS
    https://www.acmicpc.net/problem/7576
    dist 배열을 안써도 depth마다 day++ 해주면 됨.(날짜를 기준으로 세기)
    각 토마토가 익는 날이 궁금하면 dist 쓰면 될 듯.
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
int tomato[1001][1001];
int dist[1001][1001];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
void BFS(queue<pair<int,int>> q, int n, int m){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>0 && ny>0 && nx<=n && ny<=m){
                if(tomato[nx][ny]==0 && dist[nx][ny]==-1){
                    q.push(make_pair(nx,ny));
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }
    }
}
int main(){
    int N, M, x;
    cin >> M >> N;
    queue<pair<int,int>> q;
    memset(dist, -1, sizeof(dist));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> x;
            tomato[i][j] = x;
            if(x==1){
                q.push(make_pair(i,j));
                dist[i][j] = 0;
            }
        }
    }
    BFS(q, N, M);
    int day = 0; 
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            //cout << dist[i][j];
            if(tomato[i][j]!=-1 && dist[i][j]==-1){
                cout << "-1";
                return 0;
            }
            if(dist[i][j]>day)
                day = dist[i][j];
        }
        //cout << endl;
    }
    
    cout << day;
    return 0;
}