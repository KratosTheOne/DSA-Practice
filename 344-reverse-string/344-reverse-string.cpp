class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int low = 0, high = s.size() - 1;
        
        while(low < high)
        {
            swap(s[low], s[high]);
            low++;
            high--;
        }
        
        for(auto x : s)
            cout << x;
    }
};