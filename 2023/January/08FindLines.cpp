// Problem Link : https://leetcode.com/problems/max-points-on-a-line/description/


class Solution {
public:
    int gcd(int val1, int val2)
    {
        if(val1 == 0)
            return val2;
        if(val2 == 0)
            return val1;
        
        int m1 = max(val1, val2);
        int m2 = min(val1, val2);
        
        if(m1%m2 == 0)
            return m2;
        return gcd(m1%m2, m2);

        }
    void standardize(int &num, int &den)
    {
        if(num==0)
            den=1;
        if(den==0)
            num=1;
        else if( (num<0 and den<0) || den<0)
        {
            num *= -1;
            den *= -1;
        }
    }
    int maxPoints(vector<vector<int>>& points) {
        
        int ans = 1;
        
        map<pair<int, int>, int> m;
        
        for(int i=0; i<points.size(); i++)
        {
            int olp=0, maxm=0;
            
            for(int j = i+1; j<points.size(); j++)
            {
                if( points[i][0] == points[j][0] and points[i][1] == points[j][1])
                    olp++;
                else
                {
                    int xdiff = points[j][0] - points[i][0];
                    int ydiff = points[j][1] - points[i][1];
                    
                    int g = gcd(abs(xdiff), abs(ydiff));
                    
                    int f = xdiff/g;
                    int s = ydiff/g;
                    
                    standardize(f,s);
                    
                    if(m.find({f,s}) != m.end())
                        m[{f,s}]++;
                    else
                        m[{f,s}]=1;
                    maxm = max(maxm, m[{f,s}]);
                }
            }
            
            ans = max(ans, 1+olp+maxm);
            m.clear();
        }
        
        return ans;
        
    }
};

