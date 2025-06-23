
const int atMost = 3;
class Trie {
private:
    vector<Trie*> children = vector<Trie*>(26);
    vector<int> indices;
public:
    void Insert(string& word, int wi) {
        Trie* node = this;
        for (char ch : word) {
            int i = ch - 'a';
            if (!node->children[i])
                node->children[i] = new Trie();
            node = node->children[i];
            if (node->indices.size() < atMost)
                node->indices.push_back(wi);
        }
    }
    vector<vector<int>> Search(string& pref) {
        Trie* node = this;
        vector<vector<int>> results(pref.size());
        for (int i = 0; i < pref.size(); ++i) {
            int ndx = pref[i] - 'a';
            if (!node->children[ndx])
                break;
            node = node->children[ndx];
            results[i] = move(node->indices);
        }
        return results;
    }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        Trie* trie = new Trie();
        for (int i = 0; i < products.size(); ++i) {
            trie->Insert(products[i], i);
        }
        vector<vector<string>> suggestions;
        vector<vector<int>> vIndices = trie->Search(searchWord);
        for (auto& indices : vIndices) {
            vector<string> vStr;
            for (int idx : indices) {
                vStr.push_back(products[idx]);
            }
            suggestions.push_back(move(vStr));
        }
        return suggestions;
    }
};