/* Description

Given a string S, find the longest string T such that:
→ T is the prefix of S.
→ T is the suffix of S.
→ T is present in the middle of S, such that T is not a prefix and suffix.

Suppose S = “aaaa”, then T = “aa”.
aa is a prefix, S[0..1].
aa is a suffix S[2..3].
aa is present in the middle and it is not a prefix or suffix, S[1..2].

If no T exists then print -1.

 


Input Format

The first line contains an integer T, ( 1 ≤ T ≤ 10000) - the number of test cases.

The first line of each test case contains an integer N, ( 2 ≤ N ≤ 100000).

The second line contains a string S of length N.

Sum of N across all test cases ≤ 10^6.


Output Format

For each test case print the string T, if no string T exists print -1.


Sample Input 1

3
9
abababaab
6
ffffff
5
abcde

Sample Output 1

ab
ffff
-1 */
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int kmp[1000005];

void prefix(string s){
    int n= s.length();
    kmp[0]=0;
    
    for(int i=1; i<n; i++){
       j = kmp[i-1];
       while(j>0 && s[i] != s[j]) j = kmp[j-1];
       if(s[i] == s[j]) j++;
       
       kmp[i] = j;   
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--) {
        int n; cin>>n;
        string s; cin>>s;
        prefix(s);
        if(kmp[n-1] == 0){
            cout<<"-1"<<endl;
            continue;
        }
        bool f =0;
        for(int i = n-2; i>=1; i--){
            if(kmp[i] == kmp[n-1]){
                cout<<s.substr(0,kmp[n-1])<<endl;
                f = 1;
                break;
            }
        }
        if(f) continue;
        if(kmp[kmp[n-1]-1] == 0){
            cout << "-1" <<endl;
        }
        else{
            cout<<s.substr(0,kmp[kmp[n-1]-1]) <<endl;
        }
    }
}
