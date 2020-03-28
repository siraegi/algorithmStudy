/*
    BOJ 1259.cpp
    팰린드롬수
    https://www.acmicpc.net/problem/1259
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int num[100000];
int main(){
    int n;
    while((cin >> n) && n!=0){
        int tmp = n;
        int i=0;
        do {
            num[i] = tmp%10;
            i++;
        } while(tmp/=10);

        bool flag=false;
        int N = i/2;
        i--;
        for(int j=0;j<=N;j++,i--){
            if(num[i]!=num[j]){
                flag = true;
                break;
            }
        }
        if(flag) cout << "no" << endl;
        else cout << "yes" << endl;
    }
    return 0;
}