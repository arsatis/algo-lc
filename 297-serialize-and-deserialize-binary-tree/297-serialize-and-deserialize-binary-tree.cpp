/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    string data;
public:
    Codec() {
        ios_base::sync_with_stdio(0);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "x";
        stringstream ss;
        ss << root->val << "," << serialize(root->left) << "," << serialize(root->right);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        this->data = data;
        if (data[0] == 'x') return nullptr;
        TreeNode* node = new TreeNode(stoi(this->data.substr(0, this->data.find(","))));
        node->left = deserialize(this->data.erase(0, this->data.find(",") + 1));
        node->right = deserialize(this->data.erase(0, this->data.find(",") + 1));
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));