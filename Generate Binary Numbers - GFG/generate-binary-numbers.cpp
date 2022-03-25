// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
    queue<string> q;
    vector<string> ans;
    
    q.push("1");
    //q.push("0");
    
    for(int count = 0; count < N; count++)
    {
        string curr = q.front();
        ans.push_back(curr);
        q.pop();
        q.push(curr + "0");
        q.push(curr + "1");
    }
    return ans;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends