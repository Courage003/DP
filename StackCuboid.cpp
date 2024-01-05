//Variant of LIS
class Solution {
public:
    bool check(vector<int>& a, vector<int> &b){
        if(b[0]<=a[0] && b[1]<=a[1] && b[2]<=a[2])
            return true;
        else    
            return false;    
    }
    int solveOpt(int n, vector<vector<int>>&a){
       
        vector<int>currRow(n+1,0);
        vector<int>nextRow(n+1,0);
        //base case already sorted
        
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int take=0;
                if(prev==-1 || check(a[curr],a[prev]))
                    take = a[curr][2] + nextRow[curr+1];
                    
                int notTake= 0 + nextRow[prev+1];
                
                currRow[prev+1] = max(take,notTake);
                
            }
            nextRow=currRow;
        }
        return nextRow[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        int n=cuboids.size();
        for( auto &it :cuboids){
            sort(it.begin(),it.end());
        }
      //step1 -individual cuboid elem are sorted

        //step-2 sorting on basis of width
        sort(cuboids.begin(),cuboids.end());

        //Use LIS Logic

        return solveOpt(n,cuboids);

        
    }
};
