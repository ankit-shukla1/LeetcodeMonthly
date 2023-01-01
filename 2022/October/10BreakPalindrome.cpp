// Problem Link : https://leetcode.com/problems/break-a-palindrome/description/

class Solution {
public:
    string breakPalindrome(string palindrome) {

        int n = palindrome.size();

        string result = "";
        if(n==1)
            return result;
        
        int firstNotA = -1;

        for(int i=0; i<n; i++)
        {
            if(palindrome[i] != 'a' )
            {
                if(n%2 == 1 and i == n/2)
                    continue;
                firstNotA = i;
                break;
            }
        }

        // cout<<firstA;
        result = palindrome;
        if(firstNotA == -1)
            result[n-1] = 'b';
        else
            result[firstNotA] = 'a';

        return result;
        
    }
};