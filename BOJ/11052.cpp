/*
    11052. 카드 구매하기
    Dynamic Programming
*/

#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    int* p = new int[n+1];
    int* dp = new int[n+1];
    
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        dp[i] = p[i] = x;
    }
    dp[0] = 0;

    for(int i=2;i<=n;i++){
        for(int j=1;j<=i/2;j++){
            dp[i] = max(dp[i], dp[i-j] + dp[j]);
        }
    }

    cout << dp[n];
    return 0;
}