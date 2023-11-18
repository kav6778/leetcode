#include<bits/stdc++.h>
using namespace std;

const int N = 10;

void getCofactor(int mat[N][N], int temp[N][N], int p, int q, int n){
    int i=0, j=0;
    for(int row = 0; row<n; row++){
        for(int col = 0; col<n; col++){
            // copying into temp matirx 
            // only those elements which are not
            // in the given row and col
            if(row != p && col!= q){
                temp[i][j++] = mat[row][col];
                // Row is filled , so increase row
                // index and reset col index
                if(j == n-1){
                    j =0;
                    i++;
                }
            }
        }
    }
}


//recursive function for finding determinant of matrix
// n is current dimension of mat[][]
int determinantOfMatrix(int mat[N][N], int n){
    //base case: when the dimension of the matrix is 1
    if(n == 1) return mat[0][0];
    //initialize result 
    int D = 0;
    //to store cofactor
    int temp[N][N];
    //To store sign multiplier
    int sign =1;

    //iterate through the row
    for(int f =0; f<n; f++){
        //getting cofactor of mat[0][f]
        getCofactor(mat, temp, 0,f,n);
        D += sign * mat[0][f] * determinantOfMatrix(temp,n-1);
        sign *= -1;
    }
    return D;
}

void solve(){
    int n; cin>>n; //dimension of the matrix
    int mat[N][N];
    for(int row = 0; row<n; row++){
        for(int col = 0; col<n; col++){
            cin>>mat[row][col];
        }
    }
    cout<<determinantOfMatrix(mat,n)<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}
