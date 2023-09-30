
#include <bits/stdc++.h>
using namespace std;
class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {    int r=matrix.size();
         int c=matrix[0].size();
        vector<int>a(r,0);
        vector<int>b(c,0);
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==1){
                    a[i]=1;
                    b[j]=1;
                }
            }
        }
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(a[i]==1||b[j]==1){
                    matrix[i][j]=1;
                }
            }
        }
    }
}; 
