//T.C & S.C -> O(v + e) & O(v)

class Solution {
private:
    bool dfs(int node, vector<int> adj[], vector<int>& vis)
    {
        vis[node] = 2;
        
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it, adj, vis) == true)
                    return true;
            }
            
            else if(vis[it] == 2)
                return true;
        }
        
        vis[node] = 1;
        
        return false;
    }
    
    void prepareAdj(vector<int> adj[], vector<vector<int>>& prerequisites)
    {
        for(int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            
            adj[v].push_back(u);
        }
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        
        prepareAdj(adj, prerequisites);
        
        vector<int> vis(numCourses, 0);
        
        for(int i = 0; i < numCourses; i++)
        {
            if(!vis[i])
            {
                if(dfs(i, adj, vis))
                    return false;
            }
        }
        
        return true;
    }
};