#include <iostream>
#include <string>
#include <algorithm>

std::string addNumber(const std::string& s1, const std::string& s2) {
    for (const char c : s1) {
        if (!std::isdigit(c)) return "0";
    }
    for (const char c : s2) {
        if (!std::isdigit(c)) return "0";
    }

    std::string result = "";
    int i = s1.length() - 1;
    int j = s2.length() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry > 0) {
        const int digit1 = (i >= 0) ? s1[i] - '0' : 0;
        const int digit2 = (j >= 0) ? s2[j] - '0' : 0;

        const int sum = digit1 + digit2 + carry;
        result += std::to_string(sum % 10);
        carry = sum / 10;

        i--;
        j--;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    std::string n1, n2;
    std::cin >> n1 >> n2;
    std::cout << "The sum of " << n1 << " and " << n2 << " is "
            << addNumber(n1, n2) << std::endl;
    return 0;
}
