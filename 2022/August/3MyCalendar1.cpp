// Problem Link : https://leetcode.com/problems/my-calendar-i/

class MyCalendar
{
public:
    unordered_map<int, int> um;
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {

        for (auto x : um)
        {
            if ((end > x.first and end <= x.second) or (start >= x.first and start < x.second) or (start <= x.first and end > x.second))
            {
                return false;
            }
        }
        um[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */