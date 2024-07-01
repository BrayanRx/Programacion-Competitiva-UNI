#include <bits/stdc++.h>
using namespace std;

#define ll = long long;
#define ar = array;
#define debug(x) cout << #x << "=" << x << endl;

void hanoi(unsigned short int in, unsigned short int cen, unsigned short int fin, unsigned short int discos) {
    if(discos == 1){
        cout << in << " " << fin << endl;
    }
    else{
        hanoi(in, fin, cen, discos-1);
        cout << in << " " << fin << endl;
        hanoi(cen, in, fin, discos-1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    unsigned short int t;
    cin >> t;
    cout << pow(2,t)-1 << endl;
    hanoi(1,2,3,t);
    return 0;
}