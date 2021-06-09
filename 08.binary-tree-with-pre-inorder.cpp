/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        set<TreeNode*> s;
        stack<TreeNode*> st;
        int n=preorder.size();
        TreeNode* root = NULL;
        for(int pre=0,in=0;pre<n;){
            TreeNode* node=NULL;
            do{
                node = new TreeNode(preorder[pre]);
                if(root ==NULL){
                    root=node;
                }
                if(st.size()>0){
                    if(s.find(st.top())!=s.end()){
                        s.erase(st.top());
                        st.top()->right=node;
                        st.pop();
                    }
                    else{
                        st.top()->left=node;
                    }
                }
                st.push(node);
            }while(preorder[pre++]!=inorder[in] && pre<n);
            node=NULL;
            while(st.size()>0 && in<n && st.top()->val==inorder[in]){
                node=st.top();
                st.pop();
                in++;
            }
            if(node!=NULL){
                s.insert(node);
                st.push(node);
            }
        }
        return root;
    }
};
