/*
    BOJ 6118.cpp
    숨바꼭질 - Dijkstra's Algorithm
    https://www.acmicpc.net/problem/6118
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> g[N+1];
    bool check[N+1];
    int dist[N+1];
    fill(dist, dist+N+1, 0x7FFFFFFF);
    fill(check, check+N+1, false);
    for(int i=0;i<M;i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(check[now]) continue;
        check[now] = true;
        //cout << "["<< now << " : ";
        for(int i=0;i<g[now].size();i++){
            int next = g[now][i];
            //cout << next<< " ";
            if(dist[next] > dist[now]+1){
                //cout << "* ";
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }
    int index = 0;
    int maxDist = 0;
    int cnt = 1;
    for(int i=1;i<=N;i++){
        //cout << dist[i] << " ";
        if(maxDist < dist[i]){
            cnt = 1;
            maxDist = dist[i];
            index = i;
        }
        else if(maxDist == dist[i]){
            cnt++;
        }
    }
    cout << index << " " << maxDist << " " << cnt;
    
    return 0;
}