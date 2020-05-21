/*
    BOJ 1963.cpp
    소수 경로 - Brute Force Algorithm
    https://www.acmicpc.net/problem/1963
*/
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
bool Nprime[10000];
bool check[10000];
int dist[10000];
int change(int num, int digit, int x){
    if(digit == 0 && x == 0) return -1; // 1000 미만이면 비밀번호 아님
    string s = to_string(num);
    s[digit] = '0'+x;
    return stoi(s);
}
void BFS(int A, int B){
    queue<int> q;
    q.push(A);
    check[A] = true;
    dist[A] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0;i<4;i++){ // 0123
            for(int j=0;j<=9;j++){
                int next = change(now, i, j);
                if(next != -1){
                    if(!Nprime[next] && !check[next]){
                        q.push(next);
                        check[next] = true;
                        dist[next] = dist[now]+1;
                    }
                }
            }
        }
    }
    if(dist[B]!= -1){
        cout << dist[B] <<"\n";
    } else {
        cout << "Impossible\n";
    }
}
int main(){
    int t,a,b;
    for(int i=2;i<10000;i++){
        if(!Nprime[i]){
            for(int j=i*i;j<10000;j+=i){
                Nprime[j] = true;
            }
        }
    }
    cin >> t;
    while(t--){
        cin >> a >> b;
        memset(check, false, sizeof(check));
        memset(dist, -1, sizeof(dist));
        BFS(a, b);
    }
    return 0;
}