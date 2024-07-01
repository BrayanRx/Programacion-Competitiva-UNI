#include <iostream>
#include <vector>
#include <string>

using namespace std;

void permutaciones(string actual, int cif, vector<string>& comb){
    if(cif==0) return;
    if(!actual.empty()) comb.push_back(actual);
    permutaciones(actual + "4", cif-1, comb);
    permutaciones(actual + "7", cif-1, comb);
}

int main(){
    int n;
    vector<string> a;
    cin >> n;
    permutaciones("", 4, a);

    for(string num : a){
        int luckynumber = stoi(num);
        if(n%luckynumber == 0){
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}