// Problem Link : https://leetcode.com/problems/design-circular-queue/

class MyCircularQueue {
public:
    
    vector<int> v;
    int front,rear;
    MyCircularQueue(int k) {
        
        // create a new vector with size k and intialise v with it
        
        vector<int> newVector(k);
        v = newVector;
        front=-1, rear=0;
    }
    
    bool enQueue(int value) {
        if(rear==v.size())
            return false;
        v[rear]=value;
        rear++;
        front = front == -1 ? 0 : front;
        return true;
    }
    
    bool deQueue() {
        if(front==-1 or rear==0)
            return false;
        for(int i=0; i<rear-1; i++)
        {
            v[i] = v[i+1];
        }
        rear--;
        return true;
        
    }
    
    int Front() {
        
        if(front==-1 or rear==0)
            return -1;
        else
            return v[0];
        
    }
    
    int Rear() {
        
        if(rear==0)
            return -1;
        else
            return v[rear-1];
        
    }
    
    bool isEmpty() {
        
        if(rear==0)
            return true;
        return false;
        
    }
    
    bool isFull() {
        if(rear==v.size())
            return true;
        return false;
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */