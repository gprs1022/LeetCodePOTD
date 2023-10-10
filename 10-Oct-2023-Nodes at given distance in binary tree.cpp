class Solution
{
public:

    vector<int>ans;
    
    void calc(map<Node*, Node*>& mp, Node* root, Node* prev, Node* &dest, int k)
    {
        if(!root) return;
        
        mp[root] = prev;
        if(root->data == k && !dest) dest = root;
        
        calc(mp, root->left, root, dest, k);
        calc(mp, root->right, root, dest, k);
    }
    
    void solve(int k, map<Node*, Node*>& mp, Node* root, Node* prev)
    {
        if(!root) return;
        if(k == 0) 
        {
            ans.push_back(root->data);
            return;
        }
        
        if(root->left != prev) solve(k-1, mp, root->left, root);
        if(root->right != prev) solve(k-1, mp, root->right, root);
        if(mp[root] != prev) solve(k-1, mp, mp[root], root);
    }

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        ans.clear();
        map<Node* , Node*>mp;
        
        Node* dest = NULL;
        calc(mp, root, NULL, dest, target);
        // cout<<dest->data<<endl;
        solve(k, mp, dest, NULL);
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};