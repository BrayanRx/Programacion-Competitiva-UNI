#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int MAXK = 15;

int dp[MAXN][MAXK];

int sol(int valores[], int n, int k){
    if(n==1 && k==0) return valores[n-1];
    
    if(dp[n][k] != -1) return dp[n][k];

    int agregarValor = valores[n-1]^sol(valores, n-1, k-1);
    int noAgregar = sol(valores, n-1, k);

    return dp[n][k] = max(agregarValor, noAgregar);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        int val[MAXN];
        for(int i=0; i<n; i++){
            cin >> val[i];
        }
        
        memset(dp, -1, sizeof(dp));
        
        cout << sol(val, n, k) << endl;
    }
}
