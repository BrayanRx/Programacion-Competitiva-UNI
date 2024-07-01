#include <iostream>
#include <math.h>
using namespace std;

#define debug(x) cout << #x << "=" << x << endl;

int zxor(int a, int b){
    int c=0, n=0;
    while(a!=0 or b!=0){
        c += pow(2, n)*bool((a%2)*(!(b%2)) or (!(a%2))*(b%2));
        a/=2, b/=2, n++;
    }
    return c;
}

int main(){
    int a = 13, b=2;
    cout << zxor(a,b) << endl;
}