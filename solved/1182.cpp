//
//  1182.cpp
//  부분수열의 합 brute force
//
//  Created by ShiHaYeon on 24/11/2019.
//  Copyright © 2019 ShiHaYeon. All rights reserved.
//

#include <iostream>
using namespace std;
int N, S;
int cnt=0;
int arr[21];
void goSum(int sum, int i){
    sum +=arr[i];
    if(i<N){
        if(sum==S){
            cnt++;
        }
        goSum(sum, i+1);
        goSum(sum-arr[i], i+1);
    }
}
int main(){
    cin >> N >> S;
    for(int i=0;i<N;i++)
        cin >> arr[i];
    
    goSum(0, 0);
    cout << cnt;
    return 0;
}
