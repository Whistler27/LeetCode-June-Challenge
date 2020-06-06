class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        vector<vector<int>> v;
        for(int i=0;i<n; i++){
            vector<int> u;
            u.push_back(-1);
            u.push_back(-1);
            v.push_back(u);
        }
        
        sort(people.begin(),people.end());
        for(int i=0;i<n; i++){
            int a=people[i][0];
            int b=people[i][1];
            int cnt=0;
            for(int j=0;j<n; j++){
                if(v[j][0]==-1) cnt++;
                else if(v[j][0]>=a) cnt++;
                if(cnt==b+1){
                    v[j][0]=a;
                    v[j][1]=b;
                    break;
                }
            }
        }
        
        return v;
        
    }
};