class Solution
{
    int solve(string a, string b, string c, int i, int j, int k, vector<vector<vector<int>>>&dp){
         if(i==0 || j==0 || k==0){
             return 0;
         }
         
         if(dp[i][j][k]!=-1) return dp[i][j][k];
         
         if(a[i-1]==b[j-1] && b[j-1]==c[k-1]){
             return dp[i][j][k]=1+solve(a,b,c,i-1,j-1,k-1,dp);
         }
         return dp[i][j][k]=max({solve(a,b,c,i-1,j,k,dp),solve(a,b,c,i,j-1,k,dp),solve(a,b,c,i,j,k-1,dp)});
         
    }
    public:

        int LCSof3 (string a, string b, string c, int n1, int n2, int n3)
        {
            // your code here
            vector<vector<vector<int>>>dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,-1)));
            int p=solve(a,b,c,n1,n2,n3,dp);
            return p;
        }
};