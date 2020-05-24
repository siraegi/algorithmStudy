/*
    BOJ 1525.cpp
    퍼즐 - Brute Force Algorithm
    https://www.acmicpc.net/problem/1525
*/
#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int BFS(int start){
    queue<int> q;
    q.push(start);
    map<int, int> d;
    d[start] = 0;
    int ans = -1;
    while(!q.empty()){
        int now_num = q.front();
        if(now_num==123456789) {
            ans = d[now_num];
            break;
        }
        string now_str = to_string(now_num);
        q.pop();
        int z = now_str.find('9');
        int x = z/3; // row
        int y = z%3; // col
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx<3 && ny>=0 && ny<3){
                string next_str = now_str;
                swap(next_str[3*x+y], next_str[3*nx+ny]);
                int next_num = stoi(next_str);
                if(d.count(next_num)==0){
                    d[next_num] = d[now_num] + 1;
                    q.push(next_num);
                }
            }
        }
    }
    return ans;
}
int main(){
    int num = 0;
    int x;
    for(int i=0;i<9;i++){
        cin >> x;
        if(x == 0) x = 9;
        num *= 10;
        num += x;
    }
    cout << BFS(num);
    return 0;
}