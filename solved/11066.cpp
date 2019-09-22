#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
//dp[i][j] = i~j까지 최소 비용
/*
40 30 30 50
70 80
150
sum 70(30 + 40) + 80(30 + 50) + 150(70 + 80)
dp[1][4] = 300 = dp[1][2](70 = mat[1] + mat[2]) + dp[3][4](80 = mat[3] + mat[4]) + mat[1] + mat[2] + mat[3] + mat[4]

1~n의 최솟값은
dp[1][n] = 1~k의 최솟값 + (k+1)~n의 최솟값
sum += dp[][]
*/

int chapter[501];
int dp[501][501];
int sum[501][501];

int minCost(int n) {   //dp를 계산하는 함수, n: 소설의 총 장 수
    int Min;   
    // 바로 옆 장끼리 합하는 비용
    for (int i = 1; i < n; i++)
        dp[i][i + 1] = chapter[i] + chapter[i + 1];
    // k: 더하고자하는 장들의 간격(=장 개수-1) 을 늘려가며 모두 진행
    for (int k = 2; k < n; k++)
    {
        int i = 1;
        // 간격 k 의 행렬 i~j 의 범위를 오른쪽으로 한칸씩 늘려가며 모두 진행 dp구하기
        for (int j = i + k; j <= n; j++, i++)
        {
            Min = 0x7fffffff;
            // 행렬 i~j 의 곱의 최소 연산 횟수 구하기, p를 i부터 j-1까지 옮기며 최소연산의 경우를 찾는다.
            for (int p = i; p < j; p++)
            { 
                Min = min(Min, dp[i][p]+dp[p+1][j]);
            }
            dp[i][j] = Min + sum[i][j];
        }
    }
    return dp[1][n];
}

int main() {
    cin.tie(NULL);
    ios_base ::sync_with_stdio(false);
    int testCase, n;
    cin >> testCase;
    for(int t=0;t<testCase;t++){
        cin >> n;
        int data;
        //memset(sum, 0, sizeof(sum));
        for(int i=1;i<=n;i++){
            cin >> data;
            chapter[i] = data;
            sum[1][i] = sum[1][i-1] + data;
        }
        for(int i=2;i<=n;i++){
            for(int j=i;j<=n;j++){
                sum[i][j] = sum[i][j-1] + chapter[j];
            }
        }
        cout << minCost(n)<<endl;
    }
    return 0;
}