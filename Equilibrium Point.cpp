//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        // Array storing sum till now
        long long sum[n]={0};
        sum[0]=a[0];
        // If array is only having 1-element then it is equilibrim point
        if(n==1) return a[0];
        // Computing sum aarray
        for(int i=1;i<n;i++)
        {
            sum[i]=sum[i-1]+a[i];
        }
        // Keeping track if we found that point or not
        int flag=0;
        for(int i=0;i<n;i++)
        {
            // l & r storing left and right sum
            // We'll be computing these value every time for every index
            long long l=0,r=0;
            if(i==0)
            {
                l=0;
            }
            else
            {
                l=sum[i-1];
            }
            r=sum[n-1]-sum[i];
            // When we found that point then return it
            if(l==r)
            {
                flag=1;
                return i+1;
            }
        }
        if(flag==0) return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
