//T.C & S.C -> O(V + 2E) & O(V)

class Solution {
private:
    bool check(int start, int V, vector<vector<int>>& adj, vector<int>& color)
    {
        queue<int> q;
        q.push(start);

        color[start] = 0;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto it : adj[node])
            {
                if(color[it] == -1)
                {
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it] == color[node])
                {
                    return false;
                }
            }
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& adj) {
        
        int V = adj.size();
        
        vector<int> color(V, -1);

	    for(int i = 0; i < V; i++)
	    {
	        if(color[i] == -1)
	        {
	            if(check(i, V, adj, color) == false)
	                return false;
	        }
	    }

	    return true;
    }
};