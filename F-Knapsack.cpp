#include <iostream>
using namespace std;

#define debug(x) cout << #x << "=" << x << endl;

int knapsack(short int items[20][2], short int capacidad, short int n) {
    if(n==0 || capacidad==0) return 0;
    if(items[n-1][0] > capacidad){
        return knapsack(items, capacidad, n-1);
    }

    int agregarValor = items[n-1][1] + knapsack(items, capacidad - items[n-1][0], n-1);
    int noAgregar = knapsack(items, capacidad, n-1);

    return max(agregarValor, noAgregar);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    short int N, W;

    cin >> N >> W;
    short int items[N][2];
    for(int i=0; i<N; i++){
        cin >> items[i][0] >> items[i][1];
    }
    cout << knapsack(items, W, N) << endl;
    return 0;
}