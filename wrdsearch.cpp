class Solution {
public:
    
    struct node{
        char c;
        int ends;
        string word;
        node* child[26];
    };
    
    
    struct node* getnode(char c){
        node* newnode=new node;
        newnode->c=c;
        newnode->ends=0;
        newnode->word="";
        for(int i=0;i<26; i++){
            newnode->child[i]=NULL;
        }
        return newnode;
        
    }
    
    node* root=getnode('/');
    
    void insert(string s){
        node* cur=root;
        int index=0,i=0;
        while(s[i]){
            index=s[i]-'a';
            if(cur->child[index]==NULL){
                cur->child[index]=getnode(s[i]);
            }
            
            cur=cur->child[index];
            i++;   
        }
        
        cur->ends+=1;
        cur->word=s;
        
    }
    
    void solve(vector<vector<char>> &board,int i,int j,int r,int c,vector<string> &ans,node* cur){
        
        int index=board[i][j]-'a';
        if(board[i][j]=='#' || cur->child[index]==NULL) return;
        
        cur=cur->child[index];
        if(cur->ends>0){
            ans.push_back(cur->word);
            cur->ends-=1;
        }
        
        char ch=board[i][j];
        board[i][j]='#';
        
        if(i>0) solve(board,i-1,j,r,c,ans,cur);
        if(i<r-1) solve(board,i+1,j,r,c,ans,cur);
        if(j>0) solve(board,i,j-1,r,c,ans,cur);
        if(j<c-1) solve(board,i,j+1,r,c,ans,cur);
        
        board[i][j]=ch;
        
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words){
        int r=board.size();
        int c=board[0].size();
        
        for(int i=0;i<words.size(); i++) insert(words[i]);
        
        vector<string> ans;
        for(int i=0;i<r; i++){
            for(int j=0;j<c; j++){
                solve(board,i,j,r,c,ans,root);
            }
        }
        
        return ans;
    }
    
    
};