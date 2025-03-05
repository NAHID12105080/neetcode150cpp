#include <iostream>
#include <cctype> // For isalnum()

int main() {
    char ch1 = 'A';
    char ch2 = '#';

    if (isalnum(ch1))
        std::cout << ch1 << " is alphanumeric.\n";
    else
        std::cout << ch1 << " is not alphanumeric.\n";

    if (isalnum(ch2))
        std::cout << ch2 << " is alphanumeric.\n";
    else
        std::cout << ch2 << " is not alphanumeric.\n";

    return 0;
}
