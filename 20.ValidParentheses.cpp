#include <vector>
#include <string>

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{') {
                stack.push_back(c);
            }
            else {
                if (stack.empty()) return false;
                char top = stack.back();
                if ((c == ')' && top == '(') ||
                    (c == ']' && top == '[') ||
                    (c == '}' && top == '{')) {
                    stack.pop_back();
                }
                else {
                    return false;
                }
            }
        }
        return stack.empty();
    }
};