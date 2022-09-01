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
    void ser(TreeNode* root, ostringstream& out) {
        if (root) {
            out << root->val << " ";
            ser(root->left, out);
            ser(root->right, out);
        } else {
            out << "# ";
        }
    }
    
    TreeNode* deser(istringstream& in) {
        string t;
        in >> t;
        if (t == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(t));
        root->left = deser(in);
        root->right = deser(in);
        return root;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        ser(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deser(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));