class Solution {
public:
    string validIPAddress(string IP) {
        int n=IP.size();
        int len=0;
        vector<string> ans;
        bool ip4=0,ip6=0;
        string cur="";
        for(int i=0;i<n; i++){
            if(IP[i]=='.'){
                ip4=1;
                break;
            }
        }
        
        if(ip4){
            for(int i=0;i<n; i++){
                if(IP[i]=='.'){
                    ans.push_back(cur);
                    cur="";
                }
                else cur+=IP[i];
            }    
            
            ans.push_back(cur);
            if(ans.size()>4 || ans.size()<=3) return "Neither";
            for(int i=0;i<4; i++){
                if(ans[i].size()==0 || ans[i].size()>3) return "Neither";
                if(ans[i]<="255" && ans[i]>="0"){
                    if(ans[i].size()>1){
                        if(ans[i][0]=='0') return "Neither";
                    }
                }
                else return "Neither";
            }
            
            return "IPv4";
            
        }
        else{
            // for ip6
            
            for(int i=0;i<n; i++){
                if(IP[i]==':'){
                    ans.push_back(cur);
                    cur="";
                }
                else cur+=IP[i];
            }    
            ans.push_back(cur);
            if(ans.size()>=9 || ans.size()<=7) return "Neither";
            for(int i=0;i<8; i++){
                if(ans[i].size()==0 || ans[i].size()>=5) return "Neither";
                for(int j=0;j<ans[i].size(); j++){
                    if((ans[i][j]>='0'&& ans[i][j]<='9') || (ans[i][j]>='a' && ans[i][j]<='f') || (ans[i][j]>='A' && ans[i][j]<='F')){
                        continue;
                    }
                    else return "Neither";
                }
            }
            
        }
        
        return "IPv6";
        
    }
};