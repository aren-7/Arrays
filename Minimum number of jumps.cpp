Problem: https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1?page=1&difficulty[]=0&difficulty[]=1&difficulty[]=2&category[]=Data%20Structures&category[]=Arrays&sortBy=submissions
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        // With jump vector we are tracking min jumps required for every index
        vector<int> jump(n,1e9);
        // Jump to first index is always zero
        jump[0]=0;
        // When first index is zero then there is no way to jump anywhere
        if(arr[0]==0) return -1;
        for(int i=1;i<n;i++)
        {
            // Updating jump of every index by checking min jump from 0 to current index
            for(int j=0;j<i;j++)
            {
                if(i<=(j+arr[j]))
                {
                    // Computing min jump
                    jump[i]=min(jump[i],(jump[j]+1));
                }
            }
        }
        // When jump value of last index is not updated that means it is not possible
        if(jump[n-1]==1e9) return -1;
        return jump[n-1];
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends
