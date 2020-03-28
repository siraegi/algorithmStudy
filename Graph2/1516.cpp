/*
    BOJ 1516.cpp
    게임 개발 - Topological Sort
    https://www.acmicpc.net/problem/1516
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int cost[501];
vector<int> g[501];
int ind[501];
queue<int> q;
int time[501]; // 소요시간
int main(){
    int N,n,x;
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> cost[i];
        while(cin >> x && x!=-1){
            g[x].push_back(i);
            ind[i]++;
        }
    }

    // find indegree == 0 (start vertex)
    for(int i=1;i<=N;i++){
        if(ind[i]==0){
            q.push(i);
            time[i] = cost[i];
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
 
        for(int i=0;i<g[node].size();i++){
            int next = g[node][i];
            ind[next]--;

            // 현재 node의 time+다음 next의 cost > 다음 next의 기존 time 이면 time update
            if(time[node]+cost[next]>time[next]){
                //cout << next << " : "<<time[node]<<" + "<< cost[next]<<" = ";
                time[next] = time[node] + cost[next];
                //cout << time[next]<<endl;
            }

            if(ind[next]==0){
                q.push(next);
            }
        }
    }
    for(int i=1;i<=N;i++)
        cout << time[i] << endl;

    return 0;
}