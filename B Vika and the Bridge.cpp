#include <bits/stdc++.h>
using namespace std;

#define ll = long long;
#define ar = array;
#define debug(x) cout << #x << "=" << x << endl;

void solve() {
    int k, n;
    cin >> k >> n;
    int P[k+1], maxa=k;
    int mx = 0;
    for(int i=0; i<k; i++){
        cin >> P[i];
        if(P[i] > mx) mx = P[i];
    }
    for(int i=1; i<=mx; i++){
        P[k] = i;
        int max1=0, max2=0, z=0, p=0;
        for(int c:P){
            if(z/2 > maxa){
                p=1;
                break;
            }
            if(c==i){    
                if (z>max1) {
                    max2 = max1;
                    max1 = z;
                }
                else if(z>max2){
                    max2=z;
                }
                z=0;
                }
            else z++;
        }
        if(p!=1) maxa = min(max(max1/2, max2), maxa);
    }
    cout << maxa << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--)
        solve();
}