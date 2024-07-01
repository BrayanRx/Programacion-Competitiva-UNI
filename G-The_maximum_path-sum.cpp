#include <iostream>
#define debug(x) cout << #x << "=" << x << endl;
using namespace std;

int f(int A[][10], int n, int m){

    if(n==0 && m==0) return A[0][0];
    if(n==0) return A[n][m] + f(A, 0, m-1);
    if(m==0) return A[n][m] + f(A, n-1, 0);
    
    int izq = A[n][m] + f(A, n, m-1);
    int arr = A[n][m] + f(A, n-1, m);

    return max(izq, arr);
}

int main(){
    int N, M;
    cin >> N >> M;
    int A[10][10];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> A[i][j];
        }
    }
    cout << f(A, N-1, M-1) << endl;
    return 0;
}