////Q. 1. . Given a square matrix mat[][] of size n x n, such that mat[i][j] = 1 means ith person knows jth person, the task is to find the celebrity. A celebrity is a person who is known to all but does not know anyone. Return the index of the celebrity, if there is no celebrity return
////-1Note: Follow 0 based indexing and M[i][i] will always be 0.
////
////Examples:
////Input:
////mat = { {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0} }
////Output: id = 2Explanation: The person with ID 2
////does not know anyone but everyone knows him
//
//#include<iostream>
//using namespace std;
//
//int celebrity(vector<vector<int>> vec,int n){
//    int a = 0;
//    int b = n-1;
//    while(a<b){
//        if(vec[a][b]==1){
//            a++;
//        }else{
//            b--;
//        }
//    }
//    int candidate = a;
//    for(int i=0;i<n;i++){
//        if(i!=candidate &&(vec[candidate][i]==1||vec[i][candidate]==0)){
//            return -1;
//        }
//    }
//    return candidate;
//}
//
//
//int main() {
//    vector<vector<int>> mat = {
//        {0, 0, 1, 0},
//        {0, 0, 1, 0},
//        {0, 0, 0, 0},
//        {0, 0, 1, 0}
//    };
//
//    int n = mat.size();
//
//    int result = celebrity(mat, n);
//
//    if (result == -1) {
//        cout << "No Celebrity Found" << endl;
//    } else {
//        cout << "Celebrity ID = " << result << endl;
//    }
//
//    return 0;
//}
//
//
//
////Q 2. There are ‘N’ Kids, the task is to distribute books such that given an array arr[] of n integers where arr[i] represents the number of books in ith packet. Each packet can have a variable number of books. There are N Kids, the task is to distribute book packets such that: Each Kid gets exactly one book. The difference between the maximum and minimum number of books in the packets given to the Kids is minimized.
////
////
////Input: arr[] = {7, 3, 2, 4,
////9, 12, 56}, N = 3
////Output: 2
////
////Explanation: If we distribute book packets {3, 2, 4}, we will get the minimum
////difference, i.e.,  2.
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int minDiff(vector<int>& arr, int n, int k) {
//    if (k > n) return -1;
//
//    sort(arr.begin(), arr.end());
//
//    int ans = INT_MAX;
//
//    for (int i = 0; i <= n - k; i++) {
//        int diff = arr[i + k - 1] - arr[i];
//        ans = min(ans, diff);
//    }
//
//    return ans;
//}
//
//int main() {
//    vector<int> arr = {7, 3, 2, 4, 9, 12, 56};
//    int n = arr.size();
//    int k = 3;
//
//    cout << minDiff(arr, n, k);
//}
