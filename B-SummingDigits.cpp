#include <bits/stdc++.h>
using namespace std;

#define ll = long long;
#define ar = array;
#define debug(x) cout << #x << "=" << x << endl;



int f(int p) {
    int x = 0;
    for(int h=p; h!=0; h/=10){
        x += h%10;
    }
    if(x<10) return x;
    else return f(x);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t!=0){
        cout << f(t) << endl;
        cin >> t;
    }
}