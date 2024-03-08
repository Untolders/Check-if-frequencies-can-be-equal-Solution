##################################################################################  Question  ############################################################################################################

Given a string s which contains only lower alphabetic characters, check if it is possible to remove at most one character from this string in such a way that frequency of each distinct character becomes same in the string. Return true if it is possible to do else return false.

Note: The driver code print 1 if the value returned is true, otherwise 0.

Example 1:

Input:
s = "xyyz"
Output: 
1 
Explanation: 
Removing one 'y' will make frequency of each character to be 1.
Example 2:

Input:
s = "xxxxyyzz"
Output: 
0
Explanation: 
Frequency can not be made same by removing at most one character.
Your Task:  
You dont need to read input or print anything. Complete the function sameFreq() which takes a string as input parameter and returns a boolean value denoting if same frequency is possible or not.

Expected Time Complexity: O(|s|) 
Expected Auxiliary Space: O(1)

Constraints:
1 <= |s| <= 105




##################################################################################  Solution  ############################################################################################################

  //{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	      if(s.length()==1)
    {
        return true;
    }
    int arr[26]={0};
    for(int i=0;i<s.length();i++)
    {
        arr[s[i]-'a']++;
    }
    int count=0;
    int maxi=0;
    int mini=s.length();
    for(int i=0;i<26;i++)
    {
        if(arr[i]!=0)
        {
            maxi=max(maxi,arr[i]);
            mini=min(mini,arr[i]);
        }
    }
    for(int i=0;i<26;i++)
    {
        if(arr[i]!=0 and arr[i]==maxi)
        {
            count++;
        }
    }
    if(maxi==mini)
    {
        return true;
    }
    if(mini!=1)
    {
        if(count>1)
        {
            return false;
        }
    }
    if(maxi-mini==1)
    {
        return true;
    }
    return false;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends
