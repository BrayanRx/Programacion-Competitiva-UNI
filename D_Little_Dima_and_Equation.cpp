#include <iostream>
#include <cmath>
#include <vector>
#define debug(x) cout << #x << "=" << x << endl;
using namespace std;

int S(int x){
    int suma = 0;
    while(x>0){
        suma += x%10;
        x/=10;
    }
    return suma;
}

int ncifras(long long int x){
    int cif = 0;
    while(x>0){
        cif += 1;
        x/=10;
    }
    return cif;
}

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int cifmax = 8;
    while(true){
        long long int h = (b*pow(9*cifmax, a) + c);
        int p = ncifras(h);
        if(p < cifmax){
            cifmax = p;
        }
        else break;
    }
    
    long long int h = b*pow(9*cifmax, a) + c;
    if(h>999999999) h=999999999;
    debug(h)
    vector<int> nums;
    for(long long int i=1; i<=h; i++){
        if(i==b*pow(S(i), a) + c){
            nums.push_back(i);
        }
    }    
    
    cout << nums.size() << endl;
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
    return 0;  
}
