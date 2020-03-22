#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>
using namespace std;
int solution(int A, int B){
    //string a = bitset<32>(A).to_string();
    //string b = bitset<32>(B).to_string();
    bitset<32> a(A);
    bitset<32> b(B);
    bitset<65> c(0);
    
    for(int i=0;i<32;i++){
        if(b[31-i]==1){
            bitset<65> tmp(c.to_ulong()+(a.to_ulong() << i));
            c=tmp;
        }
    }

    return c.count();
}
int main(){
    int A, B;
    cin >> A >> B;
    cout << solution(A, B);
}
