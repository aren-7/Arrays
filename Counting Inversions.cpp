//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long int merge_sort(long long arr[], long long N)
    {
        long long temp[N];
        return _merge_sort(temp, arr, 0, N-1);
    }
    
    long long int _merge_sort(long long temp[], long long arr[], long long left, long long right)
    {
        long long mid, inv_count=0;
        if(left<right)
        {
            mid=(left+right)/2;
            inv_count+=_merge_sort(temp, arr, left, mid);
            inv_count+=_merge_sort(temp, arr, mid+1, right);
            inv_count+=merge(temp, arr, left, mid+1, right);
        }
        return inv_count;
    }
    
    long long int merge(long long temp[], long long arr[], long long left, long long mid, long long right)
    {
        long long int inv=0;
        long long i=left;
        long long j=mid;
        long long k=left;
        while((i<=mid-1) && (j<=right))
        {
            if(arr[i]<=arr[j])
            {
                temp[k++]=arr[i++];
            }
            // Counting inversions when right array is having elements greater then left array
            else
            {
                temp[k++]=arr[j++];
                inv+=(mid-i);
            }
        }
        while(i<=mid-1)
        {
            temp[k++]=arr[i++];
        }
        while(j<=right)
        {
            temp[k++]=arr[j++];
        }
        for(int i=left;i<=right;i++)
        {
            arr[i]=temp[i];
        }
        return inv;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long int ans = merge_sort(arr,N);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends
