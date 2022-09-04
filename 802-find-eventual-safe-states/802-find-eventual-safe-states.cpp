//T.C & S.C -> O(V+E) & O(3*V)

class Solution {
private:
    void prepareAdj(vector<int> adj[], vector<vector<int>>& graph)
    {
        for(int i = 0; i < graph.size(); i++)
        {
            for(int j = 0; j < graph[i].size(); j++)
            {
                adj[i].push_back(graph[i][j]);
            }
        }
    }
    
    bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis, vector<int>& check)
    {
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;
        
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it, adj, vis, pathVis, check) == true)
                {
                    check[node] = 0;
                    return true;
                }
            }
            else if(pathVis[it])
            {
                check[node] = 0;
                return true;
            }
        }
        
        pathVis[node] = 0;
        check[node] = 1;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int V = graph.size();
        vector<int> adj[V];
        
        prepareAdj(adj, graph);
        
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> check(V, 0);
        vector<int> safeNodes;
        
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
                dfs(i, adj, vis, pathVis, check);
        }
        
        for(int i = 0; i < V; i++)
        {
            if(check[i] == 1)
                safeNodes.push_back(i);
        }
        
        return safeNodes;
    }
};