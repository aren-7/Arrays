//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        // Intial max & steps taken will be first array element
        int maxx=arr[0];
        int steps=arr[0];
        // One jump is essential to reach to any element
        int jump=1;
        
        // if array is having only one element then only one jump is required
        if(n==1) return 1;
        // When array is having zero value then we cannot move further
        else if(arr[0]==0) return -1;
        else
        {
            // Interating over every element to find optimal jump
            for(int i=1;i<n;i++)
            {
                // When we reached last index then return jump value
                if(i==(n-1)) return jump;
                // Max steps we can jump further
                maxx=max(maxx,(i+arr[i]));
                // Steps are calculated every time we take max jump, then we decrement it to find optimal jump
                steps--;
                // When steps become zero that means we need to calculate new jump and step value
                if(steps==0)
                {
                    if(i>=maxx) return -1;
                    steps=maxx-i;
                    jump++;
                }
            }
        }
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
