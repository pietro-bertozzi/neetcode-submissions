class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> rpn;
        string operators = "+-/*";
        for (string t : tokens) {
            if (operators.contains(t)) {
                int a = rpn.top();
                rpn.pop();
                int b = rpn.top();
                rpn.pop();
                switch (t[0]) {
                    case '+':
                        rpn.push(b + a);
                        break;
                    case '-':
                        rpn.push(b - a);
                        break;
                    case '*':
                        rpn.push(b * a);
                        break;
                    case '/':
                        rpn.push(b / a);
                        break;
                }
            } else rpn.push(stoi(t));
        }
        return rpn.top();
    }
};
