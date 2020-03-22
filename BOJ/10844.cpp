//
//  10844.cpp
//  Dynamic Programming
//
//  Created by ShiHaYeon on 15/11/2019.
//  Copyright © 2019 ShiHaYeon. All rights reserved.
//

#include <iostream>
using namespace std;
long long dp[101][11]; // dp[i][j] = j로 끝나는 i자리 수의 계단수의 개수
int main(){
    int N;
    cin >> N;
    // 0으로 시작하는 계단수는 없으므로 1부터 시작
    for(int i=1;i<10;i++){
        dp[1][i]=1;
    }
    for(int i=2;i<=N;i++){
        // 계단수를 만족하려면 맨끝 숫자 다음에 올 숫자로 0은 1, 9는 8만 가능함. 나머지 1~8은 +1,-1 모두 가능
        // 전역변수로 이차원 배열의 열을 0-10까지 모두 0으로 초기화했기 때문에 0인 경우는 앞에서 처리하고 1-9까지 그냥 돌려도 9는 dp[i][10]=0 이라 상관이 없음. 원래는 조건문을 분기해서 처리해야했지만 메모리를 약간 희생하면 조건문없이 가능!
        dp[i][0] = dp[i-1][1];
        for(int j=1;j<10;j++){
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%1000000000;
        }
    }
    
    long long sum = 0;
    for(int i=0;i<10;i++){
        sum = (sum+dp[N][i])%1000000000;
    }
    cout << sum%1000000000;
    return 0;
}
