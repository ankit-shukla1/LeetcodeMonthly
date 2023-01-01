// Problem Link : https://leetcode.com/problems/count-and-say/description/

class Solution {
public:
    string helper(string input){

        char currDigit = input[0];
        int currCount = 1;
        string result = "";
        for(int i=1; i<input.size(); i++)
        {
            if(input[i] == currDigit)
                currCount++;
            else
            {
                result += to_string(currCount);
                result += to_string(currDigit-'0');
                currCount = 1;
                currDigit = input[i];
            }
        }

            result += to_string(currCount);
            result += to_string(currDigit-'0');

            return result;
    }
    string countAndSay(int n) {

        string result = "1";

        for(int i=2; i<=n; i++){
            result = helper(result);
        }
        
        return result;
    }
};