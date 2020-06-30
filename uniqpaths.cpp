class Solution {
public:
    vector<int> fact;
    int uniquePaths(int m, int n) {
        long long int ans = 1; 
        for (int i = n; i < (m + n - 1); i++) { 
            ans*= i; 
            ans /= (i - n + 1); 
        } 
        return ans; 
        
    }
};