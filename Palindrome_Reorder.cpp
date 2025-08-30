#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int cnt[26]{};
    for (char c : s)
        cnt[c - 'A']++;
    int odd = 0, mid = -1;

    // If more than one character has an odd count, a palindrome cannot be formed
    if (odd > 1)
    {
        cout << "NO SOLUTION";
        return 0;
    }

    string half = "";
    // Construct the first half of the palindrome
    for (int i = 0; i < 26; ++i)
    {
        half += string(cnt[i] / 2, 'A' + i);
    }
    cout << half;
    // middle character if exists
    if (mid != -1)
    {
        char middleChar = 'A' + mid;
        int middleCount = cnt[mid]; // guaranteed to be odd if mid != -1
        cout << string(middleCount, middleChar);
    }
    // Append the reverse of half to complete the palindrome
    reverse(half.begin(), half.end());
    cout << half;
}
