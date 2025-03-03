## 📄 2D Vector in C++ Notes

### 1. Basic Declaration

```cpp
vector<vector<int>> grid(m, vector<int>(n));
```

- `m` → Number of rows
- `n` → Number of columns
- Each element is initialized to **0** by default.

### 2. Example Code

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> grid(3, vector<int>(4)); // 3 rows, 4 columns initialized with 0

    cout << "Rows: " << grid.size() << endl;        // Output: 3
    cout << "Columns: " << grid[0].size() << endl;  // Output: 4

    // Printing the grid
    for(int i=0; i<grid.size(); i++) {
        for(int j=0; j<grid[i].size(); j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```

#### Output:

```
Rows: 3
Columns: 4
0 0 0 0
0 0 0 0
0 0 0 0
```

### 3. Initialization with Custom Value

If you want to initialize the grid with a value other than `0`, use:

```cpp
vector<vector<int>> grid(m, vector<int>(n, -1));
```

This will fill the entire grid with **-1**.

### 4. How to Access Elements

- `grid.size()` → Number of Rows
- `grid[i].size()` → Number of Columns in Row `i`

### 🔥 Bonus Tip:

You can iterate through a 2D vector easily using **range-based for loops**:

```cpp
for (auto row : grid) {
    for (auto cell : row) {
        cout << cell << " ";
    }
    cout << endl;
}
```
