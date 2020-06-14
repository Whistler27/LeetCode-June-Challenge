class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return nums;
        sort(nums.begin(),nums.end());
        vector<vector<int>> result(n,vector<int>());
        int maxlen=1;
        int maxind=0;
        
        for(int i=n-1;i>=0;i--){
            result[i].push_back(nums[i]);
            int j=i+1;
            int ma=0;
            int mind=i;
            while(j<n){
                if(nums[j]%nums[i]==0 && result[j].size()>ma){
                    ma=result[j].size();
                    mind=j;
                }
                j++;
            }
            if(mind!=i){
                result[i].insert(result[i].end(),result[mind].begin(),result[mind].end());
                if(ma+1>maxlen){
                    maxlen=ma+1;
                    maxind=i;
                }
            }
        }
        return result[maxind];    
    }
    
    
};