/*
    BOJ 2056.cpp
    작업 - Topological Sort
    https://www.acmicpc.net/problem/2056
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int cost[10001];
vector<int> g[10001];
int ind[10001];
queue<int> q;
int time[10001]; // 소요시간
int main(){
    int N,n,x;
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> cost[i] >> n;
        ind[i]=n;
        for(int j=0;j<n;j++){
            cin >> x;
            g[x].push_back(i);
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
    cout << *max_element(time+1, time+N+1);
    return 0;
}