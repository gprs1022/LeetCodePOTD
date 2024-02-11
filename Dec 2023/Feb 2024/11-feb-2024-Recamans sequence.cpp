//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
     vector<int> recamanSequence(int n){
        vector<int> res;
        set<int> t;
        res.push_back(0);
        t.insert(0);
        for(int i=1;i<n;i++){
            int cal=res[i-1]-i;
            if(cal>0 && t.find(cal)==t.end()){
            res.push_back(cal);
            t.insert(cal);
            }else {
                cal=res[i-1]+i;
                res.push_back(cal);
                t.insert(cal);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends