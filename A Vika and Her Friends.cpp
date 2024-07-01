#include <bits/stdc++.h>
using namespace std;

#define ll = long long;
#define ar = array;
#define debug(x) cout << #x << "=" << x << endl;


void solve() { //no puede escapar si la diferencia de coordenadas con alguno es multiplo de 2
    int n, m, k, i, j, a, b;
    int p=0;
    cin >> n >> m >> k;
    cin >> a >> b;
    while(k--){
        cin >> i >> j;
        if((abs(a-i)+abs(b-j))%2 == 0){
            p++;
        }
    }
    if (p==0) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}