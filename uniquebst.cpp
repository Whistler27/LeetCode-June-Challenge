class Solution {
public:
    
    int numTrees(int n) {
       long long int dp[n+1];
        if(n==1) return 1;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        
        for(int i=3;i<=n; i++){
            for(int j=0;j<=i-1; j++){
                dp[i]+=(dp[j]*dp[i-1-j]);
            }
        }
        
        return dp[n];
        
    }
};