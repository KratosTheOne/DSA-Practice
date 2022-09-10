//T.C & S.C -> O(N * K log K) & O(K)

class node {
    public:
        int data;
        int row;
        int col;
    
        node(int data, int row, int col)
        {
            this -> data = data;
            this -> row = row;
            this -> col = col;
        }
};

class compare{
    public:
        bool operator()(node* a, node* b)
        {
            return a -> data > b -> data; 
        }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& a) {
        
        //sort(a.begin(), a.end());
        
        int k = a.size();
        
        int mini = INT_MAX, maxi = INT_MIN;
    
        priority_queue<node*, vector<node*>, compare> minHeap;

        for(int i = 0; i < k; i++)
        {
            int ele = a[i][0];
            mini = min(mini, ele);
            maxi = max(maxi, ele);
            minHeap.push(new node(ele, i, 0));
        }

        int start = mini, end = maxi;

        while(!minHeap.empty())
        {
            node* tmp = minHeap.top();

            minHeap.pop();

            mini= tmp -> data;
            
            int n = a[tmp -> row].size();

            if(maxi - mini < end - start)
            {
                start = mini;
                end = maxi;
            }

            if(tmp -> col + 1 < n)
            {
                maxi = max(maxi, a[tmp -> row][tmp -> col + 1]);
                minHeap.push(new node(a[tmp -> row][tmp -> col + 1], tmp -> row, tmp -> col + 1));
            }

            else
            {
                break;
            }
        }
        
        return {end, start};
    }
};