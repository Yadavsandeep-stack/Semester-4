//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Solution {
//public:
//    int timer = 0;
//
//    void dfs(int u, int parent, vector<int> adj[],
//             vector<int>& disc, vector<int>& low,
//             vector<vector<int>>& bridges) {
//
//        disc[u] = low[u] = timer++;
//
//        for (int v : adj[u]) {
//            if (v == parent) continue;
//
//            if (disc[v] == -1) {
//                dfs(v, u, adj, disc, low, bridges);
//                low[u] = min(low[u], low[v]);
//
//                if (low[v] > disc[u]) {
//                    bridges.push_back({u, v});
//                }
//            } else {
//                low[u] = min(low[u], disc[v]);
//            }
//        }
//    }
//
//    vector<vector<int>> findBridges(int V, vector<int> adj[]) {
//        timer = 0;
//        vector<int> disc(V, -1), low(V, -1);
//        vector<vector<int>> bridges;
//
//        for (int i = 0; i < V; i++) {
//            if (disc[i] == -1) {
//                dfs(i, -1, adj, disc, low, bridges);
//            }
//        }
//
//        return bridges;
//    }
//};
//
//int main() {
//    int V = 5;
//
//    vector<int> adj[V];
//
//    adj[0].push_back(1);
//    adj[1].push_back(0);
//
//    adj[1].push_back(2);
//    adj[2].push_back(1);
//    adj[2].push_back(0);
//    adj[0].push_back(2);
//
//    adj[1].push_back(3);
//    adj[3].push_back(1);
//
//    adj[3].push_back(4);
//    adj[4].push_back(3);
//
//    Solution obj;
//    vector<vector<int>> bridges = obj.findBridges(V, adj);
//
//    cout << "Bridges in the graph:\n";
//    for (auto &edge : bridges) {
//        cout << edge[0] << " - " << edge[1] << endl;
//    }
//
//    return 0;
//}
//int optimalMerge(vector<int>& files) {
//    priority_queue<int, vector<int>, greater<int>> pq;
//    // Insert all file sizes
//    for (int size : files) {
//        pq.push(size);
//    }
//    int totalCost = 0;
//    while (pq.size() > 1) {
//        int first = pq.top(); pq.pop();
//        int second = pq.top(); pq.pop();
//
//        int mergeCost = first + second;
//        totalCost += mergeCost;
//
//        pq.push(mergeCost);
//    }
//    return totalCost;
//}
//
//int main() {
//    int size;
//    cout<<"Enter size : "<<endl;
//    cin>>size;
//    vector<int> vec(size,0);
//    for(int i=0;i<size;i++){
//        cin>>vec[i];
//    }
//    cout << optimalMerge(vec);
//}
//
//
//
//
//void printOptimalParenthesis(int i, int j, vector<vector<int>>& bracket, char &name) {
//    if (i == j) {
//        cout << name++;
//        return;
//    }
//    cout << "(";
//    printOptimalParenthesis(i, bracket[i][j], bracket, name);
//    printOptimalParenthesis(bracket[i][j] + 1, j, bracket, name);
//
//    cout << ")";
//}
//
//
//void matrixChainMultiplication(vector<int>& p) {
//    int n = p.size();
//    vector<vector<int>> dp(n, vector<int>(n, 0));
//    vector<vector<int>> bracket(n, vector<int>(n, 0));
//    for (int len = 2; len < n; len++) {
//        for (int i = 1; i < n - len + 1; i++) {
//            int j = i + len - 1;
//            dp[i][j] = INT_MAX;
//            for (int k = i; k < j; k++) {
//                int cost = dp[i][k] + dp[k+1][j]
//                         + p[i-1] * p[k] * p[j];
//
//                if (cost < dp[i][j]) {
//                    dp[i][j] = cost;
//                    bracket[i][j] = k;
//                }
//            }
//        }
//    }
//    cout << "Minimum number of multiplications: " << dp[1][n-1] << endl;
//    cout << "Optimal Parenthesization: ";
//    char name = 'A';
//    printOptimalParenthesis(1, n-1, bracket, name);
//    cout << endl;
//}
//
//int main() {
//    vector<int> p = {10, 20, 30, 40};
//    matrixChainMultiplication(p);
//    return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//int main(){
//    int t;
//    cin>>t;
//    while(t--){
//        vector<int> vec(7,0);
//        int sum=0;int maxi=0;
//        for(int i=0;i<7;i++){
//            cin>>vec[i];
//            sum+=vec[i];
//            if(maxi<vec[i]){
//                maxi = vec[i];
//            }
//            
//        }
//        sum = sum-maxi;
//        sum=-sum;
//        cout<<sum+maxi;
//        
//    }
//    return 0;
//}


