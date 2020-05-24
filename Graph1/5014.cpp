/*
    BOJ 5014.cpp
    스타트링크 - BFS
    https://www.acmicpc.net/problem/5014
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
int dist[1000001];
int F, S, G, U, D;
void BFS(){
    queue<int> q;
    q.push(S);
    dist[S] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(now-D>0){
            if(dist[now-D]==-1 || dist[now] + 1 < dist[now-D]){
                dist[now-D] = dist[now] + 1;
                q.push(now-D);
            }
        }
        if(now+U<=F){
            if(dist[now+U]==-1 || dist[now] + 1 < dist[now+U]){
                dist[now+U] = dist[now] + 1;
                q.push(now+U);
            }
        }
    }
    if(dist[G]==-1)
        cout << "use the stairs";
    else cout << dist[G];
}
int main(){
    memset(dist, -1, sizeof(dist));
    cin >> F >> S >> G >> U >> D;
    BFS();
    return 0;
}