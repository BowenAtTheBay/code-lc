TreeNode* deserialize(string data) {
        if (data == "/")
            return nullptr;
        stringstream s(data);
        return helper_deserialize(s);
    }
    
private:
    TreeNode* helper_deserialize(stringstream& s) {
        string str;
        getline(s, str, ',');
        if (str == "/")
            return nullptr;
        else {
            TreeNode* node = new TreeNode(stoi(str));
            node->left = helper_deserialize(s);
            node->right = helper_deserialize(s);
            return node;
        }
    }
};
​
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
​
//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/discuss/74252/Clean-C%2B%2B-solution
​