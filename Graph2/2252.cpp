/*
    BOJ 2252.cpp
    줄 세우기 - Topological Sort
    https://www.acmicpc.net/problem/2252
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> g[32001];
int ind[32001];
queue<int> q;
int main(){
    int N, M;
    cin >> N >> M;
    int x, y;
    for(int i=0;i<M;i++){
        cin >> x >> y;
        // x -> y
        g[x].push_back(y);
        ind[y]++;
    }
    // find indegree == 0 (start vertex)
    for(int i=1;i<=N;i++){
        if(ind[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        cout << node << " ";
        q.pop();
        for(int i=0;i<g[node].size();i++){
            int next = g[node][i];
            ind[next]--;
            if(ind[next]==0){
                q.push(next);
            }
        }
    }
    cout << endl;
    return 0;
}