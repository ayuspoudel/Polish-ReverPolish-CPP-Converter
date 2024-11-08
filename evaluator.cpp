#include"converter_polish.cpp"

char evaluate(char aa, char bb, char x){
    int a = aa - '0';  
    int b = bb - '0';  
    int res;
    switch(x){
        case '+':
            res = a+b;
            break;
        case '-':
            res = a-b;
            break;
        case '*':
            res = a*b;
            break;
        case '/':
            res = a/b;
            break;
    }
    if (res >= 0 && res <= 9) {
        return res + '0';
    } else {
        std::cerr << "Error: Result out of single-digit range" << std::endl;
        return '0';
    }
    return '0';
}
char evaluator(std::string s){
    std::unordered_set<char> digit = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    std::unordered_map<char, int> precedence = {
        {'+', 1}, 
        {'-', 1}, 
        {'*', 2}, 
        {'/', 2}
    };
    
    std::stack<char> st;
    for(int i = 0; i<s.length(); i++){
        char curr = s[i];
        if(digit.count(curr)){
            st.push(curr);
        }
        if(precedence.count(curr)){
            if(!st.empty()){
                char num2 = st.top();
                st.pop();
                char num1;
                if(!st.empty()){
                    num2 = st.top();
                    st.pop();
                }
                st.push(evaluate(num1, num2, curr));
            }
        }
    }
    return st.top();
}