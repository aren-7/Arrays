Problem: https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1?page=1&category=Data%20Structures,Arrays&difficulty=Easy,Medium,Hard&sortBy=submissions
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        // Variables to count number of 0's, 1's & 2's
        int count1=0, count2=0,count3=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0) count1++;
            else if(a[i]==1) count2++;
            else count3++;
        }
        // changing the array according to count of 0's, 1's & 2's
        for(int i=0;i<n;i++)
        {
            if(count1!=0)
            {
                a[i]=0;
                count1--;
                continue;
            }
            else if(count2!=0)
            {
                a[i]=1;
                count2--;
                continue;
            }
            else
            {
                a[i]=2;
                count3--;
            }
        }
        
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends
