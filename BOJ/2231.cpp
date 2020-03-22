//
//  2231.cpp
//  분해합, brute force
//
//  Created by ShiHaYeon on 24/11/2019.
//  Copyright © 2019 ShiHaYeon. All rights reserved.
//

#include <iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    int tmp = N;
    int digit = 1;
    while(tmp/=10){
        digit++;
    }
    int start = N - 9 * digit;
    int ans=0;
    for(int i=start;i<N;i++){
        int tmp = i;
        int sum = i;
        do {
            sum += (tmp%10);
        }while(tmp/=10);
        if(sum==N){
            ans = i;
            break;
        }
    }
    cout << ans;
    return 0;
}
