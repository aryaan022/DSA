class MedianFinder {
public:

    priority_queue<int>pq; //max heap
    priority_queue<int  ,vector<int> ,greater<>>pq_right; // min heap
    MedianFinder() {
        
    }

    
    void addNum(int num) {
        if(pq.empty() || num<=pq.top()){
            pq.push(num);
        }
        else{
            pq_right.push(num);
        }
        

        //balancing both the side
        if(pq.size()>pq_right.size()+1){
            pq_right.push(pq.top());
            pq.pop();
        }
        else if(pq.size()<pq_right.size()){
            pq.push(pq_right.top());
            pq_right.pop();
        }
    }
    
    double findMedian() {
        if(pq.size()==pq_right.size()){
            return (pq.top()+pq_right.top()) / 2.0;
        }
        return pq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */