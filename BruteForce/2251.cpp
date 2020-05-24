/*
    BOJ 2251.cpp
    물통 - Brute Force Algorithm
    https://www.acmicpc.net/problem/2251
*/
#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
struct Water{
    int a, b, c;
};
bool check[201][201];// a, b 가능한 리터 조합
void BFS(set<int>& ans, int A, int B, int C){
    queue<Water> q;
    q.push({0,0,C});
    while(!q.empty()){
        Water w = q.front();
        q.pop();
        if(check[w.a][w.b])
            continue;
        
        check[w.a][w.b] = true;
        
        if(w.a==0){
            ans.insert(w.c);
        }
        // A -> B
        if(w.a+w.b<=B) 
            q.push({0,w.a+w.b,w.c});
        else
            q.push({w.a+w.b-B,B,w.c});
        // A -> C
        if(w.a+w.c<=C) 
            q.push({0,w.b,w.a+w.c});
        else
            q.push({w.a+w.c-C,w.b,C});
        // B -> A
        if(w.a+w.b<=A)
            q.push({w.a+w.b,0,w.c});
        else
            q.push({A,w.a+w.b-A,w.c});
        // B -> C
        if(w.c+w.b<=C)
            q.push({w.a,0,w.b+w.c});
        else
            q.push({w.a,w.c+w.b-B,C});
        // C -> A
        if(w.a+w.c<=A)
            q.push({w.a+w.c,w.b,0});
        else
            q.push({A,w.b,w.a+w.c-A});
        // C -> B
        if(w.c+w.b<=B) 
            q.push({w.a,w.b+w.c,0});
        else
            q.push({w.a,B,w.b+w.c-B});
    }
}
int main(){
    int A, B, C;
    set<int> ans;
    cin >> A >> B >> C;
    BFS(ans, A,B,C);
    
    for(auto iter = ans.begin(); iter != ans.end(); iter++){
        cout << * iter << " ";
    }
    return 0;
}