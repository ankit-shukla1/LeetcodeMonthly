// Problem Link : https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
public:
    
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        // get the size of both heaps
        
        int size1 = pq1.size();
        int size2 = pq2.size();
        
        // for empty cases
        if(size1 == 0)
            pq1.push(num);
                
        else if(size1 > size2)
        {
            if( num < pq1.top() )
            {
                int a = pq1.top();
                pq1.pop();
                pq1.push(num);
                pq2.push(a);
            }
            else
            {
                pq2.push(num);                
            }
        }
        
        else
        {
            if( num > pq2.top() )
            {
                int a = pq2.top();
                pq2.pop();
                pq2.push(num);
                pq1.push(a);
            }
            else
            {
                pq1.push(num);
            }
        }
        
        
    }
    
    double findMedian() {
        
        int size1 = pq1.size();
        int size2 = pq2.size();
        
        int totalSize = size1 + size2;
        
        // cout<<totalSize<<" "<<pq1.top()<<"\n";
        
        if( totalSize%2 == 0)
        {
            int a = pq1.top();
            int b = pq2.top();
            
            return ((double)(a+b))/2;
        }
        else
        {
            return (double)(pq1.top());
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */