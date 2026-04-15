//#include<iostream>
//#include <chrono>
//using namespace std;
//using namespace chrono;
//
//class TreeNode{
//public:
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//
//    TreeNode(int x){
//        val = x;
//        left = right = NULL;
//    }
//};
//
//TreeNode* buildTree(int N) {
//    if (N == 0) return NULL;
//
//    queue<TreeNode*> q;
//    int val;
//    cin >> val;
//
//    if (val == -1) return NULL;
//
//    TreeNode* root = new TreeNode(val);
//    q.push(root);
//
//    while (!q.empty()) {
//        TreeNode* curr = q.front();
//        q.pop();
//
//        int leftVal, rightVal;
//        cin >> leftVal >> rightVal;
//
//        if (leftVal != -1) {
//            curr->left = new TreeNode(leftVal);
//            q.push(curr->left);
//        }
//
//        if (rightVal != -1) {
//            curr->right = new TreeNode(rightVal);
//            q.push(curr->right);
//        }
//    }
//
//    return root;
//}
//
//
//
//int height(TreeNode* root){
//    if(root==NULL) return 0;
//    return 1 + max(height(root->left), height(root->right));
//}
////memoise
//int diameter(TreeNode* root, unordered_map<TreeNode*, int>& dp){
//    if(root==NULL) return 0;
//
//    if(dp.count(root)) return dp[root];
//
//    int lheight = height(root->left);
//    int rheight = height(root->right);
//
//    int ldiameter = diameter(root->left, dp);
//    int rdiameter = diameter(root->right, dp);
//
//    return dp[root] = max({lheight + rheight, ldiameter, rdiameter});
//}
////tabulation
//int diameter(TreeNode* root){
//    if(root==NULL) return 0;
//    int lheight = height(root->left);
//    int rheight = height(root->right);
//    int ldiameter = diameter(root->left);
//    int rdiameter = diameter(root->right);
//
//    return max({lheight + rheight, ldiameter, rdiameter});
//}
//
//
//
//int main() {
//    int N;
//    cin >> N;
//    TreeNode* root = buildTree(N);
//    unordered_map<TreeNode*, int> dp;
//    auto start = high_resolution_clock::now();
//    int ans = diameter(root, dp);
//    auto stop = high_resolution_clock::now();
//    auto duration = duration_cast<microseconds>(stop - start);
//
//    cout << "Diameter: " << ans << endl;
//    cout << "Execution Time: " << duration.count() << " microseconds" << endl;
//}
//
//
//
//

////#include<iostream>
////using namespace std;
////
////int main(){
////    int i=0;
////    for(i =0;i<5;i++);
////    cout<<i;
////}
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//
//// Convex Hull (fixed your approach)
//
//class Solution1 {
//public:
//
//
//    int cross(pair<int,int> a, pair<int,int> b, pair<int,int> c){
//        return (b.first - a.first)*(c.second - a.second) -
//               (b.second - a.second)*(c.first - a.first);
//    }
//
//    pair<float,float> polar(pair<int,int> q, pair<int,int> pivot){
//        pair<float,float> pq;
//
//
//        float angle = atan2(q.second - pivot.second, q.first - pivot.first);
//
//        float dx = q.first - pivot.first;
//        float dy = q.second - pivot.second;
//
//        float r = dx*dx + dy*dy;
//
//        pq.first = angle;
//        pq.second = r;
//        return pq;
//    }
//
//    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
//
//        int n = trees.size();
//        if(n <= 3) return trees;
//
//        vector<pair<int,int>> res;
//        vector<pair<pair<int,int>,pair<float,float>>> data;
//
//
//        pair<int,int> pivot = {trees[0][0], trees[0][1]};
//        for(auto &t : trees){
//            if(t[1] < pivot.second || (t[1] == pivot.second && t[0] < pivot.first)){
//                pivot = {t[0], t[1]};
//            }
//        }
//
//
//        for(int i=0;i<n;i++){
//            pair<int,int> temp = {trees[i][0], trees[i][1]};
//            data.push_back({temp, polar(temp, pivot)});
//        }
//
//
//        sort(data.begin(), data.end(), [](auto& a, auto& b){
//            if(a.second.first == b.second.first)
//                return a.second.second < b.second.second;
//            return a.second.first < b.second.first;
//        });
//
//
//        for(int i=0;i<n;i++){
//            while(res.size() >= 2 &&
//                  ((res.back().first - res[res.size()-2].first) *
//                   (data[i].first.second - res.back().second) -
//                   (res.back().second - res[res.size()-2].second) *
//                   (data[i].first.first - res.back().first)) < 0){
//                res.pop_back();
//            }
//            res.push_back(data[i].first);
//        }
//
//
//        vector<vector<int>> vec;
//        for(int i=0;i<res.size();i++){
//            vec.push_back({res[i].first, res[i].second});
//        }
//
//        return vec;
//    }
//};
//
//#include <chrono>
//
//using namespace std::chrono;
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//
//// Convex Hull (fixed your approach)
//
//class Solution {
//public:
//
//    // Cross product (IMPORTANT)
//    int cross(pair<int,int> a, pair<int,int> b, pair<int,int> c){
//        return (b.first - a.first)*(c.second - a.second) -
//               (b.second - a.second)*(c.first - a.first);
//    }
//
//    pair<float,float> polar(pair<int,int> q, pair<int,int> pivot){
//        pair<float,float> pq;
//
//        // shift origin to pivot + atan2 fix
//        float angle = atan2(q.second - pivot.second, q.first - pivot.first);
//
//        float dx = q.first - pivot.first;
//        float dy = q.second - pivot.second;
//
//        float r = dx*dx + dy*dy; // squared distance (better)
//
//        pq.first = angle;
//        pq.second = r;
//        return pq;
//    }
//
//    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
//
//        int n = trees.size();
//        if(n <= 3) return trees;
//
//        vector<pair<int,int>> res;
//        vector<pair<pair<int,int>,pair<float,float>>> data;
//
//        // 🔥 Step 1: find pivot (lowest, then leftmost)
//        pair<int,int> pivot = {trees[0][0], trees[0][1]};
//        for(auto &t : trees){
//            if(t[1] < pivot.second || (t[1] == pivot.second && t[0] < pivot.first)){
//                pivot = {t[0], t[1]};
//            }
//        }
//
//        // Step 2: build data with polar wrt pivot
//        for(int i=0;i<n;i++){
//            pair<int,int> temp = {trees[i][0], trees[i][1]};
//            data.push_back({temp, polar(temp, pivot)});
//        }
//
//        // Step 3: sort by angle + distance
//        sort(data.begin(), data.end(), [](auto& a, auto& b){
//            if(a.second.first == b.second.first)
//                return a.second.second < b.second.second;
//            return a.second.first < b.second.first;
//        });
//
//        // Step 4: Graham Scan (FIXED LOGIC)
//        for(int i=0;i<n;i++){
//            while(res.size() >= 2 &&
//                  ((res.back().first - res[res.size()-2].first) *
//                   (data[i].first.second - res.back().second) -
//                   (res.back().second - res[res.size()-2].second) *
//                   (data[i].first.first - res.back().first)) < 0){
//                res.pop_back();
//            }
//            res.push_back(data[i].first);
//        }
//
//        // Step 5: convert to required format
//        vector<vector<int>> vec;
//        for(int i=0;i<res.size();i++){
//            vec.push_back({res[i].first, res[i].second});
//        }
//
//        return vec;
//    }
//};
//int main() {
//    Solution1 obj;
//    vector<vector<int>> trees = {
//        {1,1}, {2,2}, {2,0}, {2,4},
//        {3,3}, {4,2}
//    };
//    auto start = high_resolution_clock::now();
//    vector<vector<int>> result = obj.outerTrees(trees);
//    auto end = high_resolution_clock::now();
//    auto duration = duration_cast<microseconds>(end - start);
//    cout << "Convex Hull Points:\n";
//    for(auto &p : result){
//        cout << p[0] << " " << p[1] << endl;
//    }
//    cout << "\nExecution Time: " << duration.count() << " microseconds" << endl;
//    return 0;
//}
//
//
