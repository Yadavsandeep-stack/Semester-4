//Q.1 : Design and implement a program to perform  for a given set of characters along with their respective      frequencies. The objective is to generate optimal  such that the total cost of encoding (i.e.,            weighted path length) is minimized. The program should construct a  using a greedy approach by            repeatedly combining the two least frequent nodes until a single tree is formed. Based on the             constructed tree, assign binary codes to each character, where no code is a prefix of another.

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class tree {
public:
    char c;
    int fre;
    tree* left;
    tree* right;

    tree(char c, int fre) {
        this->c = c;
        this->fre = fre;
        left = right = NULL;
    }
};

class cmp {
public:
    bool operator()(tree* a, tree* b) {
        return a->fre > b->fre;
    }
};


unordered_map<char, int> freq(string str) {
    unordered_map<char, int> mp;
    for (char c : str) {
        mp[c]++;
    }
    return mp;
}


tree* make_tree(unordered_map<char, int>& mp) {
    priority_queue<tree*, vector<tree*>, cmp> minheap;

    for (auto &p : mp) {
        minheap.push(new tree(p.first, p.second));
    }

    while (minheap.size() > 1) {
        tree* left = minheap.top(); minheap.pop();
        tree* right = minheap.top(); minheap.pop();

        tree* newNode = new tree('$', left->fre + right->fre);
        newNode->left = left;
        newNode->right = right;

        minheap.push(newNode);
    }

    return minheap.top();
}

    
void generateCodes(tree* root, string code, unordered_map<char, string>& huff) {
    if (!root) return;

    if (root->c != '$') {
        huff[root->c] = code;
    }

    generateCodes(root->left, code + "0", huff);
    generateCodes(root->right, code + "1", huff);
}

int main() {
    string str = "huffman";

    unordered_map<char, int> mp = freq(str);

    tree* root = make_tree(mp);

    unordered_map<char, string> huff;
    generateCodes(root, "", huff);

    cout << "Huffman Codes:\n";
    for (auto &p : huff) {
        cout << p.first << " : " << p.second << endl;
    }

    return 0;
}





