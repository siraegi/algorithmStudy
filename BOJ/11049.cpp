#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int mat[501][2];
int dp[501][501];
int minCost(int n)
{
    int Min;
    // 바로 옆 행렬끼리의 곱셈 연산 횟수 구하기
    for (int i = 1; i <= n; i++)
        dp[i][i + 1] = mat[i][0] * mat[i][1] * mat[i + 1][1];

    // k: 곱하고자하는 행렬들의 간격(=행렬 개수-1) 을 늘려가며 모두 진행
    for (int k = 2; k < n; k++)
    {
        int i = 1;
        // 간격 k 의 행렬 i~j 의 범위를 오른쪽으로 한칸씩 늘려가며 모두 진행
        for (int j = i + k; j <= n; j++, i++)
        {
            Min = 0x7fffffff;
            // 행렬 i~j 의 곱의 최소 연산 횟수 구하기, p를 i부터 j-1까지 옮기며 최소연산의 경우를 찾는다.
            for (int p = i; p < j; p++)
            { // dp[i][j]의 최소값 구하는 과정
                Min = min(Min, dp[i][p] + dp[p + 1][j] + mat[i][0] * mat[p][1] * mat[j][1]);
            }
            dp[i][j] = Min;
        }
    }
    return dp[1][n];
}
int main(void)
{
    cin.tie(NULL);
    ios_base ::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> mat[i][0] >> mat[i][1];
    }
    cout << minCost(n);
}