/*
    BOJ 9372.cpp
    상근이의 여행 - MST(Prim's Algorithm)
    https://www.acmicpc.net/problem/9372
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> edge; // (next node, weight)
int Prim(vector<int> *g, int n, int start){
    bool visit[n+1] = {false,};
    queue<int> q;
    q.push(start);
    visit[start] = true;
    int cnt = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0;i<g[now].size();i++){
            if(!visit[g[now][i]]){
                cnt++; 
                visit[g[now][i]] = true;
                q.push(g[now][i]);
            }
        }
    }
    return cnt;
}
int main(){
    int T, N, M;
    cin >> T;
    for(int t=0;t<T;t++){
        cin >> N >> M;
        vector<int> g[N+1];
        for(int i=0;i<M;i++){
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        cout << Prim(g, N, 1)<<endl;
        for(int i=1;i<=N;i++){
            g[i].clear();
        }
    }
    return 0;
}