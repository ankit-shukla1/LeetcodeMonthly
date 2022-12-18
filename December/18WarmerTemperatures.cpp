// Problem Link : https://leetcode.com/problems/daily-temperatures/description/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();
        stack<int> s;
        vector<int> result(n);

        for(int i=0; i<n; i++){
            while(s.empty()==false and temperatures[s.top()] < temperatures[i]){
                result[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return result;     
    }
};