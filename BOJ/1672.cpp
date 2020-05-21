/*
    https://www.acmicpc.net/problem/1672
*/
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    char dna[n+1];
    cin >> dna;
    int x, y;
    for(int i=n-1;i>0;i--){
        x = dna[i];
        y = dna[i-1];
        if(x==y)
            continue;
        else if(x=='A'&&y=='G'||x=='G'&&y=='A'){
            dna[i-1] = 'C';
        }
        else if(x=='A'&&y=='C'||x=='C'&&y=='A'){
            dna[i-1] = 'A';
        }
        else if(x=='A'&&y=='T'||x=='T'&&y=='A'){
            dna[i-1] = 'G';
        }
        else if(x=='G'&&y=='C'||x=='C'&&y=='G'){
            dna[i-1] = 'T';
        }
        else if(x=='G'&&y=='T'||x=='T'&&y=='G'){
            dna[i-1] = 'A';
        }
        else if(x=='C'&&y=='T'||x=='T'&&y=='C'){
            dna[i-1] = 'G';
        }
    }
    cout << dna[0];
    return 0;
}