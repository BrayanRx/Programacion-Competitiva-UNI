#include <iostream>
using namespace std;

int A[][9] = {
    {-1,-1,-1,-1, 6,-1,-1, 2,-1},
    {-1, 8,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1, 9,-1,-1,-1,-1,-1,-1},
    {-1, 7,-1,-1,-1,-1, 9,-1, 8},
    {5,-1,-1,-1, 3,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1, 4,-1,-1},
    {-1,-1, 4, 8,-1, 9,-1,-1,-1},
    { 3,-1,-1, 7,-1,-1, 6,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1, 5,-1},
};

bool posible(int A[][9], int n, int y, int x){
    for(int i=0; i<9; i++){
        if(A[y][i]==n) return false;
        if(A[i][x]==n) return false;
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(A[3*(y/3)+i][3*(x/3)+j] == n) return false;
        }
    }
    return true;
}

void leermatriz(int A[][9]){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << "["<< i+1 << "][" << j+1 << "]: "; cin >> A[i][j];
            if(A[i][j]==0) A[i][j] = -1;
        }
    }
}

void impmatriz(int A[][9]){
    for(int i=0; i<9; i++){
        for(int j:A[i]){
            cout << j << " ";
        }
        cout << endl;
    }
}
void solucion(int A[][9], int i=0, int j=0){
    if(A[i][j]!=-1){
        if(i==8 and j==8){
            impmatriz(A);
        }
        if(j==8) return solucion(A, i+1, 0);
        return solucion(A, i, j+1);
    }
    for(int ix=1; ix<=9; ix++){
        if(posible(A, ix, i, j)){
            A[i][j] = ix;
            solucion(A, i, j);
            A[i][j] = -1;
        }
    }

}

int main(){
    int p = 0;
    cout << "Leer matriz? (1/0)\n > "; cin >> p;
    if(p) leermatriz(A);
    solucion(A);
    return 0;
}