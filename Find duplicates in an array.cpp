Problem: https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1?page=1&category=Data%20Structures,Arrays&difficulty=Easy,Medium,Hard&sortBy=submissions
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(long long arr[], int n) {
        // code here
        
        // ARROACH:01
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            long long index;
            index=arr[i]%n;
            arr[index]+=n;
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]/n >= 2)
            {
                ans.push_back(i);
            }
        }
        if(ans.empty())
        {
            ans.push_back(-1);
            return ans;
        }
        return ans;
        /* APPROACH:02
        long long freq[n]={0};
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            freq[arr[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(freq[i]>1)
            {
                ans.push_back(i);
            }
        }
        if(ans.empty())
        {
            ans.push_back(-1);
            return ans;
        }
        return ans;
        */
        /* APPROACH:03
        In this solution ans that we are getting is in sorted form but we don't want that therefore not using map
        unordered_map<long long,long long> mp;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(mp.find(arr[i]) == mp.end())
            {
                mp.insert({arr[i],1});
            }
            else
            {
                mp[arr[i]]++;
            }
        }
        bool flag=true;
        for(auto it:mp)
        {
            if(it.second!=1)
            {
                flag=false;
                ans.push_back(it.first);
            }
        }
        if(flag==true)
        {
            ans.push_back(-1);
        }
        return ans;
        */
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
