//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long max_so_far=INT_MIN;
        long long max_ending_here=0;
        
        for(int i=0;i<n;i++)
        {
            max_ending_here+=arr[i];
          // Updating max_so_far in every iteration
            if(max_so_far<=max_ending_here)
            {
                max_so_far=max_ending_here;
            }
          // When max_ending_here is getting negative then update it to 0 so that it'll not effect other maximums
            if(max_ending_here<0) max_ending_here=0;
        }
        return max_so_far;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends
