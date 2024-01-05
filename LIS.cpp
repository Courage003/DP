//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Mamoization
    int solve(int n, int a[], int curr, int prev,vector<vector<int>>&dp){
        if(curr==n){
            return 0;
        }
        //include
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        int take=0;
        if(prev==-1 || a[curr]>a[prev])
            take = 1 + solve(n,a,curr+1,curr,dp);
            
        int notTake= 0 + solve(n,a,curr+1,prev,dp);
        
        return dp[curr][prev+1]=max(take,notTake);
    }
    
    int solveTab(int n, int a[]){
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        //base case already sorted
        
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int take=0;
                if(prev==-1 || a[curr]>a[prev])
                    take = 1 + dp[curr+1][curr+1];
                    
                int notTake= 0 + dp[curr+1][prev+1];
                
                dp[curr][prev+1] = max(take,notTake);
                
            }
        }
        return dp[0][0];
    }
    
    //Space Optimixation
    
    int solveOpt(int n, int a[]){
       
        vector<int>currRow(n+1,0);
        vector<int>nextRow(n+1,0);
        //base case already sorted
        
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int take=0;
                if(prev==-1 || a[curr]>a[prev])
                    take = 1 + nextRow[curr+1];
                    
                int notTake= 0 + nextRow[prev+1];
                
                currRow[prev+1] = max(take,notTake);
                
            }
            nextRow=currRow;
        }
        return nextRow[0];
    }
    
    //Dp with Binary Search
    int solveOptt(int n, int a[]){
        vector<int>ans;
        if(n==0) return 0;
        ans.push_back(a[0]);
        
        for(int i=1;i<n;i++){
            if(a[i]>ans.back()){
                ans.push_back(a[i]);
            }
            else{
                //find index of just badaa element
                int id= lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
                ans[id]=a[i];
            }
        }
        return ans.size();
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       //vector<vector<int>>dp(n,vector<int>(n+1,-1));
       return solveOptt(n,a);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends
