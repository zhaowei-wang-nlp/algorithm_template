class MyCircularQueue {
private:
    int n;
    int *q = NULL;
    int tt = 0, hh = 0;
public:
    MyCircularQueue(int k) {
        this->n = k + 1;
        this->q = new int[this->n];
    }
    
    bool enQueue(int value) {
        if((tt + 1)%this->n == hh)
            return false;
        this->q[tt] = value;
        tt ++;
        if(tt == this->n)
            tt = 0;
        return true;
    }
    
    bool deQueue() {
        if(tt == hh)
            return false;
        hh ++;
        if(hh == this->n)
            hh = 0;
        return true;
    }
    
    int Front() {
        if(tt == hh)
            return -1;
        return this->q[hh];
    }
    
    int Rear() {
        if(tt == hh)
            return -1;
        int idx;
        if(tt > 0)
            idx = tt - 1;
        else
            idx = this->n - 1;
        return this->q[idx];
    }
    
    bool isEmpty() {
        if(tt == hh)
            return true;
        else
            return false;
    }
    
    bool isFull() {
        if((tt + 1) % this->n == hh)
            return true;
        else
            return false;
    }
};