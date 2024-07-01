#include <bits/stdc++.h>
using namespace std;

#define ll = long long;
#define ar = array;
#define debug(x) cout << #x << "=" << x << endl;



int f91(int t) {
    if(t<=100) return f91(f91(t+11));
    else return t-10; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    
    while(true){
        cin >> t;
        if(t==0) break;
        cout << "f91(" << t << ") = " << f91(t) << endl;
    }
    return 0;
}
