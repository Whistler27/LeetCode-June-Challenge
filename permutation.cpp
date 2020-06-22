class Solution {
public:
    
    vector<int> dig,fact;
    void solve(string &ans,int n,int k){
        
        if(dig.size()==1){
            ans+=(dig[0]+'0');
            
            return;
        }
        
        int ind=k/fact[n-1];
        if(k%fact[n-1]==0) ind--;
        
        ans+=(dig[ind]+'0');
        dig.erase(dig.begin()+ind);
        k=k-ind*fact[n-1];
        
        solve(ans,n-1,k);
        
        
    }    
    
    string getPermutation(int n, int k) {
        int f=1;
        fact.push_back(f);
        for(int i=1;i<=n; i++){
            f*=i;
            fact.push_back(f);
        }

        for(int i=1;i<=n; i++){
            dig.push_back(i);
        }
        
        string ans;
        solve(ans,n,k);
        return ans;
        
    }
};