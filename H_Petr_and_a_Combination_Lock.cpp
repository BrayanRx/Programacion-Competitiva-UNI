#include <bits/stdc++.h>
using namespace std;

void agrega(int nums[], int &n, int cifra, int i){
    for(int j=n; j>i; j--){
        nums[j] = nums[j-1];
    }
    nums[i]=cifra;
    n++;
}
void quita(int nums[], int &n, int i){
    for(int j=i; j<n-1; j++){
        nums[j] = nums[j+1];
    }
    n--;
}

bool existe(int a[], int x, int n){
    for(int i=0; i<n; i++){
        if (a[i]==x) return true;
    }
    return false;
}

void sumasposibles(int angactual, int ai[], int n, bool &posible, int angulos[], int &n2){
    angactual = angactual%360;
    if(n==0){
        
        if(angactual==0){
            agrega(angulos, n2, angactual, n2);
            posible = true;
            return;
        }
        else{
            if(existe(angulos, angactual, n2)) return;
            else agrega(angulos, n2, angactual, n2);
        }
        
    }
    if(posible) return;

    for(int i=0; i<n; i++){
        int x = ai[i];
        quita(ai, n, i);
        sumasposibles(angactual + x, ai, n, posible, angulos, n2);
        if(!posible) sumasposibles(angactual - x, ai, n, posible, angulos, n2);
        agrega(ai, n, x, i);
    }
}

void solve() {
    int n;
    bool posible = false;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int angulosposibles[360] = {};
    int n2=0;
    sumasposibles(0, a, n, posible, angulosposibles, n2);
    if(posible) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}


