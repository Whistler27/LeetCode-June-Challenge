class Solution {
public:
    
    void solve(vector<vector<int>> &adj,vector<vector<int>> &cost, int src,int dst,int k,int &ans,int tot,vector<bool> &vis){
        if(k<-1) return;
        if(src==dst){
            ans=min(ans,tot);
            return;
        }
        
        vis[src]=true;
        for(int i=0;i<adj[src].size(); i++){
            if(!vis[adj[src][i]] && (tot+cost[src][adj[src][i]]<=ans)){
                solve(adj,cost,adj[src][i],dst,k-1,ans,tot+cost[src][adj[src][i]],vis);
            }
        }
        vis[src]=false;
        
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        int m=flights.size();
        vector<vector<int>> adj(n);
        vector<vector<int>> cost(n+1,vector<int>(n+1));
        
        for(int i=0;i<m; i++){
            adj[flights[i][0]].push_back(flights[i][1]);
            cost[flights[i][0]][flights[i][1]]=flights[i][2];
        }
        
        vector<bool> vis(n+1,false);
        int ans=INT_MAX;
        solve(adj,cost,src,dst,K,ans,0,vis);
        
        if(ans==INT_MAX) return -1;
        return ans;
        
    }
};