#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string num;
        cin >> num;
        int f = 0;
        int b = 0;
        f += (double)(num[0]-'A')*pow(26, 2);
        f += (double)(num[1]-'A')*pow(26, 1);
        f += (double)(num[2]-'A');
        b += (num[4]-'0')*1000;
        b += (num[5]-'0')*100;
        b += (num[6]-'0')*10;
        b += (num[7]-'0');

        if(abs(f - b)<=100.0)
            cout << "nice\n";
        else
            cout << "not nice\n";
    }
    return 0;
}