class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int cnt[32];
        memset(cnt,0,sizeof(cnt));
        for(int i=31;i>=0;i--){
            for(int j=0;j<nums.size(); j++){
                if(nums[j]&(1<<i)) cnt[i]++;
            }   
        }
        
        int ans=0;
        for(int i=0;i<32; i++){
            if(cnt[i]%3!=0){
                ans|=(1<<i);
            }
        }
        
        return ans;
        
    }
};