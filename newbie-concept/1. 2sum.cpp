#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; 
    }
};

int main(){
    return 0;
}
// --------
// Qusetion: Why does the code return {i, j} instead of std::make_pair(i, j) or std::vector<int>({i, j})?

// The return {i, j}; in the code is valid because of C++'s brace-enclosed initializer lists, which allow direct initialization of containers such as std::vector.

// Detailed Explanation
// std::vector<int> Return Type:

// The function twoSum has a return type of std::vector<int>.
// std::vector<int> can be constructed from a brace-enclosed list of integers, e.g., {i, j}.
// Brace-Enclosed Initializer List:

// The syntax {i, j} is interpreted as an initializer list.
// It creates a std::vector<int> with two elements: i and j.
// This works because std::vector has a constructor that accepts an std::initializer_list.
// No Need for Explicit Construction:

// You don't need to write std::vector<int>({i, j}) explicitly.
// The compiler automatically constructs a std::vector<int> from {i, j} because the return type is already declared as std::vector<int>.

// Question:Why Doesn't It Return a std::pair?
// The code doesn't return a std::pair because:
// The function explicitly specifies the return type as std::vector<int>, not std::pair<int, int>.
// {i, j} matches the constructor of std::vector<int>, not std::pair.
// If you want to return a std::pair, you'd have to change the return type to std::pair<int, int> and use:

// return std::make_pair(i, j);
// --------

// 2# Qusetion: What is the std::initializer_list class template in C++?

// Key Points about std::initializer_list
// What is std::initializer_list?

// It is a standard library class template that represents a fixed-size array of objects.
// It allows objects to be initialized using a {} syntax.
// Example:

// std::initializer_list<int> list = {1, 2, 3};
// Constructors Supporting Initializer Lists:

// Many STL containers (like std::vector, std::set, etc.) have constructors that accept std::initializer_list as an argument.
// Example:

// std::vector<int> v = {1, 2, 3}; /