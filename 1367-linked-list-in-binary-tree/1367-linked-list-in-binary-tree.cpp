/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool checkValidity(ListNode* ln, TreeNode* tn) {
        if (ln == nullptr) return true;
        if (tn == nullptr || ln->val != tn->val) return false;
        return checkValidity(ln->next, tn->left) || checkValidity(ln->next, tn->right);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        std::deque<TreeNode*> q;
        q.push_back(root);
        while (q.size() > 0) {
            TreeNode* node = q.front();
            q.pop_front();
            if (node->val == head->val && checkValidity(head, node)) return true;
            if (node->left) q.push_back(node->left);
            if (node->right) q.push_back(node->right);
        }
        return false;
    }
};