class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int edges = prerequisites.size();
        
        vector<int> adj[numCourses + 1];
        vector<int> inDegree(numCourses, 0);
        
        for(int i = 0; i < edges; i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            
            adj[v].push_back(u);
            inDegree[u]++;
        }
        
        queue<int> q;
        
        for(int i = 0; i < numCourses; i++)
        {
            if(inDegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        vector<int> topo;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it : adj[node])
            {
                inDegree[it]--;
                if(inDegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        
        if(numCourses == topo.size())
            return topo;
        
        else return {};
    }
};