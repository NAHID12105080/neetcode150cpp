# 🚀 Binary Search, Upper Bound, and Lower Bound – The Ultimate CP Guide

## 🔥 Binary Search:

- a divide-and-conquer technique
- used to efficiently find an element in a `sorted array`
- O(log N) time.

## 📌 Standard Binary Search Template

Finds the first occurrence of target in arr:

```cpp
int binary_search(vector<int>& arr, int target) {
    int lo = 0, hi = arr.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;  // Avoid overflow
        if (arr[mid] == target) return mid;  // Found
        else if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;  // Not found
}
```

## 🎯 Lower Bound (std::lower_bound)

Finds the `first index` where arr[i] >= target.
If target exists, it returns the first occurrence.
If target doesn’t exist, it returns where it should be inserted.
Complexity: O(log N)
📌 Implementation (C++ STL)

```cpp
int lb = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
```

## 🏹 Manual Implementation

```cpp
int lower_bound(vector<int>& arr, int target) {
    int lo = 0, hi = arr.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] < target) lo = mid + 1;
        else hi = mid;
    }
    return lo;  // Index where `target` should be
}
```

### 🔥 Pro Tip:

If arr[lb] == target, target exists.
If lb == arr.size(), target is greater than all elements.

---

### 🎯 Upper Bound (std::upper_bound)

Finds the first index where arr[i] > target.
Always returns the index of the next greater element.
If target is the largest, returns arr.size().
Complexity: O(log N)
📌 Implementation (C++ STL)

```cpp
int ub = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
```

### 🏹 Manual Implementation

```cpp
int upper_bound(vector<int>& arr, int target) {
    int lo = 0, hi = arr.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] <= target) lo = mid + 1;
        else hi = mid;
    }
    return lo;  // Index of the first element greater than `target`
}

```

### ⚔ Binary Search Variations in CP

| **Problem Type**      | **Use Case**       | **Function**        |
| --------------------- | ------------------ | ------------------- |
| Find first occurrence | `arr[i] == target` | `lower_bound()`     |
| Find last occurrence  | `arr[i] == target` | `upper_bound() - 1` |
| Count occurrences     | Count of `target`  | `ub - lb`           |
| Insert position       | `arr[i] >= target` | `lower_bound()`     |
| Next greater element  | `arr[i] > target`  | `upper_bound()`     |

### 🔥 Pro Tip:

If ub - lb == 0, target does not exist in arr.
ub - lb gives the frequency of target in arr.

### 🏆 Competitive Programming Hacks

Avoid overflow in mid calculation:

```cpp
int mid = lo + (hi - lo) / 2;  // Safe mid calculation
```

When searching for double values, use eps:

```cpp
while (hi - lo > 1e-9) { ... }  // Precision binary search
```

Use std::binary_search() if only checking existence:

```cpp
bool exists = binary_search(arr.begin(), arr.end(), target);
```

### Binary Search on Answer (When the array is not given):

Used in problems like minimum days, max speed, or smallest valid value.
Example:

- Find the minimum x such that f(x) == true.

```cpp
while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (isValid(mid)) hi = mid;
    else lo = mid + 1;
}
```
