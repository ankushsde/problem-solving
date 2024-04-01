v1 - 
#include <bits/stdc++.h>

using namespace std;

int nCr(int n , int r ){
    long long res = 1;
    
    for(int i = 0; i<r; i++){
        res = res * (n-i);
        res = res / (i+1);
    }
    return res;
}

int pascalTrianngle(int r , int c){
    int element = nCr(c-1,r-1);
    return element;
}

int main(){
    int r = 5;
    int c = 3;
    int element = pascalTrianngle(c,r);
    cout<< element;
    
    return 0;
}
