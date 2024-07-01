#include <bits/stdc++.h>

using namespace std;

#define ll = long long;
#define ar = array;
#define debug(x) cout << #x << "=" << x << endl;

int zxor(int a, int b){
    int c=0, n=0;
    while(a!=0 or b!=0){
        c += pow(2, n)*bool((a%2)*(!(b%2)) or (!(a%2))*(b%2));
        a/=2, b/=2, n++;
    }
    return c;
}

int n, k;

void solve() {
    cin >> n;
    int A[n];
    int c=0, zx=0;
    for(int i=0; i<n; i++){
        cin >> A[i];
        if(A[i]!=0) zx=1;
    }
    while(zx){
        c++;
        zx=0;
        int f = A[0];
        for(int i=0; i<n-1; i++){
            A[i] = zxor(A[i],A[i+1]);
            if(A[i]!=0) zx=1;
        }
        A[n-1] = zxor(A[n-1], f);
        if(A[n-1]!=0) zx=1;
    }
    cout << c << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}