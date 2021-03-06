class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int l=0;
        int r=n-1;
        int ans=0,cur=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(citations[mid]>=n-mid){
                cur=n-mid;
                r=mid-1;
            }
            else{
                l=mid+1;   
            }
            ans=max(ans,cur);
      
        }
        return ans;  
    }
};