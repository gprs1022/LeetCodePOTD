//Count Nodes Equal to Average of Subtree
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        dfs(root, count);
        return count;
    }
private:
    pair<int,int> dfs(TreeNode* root, int& count){
        if(!root) return {0,0};

        auto left = dfs(root->left, count);
        auto right = dfs(root->right, count);

        int totalSum = left.first + right.first + root->val;
        int totalCount = left.second + right.second + 1;

        if(totalSum / totalCount == root->val) count ++;

        return {totalSum, totalCount};
    }
};