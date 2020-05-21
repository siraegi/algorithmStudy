/*
    BOJ 1697.cpp
    숨바꼭질 - Brute Force Algorithm
    https://www.acmicpc.net/problem/1697
*/
#include <iostream>
#include <queue>
using namespace std;
bool check[100001];
int dist[100001];
int BFS(int N, int K){
    int ans = 0;
    queue<int> q;
    q.push(N);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(now == K){
            ans = dist[now];
            break;
        }  
        if(now-1 >= 0 && !check[now-1]){
            check[now-1] = true;
            q.push(now-1);
            dist[now-1] = dist[now]+1;
        }
        if(now+1 <= 100000 && !check[now+1]){
            check[now+1] = true;
            q.push(now+1);
            dist[now+1] = dist[now]+1;
        }
        if(now*2 <= 100000 && !check[now*2]){
            check[now*2] = true;
            q.push(now*2);
            dist[now*2] = dist[now]+1;
        }
    }
    return ans;
}
int main(){
    int n, k;
    cin >> n >> k;
    cout << BFS(n,k);
    return 0;
}