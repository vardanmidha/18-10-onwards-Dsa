class Solution {
    
    
    
    private:
    
    bool bfs(vector<int> adj[] , int node , vector<int> &vis){
        
        
        
        vis[node] = 1;
        
        queue<pair<int , int>> q;
        // pair = node , parent
        
        q.push({node , -1});
        // Assume parent of starting node is -1
        
        
        
        while(!q.empty()){
            
            auto ite = q.front();
            int currNode =ite.first; 
            int parent = ite.second;
            q.pop();
            
            for(auto it:adj[node]){
                
                
                if(!vis[it]){
                    // Here it means Adjacent nodes.
                    vis[it] = 1;
                    
                    q.push({it , currNode});
                }
                
                
                
                
                // if we fount it visited , but the parent is not equal to the it (adjacent nodes).
                // Then we got our cycle
                
                else if(parent!=it){
                    return true;
                }
            }
            
            
            
        }
        return false;
        
    }
    
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        
        vector<int> vis(V+1 , 0);
        
        
        for(int i=0 ; i<V ; i++){
            
            if(!vis[i] ){
                
                if(bfs(adj , i , vis) == true )
{
    return true;
}                
            }
            
        }
        
        
        return false;
    }
};
