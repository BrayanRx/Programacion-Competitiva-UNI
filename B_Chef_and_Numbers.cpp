#include <iostream>
using namespace std;

int S(int x){
    int suma = 0;
    while(x>0){
        suma += x%10;
        x/=10;
    }
    return suma;
}

int main(){
    long int N;
    int cant = 0;
    cin >> N;
    if(N>90){
        for(long int i=N-90; i<N; i++){
            if(i + S(i) + S(S(i)) == N) cant++;
        }
    }
    else{
        for(long int i=0; i<N; i++){
            if(i + S(i) + S(S(i)) == N) cant++;
        }
    }
    cout << cant;
    return 0;
}