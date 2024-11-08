#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <string>
#include <cstdlib>


std::string postfix_converter(std::string s){
        std::unordered_map<char, int> precedence = {{'+', 1}, 
                                                    {'-', 1}, 
                                                    {'*', 2},
                                                    {'/', 2}};

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

        std::unordered_set<char> digit = {'1', '2', '3', '4',
                                            '5', '6', '7', '8',
                                            '9', '0'};
        std::stack<char> st;
        std::string postfix = "";
        int j = 0;
        for(int i = 0;i<s.length(); i++){
            char curr = s[i];
            if(opening.count(curr)){ //if opening parenthesis
                st.push(curr);
            }
            else if(digit.count(curr)){   //if number
                postfix[j++] = curr;
            }
            else if(precedence.count(curr)){    //if operator
                while(!st.empty() && precedence[st.top()]>=precedence[curr]){
                    postfix[j++] = st.top();
                    st.pop();
                }
                st.push(curr);
            }
            else if(closing.count(curr)){
                while(!st.empty() && st.top() == closing[curr]){
                    postfix[j++] = st.top();
                    st.pop();
                }
                if(!st.empty()){
                    if(!opening.count(st.top()))
                        return "Invalid";
                    } else{st.pop();}
            }
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
