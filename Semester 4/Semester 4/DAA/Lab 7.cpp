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



//Q.2 : Implement AVL tree
//This is one time conversion of a binary search tree into the AVL tree using the divide and conquere algorithm

class node {
public:
    int val;
    node* left;
    node* right;

    node(int v) {
        val = v;
        left = right = NULL;
    }
};


node* insertBST(node* root, int val) {
    if (!root) return new node(val);

    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}


void inorderPrint(node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}


void inorderStore(node* root, vector<int>& arr) {
    if (!root) return;
    inorderStore(root->left, arr);
    arr.push_back(root->val);
    inorderStore(root->right, arr);
}


node* buildAVL(vector<int>& arr, int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    node* root = new node(arr[mid]);
    root->left = buildAVL(arr, start, mid - 1);
    root->right = buildAVL(arr, mid + 1, end);
    return root;
}
node* convertToAVL(node* root) {
    vector<int> arr;
    inorderStore(root, arr);
    return buildAVL(arr, 0, arr.size() - 1);
}
//
