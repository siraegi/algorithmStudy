/*
    BOJ 9663.cpp
    N-Queen - Brute Force Algorithm(recursion), Backtracking
    https://www.acmicpc.net/problem/9663
*/
#include <iostream>
using namespace std;
bool chess[15][15];
int n;
bool check(int r, int c){
    // 수직 위
    for(int i=0;i<r;i++){
        if(chess[i][c]) return false;
    }
    // 왼쪽 위 대각선
    for(int x = r - 1, y = c - 1;x>=0 && y>=0; x--, y--){
        if(chess[x][y]) return false;
    }
    // 오른쪽 위 대각선
    for(int x = r - 1, y = c + 1;x>=0 && y<n; x--, y++){
        if(chess[x][y]) return false;
    }
    return true;
}
int calc(int row) {
    if(row == n){
        return 1;
    }
    int ans = 0;
    for(int col=0;col<n;col++){
        chess[row][col] = true;
        if(check(row,col)){
            ans += calc(row+1);
        }
        chess[row][col] = false;
    }
    return ans;
}
int main(){

    cin >> n;
    cout << calc(0);
    return 0;
}