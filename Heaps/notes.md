# 🚀 Priority Queue and Heaps in C++ for Competitive Programming

## Introduction

- **Priority Queue**: A data structure that stores elements such that the highest (or lowest) priority element is accessible in constant time.
- **Heap**: A specialized binary tree-based structure satisfying the heap property:
  - **Max-Heap**: Parent node ≥ child nodes.
  - **Min-Heap**: Parent node ≤ child nodes.

---

## Priority Queue in C++ STL

### Syntax

```cpp
#include <queue>

// Max-Heap
std::priority_queue<int> pq;

// Min-Heap
std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
```
