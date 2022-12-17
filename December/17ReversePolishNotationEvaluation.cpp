// Problem Link : https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
private:
    static bool checkIsSymbol(string c){
        return ( c == "+" || c == "-" || c == "*" || c == "/");
    }
    static long long int calculate(long long int a,long long int b, string symbol){
        switch (symbol[0]){

            case '+':
                return a+b;
            case '-':
                return b-a;
            case '*':
                return a*b;
            case '/':
                return b/a;

        }

        return 0;
    }
public:
    int evalRPN(vector<string>& tokens) {

        stack<long long int> st;
        st.push(stoi(tokens[0]));
        int n = tokens.size();
        int i=1;
        while(i<n && st.empty() == false){
            string c = tokens[i];
            if(checkIsSymbol(c)){
                long long int a = st.top();
                st.pop();
                long long int b = st.top();
                st.pop();
                long long int result = calculate(a,b,c);
                st.push(result);
            }else{
                st.push(stoi(c));
            }
            i++;
        }

        return st.top();
        
    }
};