//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
	    int max01=INT_MIN;
	    int max02=INT_MIN;
	    // Finding largest element in array
	    for(int i=0;i<n;i++)
	    {
	        if(max01<arr[i])
	        {
	            max01=arr[i];
	        }
	    }
	    // Finding largest element in array which is not equal to first largest element
	    for(int i=0;i<n;i++)
	    {
	        if(max02<arr[i] && arr[i]!=max01)
	        {
	            max02=arr[i];
	        }
	    }
	    if(max02==INT_MIN) return -1;
	    return max02;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
