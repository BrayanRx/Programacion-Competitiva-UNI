#include <bits/stdc++.h>
#define debug(x) cout << #x << "=" << x << endl;
using namespace std;

int sol(int valores[], int n, int k){
    if(k==1 && n==1) return valores[n-1];
    if(k==0) return 0;

    int agregarValor = valores[n-1]^sol(valores, n-1, k-1);
    if(n==k) return agregarValor;
    else{
        int noAgregar = sol(valores, n-1, k);
        return max(agregarValor, noAgregar);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        int val[n];
        for(int i=0; i<n; i++){
            cin >> val[i];
        }
        cout << sol(val, n, k) << endl;
    }
}
