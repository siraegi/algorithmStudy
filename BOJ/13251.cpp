#include <iostream>
#include <vector>
using namespace std;
int main(){
    int m, k;
    int num[m+1];
    int sum = 0;
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> num[i];
        sum += num[i];
    }
    cin >> k;
    double total = 0;
    for(int i=0;i<m;i++){
        double p = 1;
        for(int j=0;j<k;j++){
            p *= ((double)(num[i]-j)/(double)(sum-j));
        }
        total += p;
    }
    printf("%.15lf",total);
    return 0;
}