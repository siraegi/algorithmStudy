/*
    BOJ 10775.cpp
    공항
    https://www.acmicpc.net/problem/10775
    g에 바로 넣는게 가장 많이 넣을 수 있음->뒤에서부터 채워야 최대로 도킹 가능
    차선책을 parent로 갖고 있게 한 후, 차선책이 0이면 도킹 불가
*/
#include <iostream>
using namespace std;
int parent[100001];
int Find(int x){
    if(x == parent[x])
        return x;
    else 
        return parent[x] = Find(parent[x]);
}
void Union(int x, int y){
    int a = Find(x);
    int b = Find(y);
    parent[b] = a;
}
int main(){
    int G, P, p, cnt = 0;
    cin >> G >> P;
    
    for(int i=0;i<=G;i++)
        parent[i] = i;

    bool flag = false;
    for(int i=0;i<P;i++){
        cin >> p;
        if(flag) continue;
        int g = Find(p);
        if(g==0){// 사고나면 어떤 게이트에도 도킹 불가
            flag = true;
        }
        else {
            Union(g-1, g);
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}