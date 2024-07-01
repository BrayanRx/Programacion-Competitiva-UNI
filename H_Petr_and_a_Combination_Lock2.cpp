#include <iostream>
#include <vector>
using namespace std;

bool clockWise(const vector<int>& V) {
    int n = V.size();
    int total = 1<<n;

    for (int mask = 0; mask < total; mask++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int p = ((mask & (1 << i)) == 0) ? 1 : -1; //todos los subconjuntos de sumas con V y el resto con resta
            sum += p*V[i];
        }
        if (sum%360 == 0) {
            return true;
        }
    }
    
    return false;
}

int main() {
    int n, p;
    cin >> n;
    vector<int> arr = {};
    for(int i=0; i<n; i++){
        cin >> p;
        arr.push_back(p);   
    }

    if (clockWise(arr)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}