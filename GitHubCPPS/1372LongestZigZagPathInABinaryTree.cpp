
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
    enum TupleID { treenode, zigzag_cc, lr_dir };
    int longestZigZag(TreeNode* root) {
        if (root == nullptr) return 0;
        stack<tuple<TreeNode*, int, char>> tplStack;
        tuple<TreeNode*, int, char> head;
        get<treenode>(head) = root;
        get<zigzag_cc>(head) = 0; //zigzag counter
        get<lr_dir>(head) = 'U'; //'U', 'L', 'R', current node is left or right child of its parent node
        tplStack.push(head);
        int maxZigZagCount = 0;
        while (!tplStack.empty()) {
            tuple<TreeNode*, int, char> tpl = tplStack.top(); tplStack.pop();
            TreeNode* tnptr = get<treenode>(tpl);
            int zzc = get<zigzag_cc>(tpl);
            char lrdir = get<lr_dir>(tpl);
            if (maxZigZagCount < zzc) maxZigZagCount = zzc;
            if (tnptr->right) {
                int r_zzc = zzc;
                if (lrdir == 'L') r_zzc++; else r_zzc = 1;
                tplStack.push(make_tuple(tnptr->right, r_zzc, 'R'));
            }
            if (tnptr->left) {
                if (lrdir == 'R') zzc++; else zzc = 1;
                tplStack.push(make_tuple(tnptr->left, zzc, 'L'));
            }
        }
        return maxZigZagCount;
    }
};