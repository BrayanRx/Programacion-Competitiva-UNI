#include <iostream>
using namespace std;

typedef char dungeon[101];

int main(){
    int n;
    dungeon DUN;
    cin >> n >> DUN;
    int anc = n/4;
    bool ans = false;
    for(int salto=1; salto<=anc; salto++){
        for(int jx=0; jx<salto; jx++){
            if(jx+4*salto >= n) break;
            int k=0;
            int j=jx;
            while(j<n){
                if(DUN[j]=='*') k++;
                else k=0;
                if(k==5){
                    ans = true;
                    break;
                }
                j+=salto;
                
            }
            if(ans) break;
        }
        if(ans) break;
    }
    if(ans) cout << "yes"; 
    else cout << "no";
}

// .* ** ** ** *

//15
// *** *** *** *** ***
// *** *** *** *** ***

// 16
// .** .*. .*. *** .** .
// .**. *..* .*** .**.

// 11
// .* .* .. .* .* .

// 14
// *** *** **. *.. **

// 19
// .** .*. .*. *** .** .*. *
// .**. *..* .*** .**. *.*