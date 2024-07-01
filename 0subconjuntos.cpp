#include <iostream>
#include <vector>

using namespace std;

void exploreSubsets(vector<int>& arr) {
    int n = arr.size();
    
    for (int mask = 0; mask < (1 << n); mask++) { 
        cout << mask << endl;
        vector<int> subset;
        for (int i = 0; i < n; ++i) {
            cout << i << endl;
            if (mask & (1 << i)) {
                cout << "if" << endl;
                cout << i << endl;
                subset.push_back(arr[i]);
            }
        }
        
        // Eliminar el subconjunto actual
        
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    exploreSubsets(arr);
    
    return 0;
}
