#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <string>

// Define the postfix_converter function
std::string postfix_converter(const std::string& s) {
    std::unordered_map<char, int> precedence = {
        {'+', 1}, 
        {'-', 1}, 
        {'*', 2}, 
        {'/', 2}
    };

    std::unordered_map<char, char> opening = {
        {'(', ')'},
        {'{', '}'},
        {'[', ']'}
    };

    std::unordered_map<char, char> closing = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    std::unordered_set<char> digit = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};

    std::stack<char> st;
    std::string postfix = "";

    for (char curr : s) {
        if (opening.count(curr)) {  // If it's an opening parenthesis
            st.push(curr);
        }
        else if (digit.count(curr)) {  // If it's a digit
            postfix += curr;
        }
        else if (precedence.count(curr)) {  // If it's an operator
            while (!st.empty() && precedence.count(st.top()) && precedence[st.top()] >= precedence[curr]) {
                postfix += st.top();
                st.pop();
            }
            st.push(curr);
        }
        else if (closing.count(curr)) {  // If it's a closing parenthesis
            while (!st.empty() && st.top() != closing[curr]) {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop();  // Pop the matching opening parenthesis
            } else {
                return "Invalid";  // Unmatched closing bracket
            }
        }
    }

    // Pop all remaining operators in the stack
    while (!st.empty()) {
        if (opening.count(st.top())) {
            return "Invalid";  // Unmatched opening bracket
        }
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    std::string expression;
    std::cout << "Enter an infix expression: ";
    std::cin >> expression;

    std::string result = postfix_converter(expression);
    std::cout << "Postfix Expression: " << result << std::endl;

    return 0;
}
