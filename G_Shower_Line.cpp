#include <iostream>
#include <string>
#include <vector>
using namespace std;

int happiness(int orden, int g[][5]){
    int i1=orden%10-1;
    orden /= 10;
    int i2=orden%10-1;
    orden /= 10;
    int i3=orden%10-1;
    orden /= 10;
    int i4=orden%10-1;
    orden /= 10;
    int i5=orden%10-1;
    orden /= 10;
    
    return g[i1][i2]+g[i2][i1] + g[i3][i4]+g[i4][i3] + g[i2][i3]+g[i3][i2] + g[i4][i5]+g[i5][i4] + g[i3][i4]+g[i4][i3] + g[i5][i4]+g[i4][i5];
}

void permutaciones(string actual, int cif, vector<int> numeros, vector<int> &comb){

    if(cif==0){
        int x = stoi(actual);
        comb.push_back(x);
        return;
    }
    

    for(int i=0; i<numeros.size(); i++){
        int c = numeros[i];
        numeros.erase(next(numeros.begin(), i)); //eliminar de numeros el elemento de indice i
        permutaciones(actual + to_string(c), cif-1, numeros, comb);
        numeros.insert(numeros.begin() + i, c); //insertar en numeros el elemento c en la pos i
    }
    
}

int main(){
    int matrizH[5][5];
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> matrizH[i][j];
        }
    }

    vector<int> permposibles, numeros = {1,2,3,4,5};
    permutaciones("", 5, numeros, permposibles);
    
    int maxhap = 0, comb;
    for(int i=0; i<permposibles.size(); i++){
        int x = happiness(permposibles[i], matrizH);
        if(x > maxhap){
            comb = permposibles[i];
            maxhap=x;
        }
    }
    cout << maxhap << endl;
    return 0;
}