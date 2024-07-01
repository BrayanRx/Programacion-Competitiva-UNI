#include <iostream>
#include <cmath>
#include <vector>
#define debug(x) cout << #x << "=" << x << endl;
using namespace std;

int S(long long int x){
    int suma = 0;
    while(x>0){
        suma += x%10;
        x/=10;
    }
    return suma;
}

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    vector<long long int> nums;
    for(int i=1; i<=81; i++){
        long long int k = b*pow(i, a) + c;
        if(k > 999999999) break;
        if(S(k) == i){
            nums.push_back(k);
        }
    }    
    
    cout << nums.size() << endl;
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
    return 0;
}
