//
//  2309.cpp
//  brute force
//
//  Created by ShiHaYeon on 24/11/2019.
//  Copyright © 2019 ShiHaYeon. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int h[9];
    vector<int> ans;
    int sum=0;
  
    for(int i=0;i<9;i++){
        cin >> h[i];
        sum +=h[i];
    }
    bool flag = false;
    for(int i=0;i<9;i++){
        for(int j=i+1;j<9;j++){
            int s = sum - (h[i]+h[j]);
            if(s==100){
                h[i] = -1;
                h[j] = -1;
                flag = true;
                break;
            }
        }
        if(flag) break;
    }

    sort(h,h+9);
    for(int i=2;i<9;i++){
        cout << h[i] << endl;
    }
    return 0;
}
