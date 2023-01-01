// Problem Link : https://leetcode.com/problems/decode-ways/description/

class Solution {
public:
int numDecodings(string s)
{
    int f =0, sec=0;
    int current = s[0]-'0';

    if(current>0)
        f = 1, sec=1;
    
//     if( current == 0)
//         return 0;

    if( s.size()  == 1 )
        return f;
    
    int next = current*10 + (s[1]-'0');
    if(s[1] == '0')
    {
        if( next >= 10 and next <= 26)
            sec = f;
        else 
            return 0;
            
    }
    else if( next > 10 and next <= 26 )
        sec = f + 1;
    for(int i=2; i<s.size(); i++)
    {

        int curr = 0;
        // cout<<"Start Loop : \n";
        // cout<<"i : "<<i<<" f : "<<f<<" s : "<<sec<<" curr : "<<curr<<"\n\n";


        current = s[i]-'0';
        if(current>0)
            curr += sec;
        
        next = (s[i-1]-'0')*10 + current;
        if(next >= 10 and next <= 26)
                curr += f;

        f = sec;
        sec = curr;

        // cout<<"End Loop : \n";
        // cout<<"i : "<<i<<" f : "<<f<<" s : "<<sec<<" curr : "<<curr<<"\n\n";

    }

    return sec;
    
}
};