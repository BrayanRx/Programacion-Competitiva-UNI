#include <bits/stdc++.h>
#include <string.h>
using namespace std;

#define debug(x) cout << #x << "=" << x << endl;

char tablero[16][16];
int solus = 0;

bool posible(int n, int x, int y){
    if(tablero[y][x]=='*') return false;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(tablero[i][j] == 'q'){
                if(j==x || i==y || abs(y-i)==abs(x-j)){
                    return false;
                }
            }
        }
    }
    return true;
}

void solu(int n, int q){
    if(q==0){
        solus++;
    } 
    else{
        for(int i=0; i<n; i++){
            if(posible(n, q-1, i)){
                tablero[i][q-1] = 'q';
                solu(n, q-1);
                tablero[i][q-1] = '.';
            }
        }
    }
}

void solve(int t) {
    int n=t;
    char fila[16];
    for(int i=0; i<n; i++){
        cin >> fila;
        strcpy(tablero[i], fila);
    }
    solu(n, n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    int c = 1;
    while(true){
        cin >> t;
        if(t==0) break;
        solve(t);
        cout << "Case " << c << ": " << solus << endl;
        c++;
        solus=0;
    }
    return 0;
}


/*
void presentatablero(int n){
    for(int i=0; i<n; i++){
        cout << tablero[i] << endl;
    }
}
*/