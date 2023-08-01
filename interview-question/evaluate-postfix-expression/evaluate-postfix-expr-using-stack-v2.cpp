#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    while (true)
    {
        string postfixExpr{};
        cout << "Enter postfix expression : ";
        cin >> postfixExpr;
        stack<int> stackPostfix{};
        bool invalidPostfixExpr = false;

        for (unsigned i = 0; i < postfixExpr.length(); ++i)
        {
            char ch = postfixExpr[i];
            if (isdigit(ch))
            {
                stackPostfix.push(ch - '0');
            }
            else
            {
                if (stackPostfix.size() >= 2)
                {
                    int op1 = stackPostfix.top();
                    stackPostfix.pop();
                    int op2 = stackPostfix.top();
                    stackPostfix.pop();
                    int temp{};
                    switch (ch)
                    {
                    case '+':
                        temp = op2 + op1;
                        break;
                    case '-':
                        temp = op2 - op1;
                        break;
                    case '*':
                        temp = op2 * op1;
                        break;
                    case '/':
                        temp = op2 / op1;
                        break;
                    default:
                        invalidPostfixExpr = true;
                        break;
                    }
                    stackPostfix.push(temp);
                }
                else
                {
                    invalidPostfixExpr = true;
                    break;
                }
            }
        }

        if ((!invalidPostfixExpr) && (stackPostfix.size()==1))
        {
            cout << stackPostfix.top() << endl;
            stackPostfix.pop();
        }
        else
        {
            cout << "Invalid postfix expression!\n";
        }
    }

    return EXIT_SUCCESS;
}