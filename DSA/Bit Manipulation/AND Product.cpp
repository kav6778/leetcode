// https://www.hackerrank.com/challenges/and-product/problem 
#include<iostream>
#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
#define ld long double
using namespace std;

long first_equal_bit(long a, long b){
    int sum =0, ans =0;
    for(int i=0; i<32; i++){ // looping through eeach bit
        int sum =0;
        if((a&(1<<i) && (b&(1<<i)) )== 0){
            ans = i;
            break;
        }
    }return ans;
    
}

void solve(){
    long a,b; cin>>a>>b;
    long ans =0;
    long i = first_equal_bit(a,b); 
    // cout<< i<< endl;
    // from lsb to i every binary element becomes zero after i they remains same as a or b
    for(int j=i; j<32; j++){ // looping from i to msb
        if(a&(1<<j)){
            ans |= (1<<j); // set the bit in answer
        }
    }
    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
}

//     // for(int j=a; j<=b; j++){ // looping through eeach element
    //     // sum += (j&(1<<i));
    //     if(sum == (b-a)) 
    //         ans = i; // set the index to ans
    //     }
