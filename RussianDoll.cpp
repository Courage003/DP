//variant of DP with Binary Search
class Solution {
public:
    static bool comp(vector<int>& a, vector<int> &b){
        if(a[0]==b[0]){
            return a[1]>b[1]; //applying decreasing order as per height
        }
        return a[0]<b[0];
    }

    int solve(vector<vector<int>>&e){
        int n=e.size();
        if(n==0) return 0;
        vector<int>ans;
        ans.push_back(e[0][1]);

        for(int i=1;i<n;i++){
            if(e[i][1]>ans.back()){
                ans.push_back(e[i][1]);
            }
            else{
                //find index
                int id= lower_bound(ans.begin(),ans.end(),e[i][1])-ans.begin();
                ans[id]=e[i][1];
            }

        }
        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end(),comp);
        return solve(envelopes);
        
    }
};
