#include <iostream>
#include <string.h>
using namespace std;
typedef char Cadena[100];
int main(){
    Cadena p;
    cin >> p;
    int min=0, may=0; 
    for(int i=0; i<strlen(p); i++){
        int c = p[i];
        if (int('a') <= c) min++;
        else may++;
    }
    if(may>min) cout << strupr(p);
    else cout << strlwr(p);
}