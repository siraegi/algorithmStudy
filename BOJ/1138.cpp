#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    int h[n+1];
    int x;
    for(int i=1;i<=n;i++){
        cin >> h[i];
    }
    vector<int> o;
    for(int i=n;i>0;i--){
        o.insert(o.begin()+h[i], i);
    }
    for(int i=0;i<n;i++){
        cout << o[i] <<" ";
    }
    return 0;
}