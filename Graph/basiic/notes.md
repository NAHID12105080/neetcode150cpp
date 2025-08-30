# to traverse in 8 directions

```cpp
vector<vector<int>> directions = {
{1, 0}, // down
{-1, 0}, // up
{0, 1}, // right
{0, -1}, // left
{1, 1}, // down-right
{1, -1}, // down-left
{-1, 1}, // up-right
{-1, -1} // up-left
};
```

```cpp
for (auto& dir : directions) {
int nrow = r + dir[0];
int ncol = c + dir[1];
// ... boundary checks, visit logic, etc.
}
```
