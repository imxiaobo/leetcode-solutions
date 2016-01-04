class MedianFinder {

  priority_queue<int, std::vector<int>, less<int>> maxHeap;
  priority_queue<int, std::vector<int>, greater<int>> minHeap;

public:
  // Adds a number into the data structure.
  void addNum(int num) {
    if (maxHeap.empty() || num < maxHeap.top())
      maxHeap.push(num);
    else
      minHeap.push(num);

    if (maxHeap.size() > minHeap.size() + 1) {
      minHeap.push(maxHeap.top());
      maxHeap.pop();
    } else if (minHeap.size() > maxHeap.size() + 1) {
      maxHeap.push(minHeap.top());
      minHeap.pop();
    }
  }

  // Returns the median of current data stream
  double findMedian() {
    if (maxHeap.empty() && minHeap.empty())
      return 0;
    if (maxHeap.size() > minHeap.size())
      return maxHeap.top();
    if (minHeap.size() > maxHeap.size())
      return minHeap.top();
    return ((double)maxHeap.top() + (double)minHeap.top()) / 2.0;
  }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
