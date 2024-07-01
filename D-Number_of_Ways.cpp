#include <bits/stdc++.h>
using namespace std;

void f(int n, int &formas) {
    if(n==0) formas++;
    else{
        for(int i=1; i<=((n<3)? n:3); i++){
            f(n-i, formas);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int s, e, formas=0;
    cin >> s >> e;
    f(e-s, formas);
    cout << formas << endl;
}