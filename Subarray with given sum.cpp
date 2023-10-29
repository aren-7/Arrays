Problem link: https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1?page=1&difficulty[]=0&difficulty[]=1&difficulty[]=2&category[]=Data%20Structures&category[]=Arrays&sortBy=submissions
//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        vector<int> ans;
        // To track first and last index of subarray
        int l=0,r=0;
        // To track sum of subarray of slidding window
        long long temp=0;
        for(int i=0;i<n;i++)
        {
            temp+=arr[i];
            // Windows sum is greater then the limit given 
            if(temp>=s)
            {
                // update the last index of slidding window
                // slidding the window from front for matching the sum
                r=i;
                while(s<temp && l<r)
                {
                    temp-=arr[l];
                    l++;
                }
            }
            if(temp==s)
            {
                // adding one as index are starting from 1
                ans.push_back(l+1);
                ans.push_back(r+1);
                break;
            }
            /*
            // temp+=arr[r];
            if(temp==s)
            {
                ans.push_back(l+1);
                ans.push_back(r+1);
                // cout<<"inside if: "<<temp<<" "<<l<<" "<<r<<endl;
                break;
            }
            else if(temp<s)
            {
                temp+=arr[r];
                if(temp>s)
                {
                    // cout<<"temp is greater"<<endl;
                    // r--;
                    continue;
                }
                else if(temp==s)
                {
                    continue;
                }
                r++;
                // cout<<"inside else-if: "<<temp<<" "<<l<<" "<<r<<endl;
            }
            else
            {
                temp-=arr[l];
                // r--;
                l++;
                // cout<<"inside else: "<<temp<<" "<<l<<" "<<r<<endl;
            }
            */
        }
        // if we never able to reach the desired sum with continuous subarray sum
        if(ans.empty())
        {
            ans.push_back(-1);
            return ans;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
