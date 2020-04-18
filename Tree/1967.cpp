/*
    BOJ 1967.cpp
    트리의 지름
    https://www.acmicpc.net/problem/1967
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
long long ans;
int BFS(vector<pair<int, int>> *g, int n, int start){
    bool check[n+1]={false,};
    long long dist[n+1]={0,};
    check[start] = true;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0;i<g[now].size();i++){
            int next = g[now][i].first;
            int cost = g[now][i].second;
            if(!check[next]){
                check[next] = true;
                dist[next] = dist[now] + cost;
                q.push(next);
            }
        }
    }
    int index = distance(dist, max_element(dist, dist+n+1));
    ans = dist[index];
    return index;
}
int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> g[n+1];
    int a, b, c;
    for(int i=1;i<n;i++){
        cin >> a >> b >> c;
        g[a].push_back(make_pair(b,c));
        g[b].push_back(make_pair(a,c));
    }
    int s = BFS(g, n, 1);
    BFS(g, n, s);
    cout << ans;
    return 0;
}