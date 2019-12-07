//
//  9251.cpp
//  LCS (Dynamic Programming)
//
//  Created by ShiHaYeon on 07/12/2019.
//  Copyright © 2019 ShiHaYeon. All rights reserved.
//

#include <iostream>
using namespace std;
string A;
string B;
int main(){
    cin >> A >> B;
    int m = A.length();
    int n = B.length();
    int c[m+1][n+1];
    
    for(int i=0;i<=m;i++)
        c[i][0] = 0;
    
    for(int i=0;i<=n;i++)
        c[0][i] = 0;
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(A[i-1]==B[j-1])
                c[i][j] = c[i-1][j-1]+1;
            
            else if(c[i-1][j]>=c[i][j-1])
                c[i][j] = c[i-1][j];
            
            else
                c[i][j] = c[i][j-1];
        }
    }
    
    cout << c[m][n];
    return 0;
}
