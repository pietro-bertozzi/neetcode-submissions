class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> rpn;
        string operators = "+-/*";
        for (string t : tokens) {
            if (operators.contains(t)) {
                int a = stoi(rpn.top());
                rpn.pop();
                int b = stoi(rpn.top());
                rpn.pop();
                switch (t[0]) {
                    case '+':
                        rpn.push(to_string(b + a));
                        break;
                    case '-':
                        rpn.push(to_string(b - a));
                        break;
                    case '*':
                        rpn.push(to_string(b * a));
                        break;
                    case '/':
                        rpn.push(to_string(b / a));
                        break;
                }
            } else rpn.push(t);
        }
        return stoi(rpn.top());
    }
};
