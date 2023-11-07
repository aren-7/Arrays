//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        bool ans= false;
        stack<char> s;
        int n=x.length();
        
        for(int i=0;i<n;i++)
        {
            // If stack is empty push first element
            if(s.empty())
            {
                s.push(x[i]);
            }
            else
            {
                // Pop from top of stack if parenthesis is balanced
                if(x[i]=='}' && s.top()=='{')
                {
                    s.pop();
                }
                else if(x[i]==')' && s.top()=='(')
                {
                    s.pop();
                }
                else if(x[i]==']' && s.top()=='[')
                {
                    s.pop();
                }
                // If not balanced just push it into stack
                else
                {
                    s.push(x[i]);
                }
            }
        }
        // If given string is balanced return true
        if(s.empty()) 
        {
            ans=true;
        }
        return ans;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends
