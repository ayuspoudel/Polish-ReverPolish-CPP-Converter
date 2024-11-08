#include"converter_polish.cpp"
int main() {
    std::string expression;
    std::cout << "Enter an infix expression: ";
    std::cin >> expression;

    std::string result = postfix_converter(expression);
    std::cout << "Postfix Expression: " << result << std::endl;

    return 0;
}