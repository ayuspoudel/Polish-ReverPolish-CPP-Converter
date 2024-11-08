#include"converter_polish.cpp"
#include"evaluator.cpp"
int main() {
    std::string expression;
    std::cout << "Enter an infix expression: ";
    std::cin >> expression;

    std::string result = postfix_converter(expression);
    std::cout << "Postfix Expression: " << result << std::endl;
    char result1 = evaluator(result);
    std::cout << "Evaluated Expression: " << result1 << std::endl;
    return 0;
}