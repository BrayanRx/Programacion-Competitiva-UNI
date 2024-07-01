#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define debug(x) cout << #x << "=" << x << endl;

using namespace std;

long long int stringToInt(const string& s) {
    long long int result = 0;
    for (char c : s) {
        result = result * 10 + (c - '0');
    }
    return result;
}

void permutaciones(string actual, int cif, vector<string>& comb){
    if(cif==0){
        comb.push_back(actual);
        return;
    }
    if(cif>1) permutaciones(actual + "1", cif-1, comb);
    permutaciones(actual + "2", cif-1, comb);
}

void solve(int t){
    long long int p, q, min=-1, max=-1;
    bool fst = true;
    vector<string> comb;
    cin >> p >> q;
    permutaciones("", p, comb);

    for(string num : comb){
        long long int x = stringToInt(num);
        if(x%(int(pow(2,q))) == 0){
            if(fst){
                min = x;
                max = x;
                fst = false;
            }
            else{
                if(x<min) min = x;
                if(x>max) max = x;
            }
        } 
    }

    cout << "Case " << t << ": ";
    if(min == -1 or max==-1) cout << "impossible" << endl;
    else if(min == max){
        cout << min << endl;
    }
    else{
        cout << min << " " << max << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, i=1;
    cin >> t;
    while(i<=t){
        solve(i);
        i++;
    }
    return 0;
}
