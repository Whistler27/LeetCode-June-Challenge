class Solution {
public:
    
    
    
    int numSquares(int n) {
        if(n<=3) return n;
        
        int dp[n+1];
        for(int i=0;i<=n; i++) dp[i]=n;
        
        dp[1]=1;
        dp[0]=0;
        dp[2]=2;
        dp[3]=3;
        
        for(int i=1;i*i<=n; i++) dp[i*i]=1;
        
        for(int i=4;i<=n; i++){
            for(int j=1;j*j<=i; j++){
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
            //cout << dp[i] << " ";
        }
        
        return dp[n];
    }
};