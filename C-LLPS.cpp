#include <iostream>
#include <string.h>
typedef char Cadena[12];
using namespace std;

void agrega(Cadena cad, char l, int i){
    int n=strlen(cad);
    cad[n+1] = '\0';
    for(int j=n; j>i; j--){
        cad[j] = cad[j-1];
    }
    cad[i]=l;
}
void quita(Cadena cad, int i){
    int n=strlen(cad);
    for(int j=i; j<n-1; j++){
        cad[j] = cad[j+1];
    }
    cad[n-1] = '\0';
}

bool espalindromo(Cadena pal){
    int n = strlen(pal);
    for(int i=0; i<n/2; i++){
        if(pal[i]!=pal[n-i-1]) return false;
    }
    return true;
}

void permutaciones(Cadena combactual, Cadena pal, int n,  Cadena ans){
    if(n==0) return;
    for(int i=0; i<n; i++){
        agrega(combactual, pal[i], strlen(combactual));
        char c = pal[i];
        quita(pal, i);
        if(strcmp(combactual, ans) > 0){
            if(espalindromo(combactual)) strcpy(ans, combactual);
            if(strlen(combactual)<=n || espalindromo(combactual)) permutaciones(combactual, pal, n-1, ans);
        }
        agrega(pal, c, i);
        quita(combactual, strlen(combactual));
    }
}

int main(){
    Cadena pal, ans, in;
    int ix;
    cin >> pal;
    strcpy(ans, "a");
    for(int i=0; i<strlen(pal); i++){
        if(pal[i] > ans[0]){
            ans[0] = pal[i];
            ix = i;
        }
    }
    strcpy(in, ans);
    quita(pal, ix);
    permutaciones(in, pal, strlen(pal), ans);
    cout << ans;
    return 0;
}