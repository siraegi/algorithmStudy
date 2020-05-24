/*
    BOJ 9019.cpp
    DSLR - Brute Force Algorithm
    https://www.acmicpc.net/problem/9019
*/
#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
int dist[10000];
int from[10000];
char how[10000];
int BFS(int A, int B){
    queue<int> q;
    q.push(A);
    dist[A] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        int D = (2*now) % 10000;
        int S;
        now == 0 ? S = 9999 : S = now - 1;
        int L = (now / 1000)+(now % 1000)*10;
        int R = (now / 10)+(now % 10)*1000;
        if(dist[D]==-1){
            dist[D] = dist[now]+1;
            from[D] = now;
            how[D] = 'D';
            q.push(D);
        }
        if(dist[S]==-1){
            dist[S] = dist[now]+1;
            from[S] = now;
            how[S] = 'S';
            q.push(S);
        }
        if(dist[L]==-1){
            dist[L] = dist[now]+1;
            from[L] = now;
            how[L] = 'L';
            q.push(L);
        }
        if(dist[R]==-1){
            dist[R] = dist[now]+1;
            from[R] = now;
            how[R] = 'R';
            q.push(R);
        }
    }
    return dist[B];
}
void solve(int A, int B){
    int n = BFS(A, B); // 명령어 개수
    // 명령어 나열
    int tmp = B;
    string cmd = "";
    for(int i=0;i<n;i++){
        cmd += how[tmp];
        tmp = from[tmp];
    }
    reverse(cmd.begin(), cmd.end());
    cout << cmd <<"\n";
}
int main(){
    int t, a, b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        memset(dist, -1, sizeof(dist));
        memset(from, -1, sizeof(from));
        memset(how, ' ', sizeof(how));
        solve(a, b);
    }
    return 0;
}