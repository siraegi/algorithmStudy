//  Algorithm
//  1912. 연속합
//  maximum subsequence problem
//  Created by ShiHaYeon on 01/11/2019.
//  Copyright © 2019 ShiHaYeon. All rights reserved.
//

#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n+1];
    int dp[n+1];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    
    dp[0] = arr[0];
    int Max = dp[0];
    for(int i=1;i<n;i++){
        if(dp[i-1]+arr[i]>arr[i])
            dp[i] = dp[i-1] + arr[i];
        else dp[i] = arr[i];
        Max = max(Max,dp[i]);
    }
    cout << Max;
    return 0;
}
