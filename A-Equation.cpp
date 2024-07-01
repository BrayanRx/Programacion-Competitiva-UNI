#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define debug(x) cout << #x << "=" << x << endl;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if(a==0) cout << "-1" << endl;
    else if(pow(b,2)-4*a*c < 0) cout << "0" << endl;
    else if(pow(b,2)-4*a*c == 0){
        cout  << fixed << setprecision(5) << "1" << endl << float(-1*b/(2.0*a)) << endl;
    }
    else{
        cout << fixed << setprecision(5) << "2" << endl << float((-1*b-sqrt(pow(b,2)-4*a*c))/(2.0*a)) << endl << float((-1*b+sqrt(pow(b,2)-4*a*c))/(2.0*a)) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
}
