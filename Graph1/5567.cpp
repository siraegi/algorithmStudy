/*
    BOJ 5567.cpp
    결혼식 - Graph
    https://www.acmicpc.net/problem/5567
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> g[501];
bool invited[501];
queue<int> q1;
int main(){
    int n, m;
    cin >> n >> m;
    int x, y;
    for(int i=0;i<m;i++){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    invited[1] = true;
    int cnt = 0;
    for (int i = 0; i < g[1].size(); i++){
        int next = g[1][i];
        invited[next] = true;
        q1.push(next);
        cnt++;
    }
    while(!q1.empty()){
        int now = q1.front();
        q1.pop();
        for (int i = 0; i < g[now].size(); i++){
        int next = g[now][i];
            if(!invited[next]){
                invited[next] = true;
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}