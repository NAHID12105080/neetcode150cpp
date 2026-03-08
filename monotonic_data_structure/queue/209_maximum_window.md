## The key insight is:
- Keep the deque monotonic decreasing (values in decreasing order).
- The front of the deque always contains the maximum of the current window.

# Approach 🔍
- Iterate through the array `indices i`.
- Remove indices from the front if they are out of the current window `(i - k)`.
- Remove indices from the back if their corresponding values are smaller than the current value `nums[i]` (since they can never be max again).
- Push the current `index i` into the deque.
- Once we’ve processed at least k elements, the front of the deque is the max for this window, so push `nums[dq.front()]` into the result.

## Complexity 📊
### Time complexity: (O(n))
- Each element is pushed and popped from the deque at most once.
### Space complexity: (O(k)) for the deque.




```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq; //double ended queue

        for (int i = 0; i < n; i++) {
            // Remove `indices` outside the window
            if (!dq.empty() && dq.front() <= i - k) 
                dq.pop_front();

            // Maintain decreasing order in deque
            while (!dq.empty() && nums[dq.back()] <= nums[i]) 
                dq.pop_back();

            dq.push_back(i);

            // Add maximum for the current window
            if (i >= k - 1) 
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
}; 
```