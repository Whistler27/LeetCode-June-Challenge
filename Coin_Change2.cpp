class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int ans=0;
        int n=coins.size();
        int dp[amount+1][n+1];
        memset(dp,0,sizeof(dp));
        
        dp[0][0]=1;
        for(int i=1;i<=n; i++){
            dp[0][i]=1;
        }
        for(int i=1;i<=amount; i++) dp[i][0]=0;
        
        for(int i=1;i<=amount; i++){
            for(int j=0;j<n; j++){
                if(i-coins[j]>=0){
                    dp[i][j+1]=dp[i-coins[j]][j+1]+dp[i][j];
                }
                else dp[i][j+1]=dp[i][j];
            }
        }
        return dp[amount][n];
    }
};