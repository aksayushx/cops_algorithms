#include<bits/stdc++.h> 
using namespace std; 
  
// Returns the length of the longest palindromic subsequence in seq 
int longestPalindromicSubs(string str) 
{ 
   int n = str.length(); 
   int i, j, cl; 
   int L[n][n];  

   for (i = 0; i < n; i++) 
      L[i][i] = 1; 

    for (cl=2; cl<=n; cl++) 
    { 
        for (i=0; i<n-cl+1; i++) 
        { 
            j = i+cl-1; 
            if (str[i] == str[j] && cl == 2) 
               L[i][j] = 2; 
            else if (str[i] == str[j]) 
               L[i][j] = L[i+1][j-1] + 2; 
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]); 
        } 
    } 
  
    return L[0][n-1]; 
}  
int main() 
{ 
    string s;
    cout<<"Enter a string\n";
    cin>>s;
    int n = s.length(); 
    cout << "The length of the Longest Palindromic Subsequence is " 
         << longestPalindromicSubs(s); 
    return 0; 
} 
  
