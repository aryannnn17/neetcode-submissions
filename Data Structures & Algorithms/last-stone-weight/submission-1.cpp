class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        // priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int n : stones) maxHeap.push(n);

        while (maxHeap.size() > 1) {
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();
            if (x > y) maxHeap.push(x - y);
        }
        return (maxHeap.empty()) ? 0 : maxHeap.top();
    }
};
