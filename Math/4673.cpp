/*
    BOJ 4673.cpp
    셀프 넘버 - 에라토스테네스의 체
    https://www.acmicpc.net/problem/4673
*/
#include <iostream>
using namespace std;
bool num[10001];
int test(int n){
    int sum = n;
    do{
        sum += (n%10);
    }while(n/=10);
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    for(int i=1;i<10001;i++){
        int ret = test(i);
        if(ret<10001)
            num[ret] = true;
    }
    for(int i=1;i<10001;i++){
        if(!num[i])
            cout << i << "\n";
    }
    return 0;
}