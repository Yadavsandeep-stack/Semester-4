#include<iostream>
using namespace std;

int fun(vector<int> wt,vector<int> val,int w,int ind){
    if(ind<0||w<=0){
        return 0;
        
    }
    int pick=0;
    if(wt[ind]<=w){
        pick = val[ind]+fun(wt,val,w-wt[ind],ind-1);
    }
    int not_pick = fun(wt,val,w,ind-1);
    return max(pick,not_pick);
}

//Memoisation
int fun1(vector<int> wt,vector<int> val,int w,int ind,vector<int>& dp){
    if(ind<0||w<=0){
        return 0;
        
    }
    if(dp[ind]!=-1) return dp[ind];
    int pick=0;
    if(wt[ind]<=w){
        pick = val[ind]+fun1(wt,val,w-wt[ind],ind-1,dp);
    }
    int not_pick = fun1(wt,val,w,ind-1,dp);
    return dp[ind]=max(pick,not_pick);
}

//Tabulation

int fun2(int W, vector<int> &val, vector<int> &wt) {
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1,0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            
                int pick = 0;
                if(wt[i - 1] <= j)
                    pick = val[i - 1] + dp[i - 1][j - wt[i - 1]];
                int notPick = dp[i - 1][j];
                
                dp[i][j] = max(pick, notPick);
            
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            cout<<dp[i][j]<<" ";
            
        }cout<<endl;
    }
    cout<<endl;
    return dp[n][W];
}
int main(){
    int size;
    cin>>size;
    vector<int> wt(size,0);
    vector<int> val(size,0);
    for(int i=0;i<size;i++){
        cout<<"Enter (wt,val) : ";
        cin>> wt[i];
        cin>>val[i];
    }
    int w;
    cout<<"Enter capacity : ";
    cin>>w;
    cout<<fun(wt,val,w,size-1);
}
int main(){
    vector<int> wt = {4,5,1};
    vector<int> val={1,2,3};
    int w=4;
    vector<int> dp(3,-1);
    cout<<fun1(wt,val,w,2,dp);
}
int main(){
    vector<int> wt = {4,5,1};
    vector<int> val={1,2,3};
    int w=4;
    cout<<fun2(w,val,wt)<<endl;
}



int lcs(string s,int n,string t,int m){
    if(n<0||m<0){
        return 0;
    }
    if(s[n]==t[m]){
        return 1+lcs(s, n-1, t, m-1);
    }
    return max(lcs(s, n, t, m-1),lcs(s, n-1, t, m));
}
//Memoisation
int lcs1(string s,int n,string t,int m,vector<vector<int>>& dp){
    if(n<0||m<0){
        return 0;
    }
    if(dp[n][m]!=-1) return dp[n][m];
    if(s[n]==t[m]){
        return dp[n][m]=1+lcs(s, n-1, t, m-1);
    }
    return dp[n][m]=max(lcs(s, n, t, m-1),lcs(s, n-1, t, m));
}
int lcs2(string s,string t){
    vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,0));
    
    for(int i=1;i<=s.size();i++){
        for(int j=1;j<=t.size();j++){
            if(s[i]==t[j]){
                 dp[i][j]=1+dp[i-1][j-1];
                
            }else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    for(int i=0;i<=s.size();i++){
        for(int j=0;j<=t.size();j++){
            cout<<dp[i][j]<<" ";
            
        }cout<<endl;
    }
    cout<<endl;
    return dp[s.size()][t.size()];
}

int main(){
    string s="ABCD";
    string t= "BCDE";
    vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
    cout<<lcs1(s, s.size()-1, t, t.size()-1,dp)<<endl;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<t.size();j++){
            cout<<dp[i][j] << " " ;
        }cout<<endl;
    }cout<<endl;
}

int main(){
    string s="ABCD";
    string t="BCDE";
    cout<< lcs2(s, t)<<endl;
    
}
