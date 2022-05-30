#include <bits/stdc++.h> 
using namespace std; 
bool isPalRec(char str[], int s, int e) 
{
    if (s == e) 
    return true; 
  
    // If first and last 
    // characters do not match 
    if (str[s] != str[e]) 
    return false; 
  
    // If there are more than  
    // two characters, check if  
    // middle substring is also  
    // palindrome or not. 
    if (s < e + 1) 
    return isPalRec(str, s + 1, e - 1); 
  
    return true; 
} 
  
bool isPalindrome(char str[]) 
{ 
    int n = strlen(str); 
      
    // An empty string is  
    // considered as palindrome 
    if (n == 0) 
        return true; 
      
    return isPalRec(str, 0, n - 1); 
} 
  
// Driver Code 
int main() 
{ 
    char str[] = "ABCB"; 
  
    if (isPalindrome(str)) 
    cout << "Yes"; 
    else
    cout << "No"; 
  
    return 0; 
} 
