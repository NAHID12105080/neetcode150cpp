```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {//u have not found num-1 in numSet
                int length = 1;

                while (numSet.find(num + length) != numSet.end()) {
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};
```

```cpp
s.find(current_element) != s.end()
```

- True: If current_element is found in the set (because the iterator is not equal to s.end()).
- False: If current_element is not found in the set (because the iterator equals s.end()).
