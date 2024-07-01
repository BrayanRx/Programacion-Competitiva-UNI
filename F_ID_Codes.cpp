#include <bits/stdc++.h>
#include <iostream>
#include <string.h>
using namespace std;

#define ll = long long;
#define ar = array;
#define debug(x) cout << #x << "=" << x << endl;
typedef char Cadena[51];

void inserta(Cadena cad, char c, int pos, int ix){
    for(int i=ix; i>pos; i--){
        cad[i] = cad[i-1];
    }
    cad[pos] = c;
}

void solve(Cadena t) {
    
    int n = strlen(t);
    for(int i=n-1; i>0; i--){
        for(int j = i-1; j>=0; j--){
            if(t[j] < t[i]){
                inserta(t, t[i], j, i);
                for(int i2=j+1; i2<n-1; i2++){
                    for(int j2=i2+1; j2<n; j2++){
                        if(t[i2]>t[j2]){
                            char aux = t[i2];
                            t[i2] = t[j2];
                            t[j2] = aux;
                        }
                    }
                }
                cout << t << endl;
                return;
            }
        }
    }
    cout << "No Successor" << endl;
}

int main() {
    Cadena t;
    cin >> t;

    while(strcmp(t, "#") != 0){
        solve(t);
        strcpy(t, "");
        cin >> t;
    }
    return 0;
}

/*
abaacb
ababac
ababca
abacab
abacba
abbaac
abbaca
*/