#include <iostream>
#include <string>
#include <stack>
using namespace std;

int evaluate(int op1, int op2, const char& op)
{
    int temp{};
    switch (op)
    {
    case '+': 
        temp = op1 + op2;
        return temp;
        break;
    case '-': 
        temp = op1 - op2;
        return temp;
        break;
    case '*': 
        temp = op1 * op2;
        return temp;
        break;
    case '/': 
        temp = op1 / op2;
        return temp;
        break;
    default:
        cout <<"Grrr! I quit.\n";
        exit ( EXIT_FAILURE );
    }
}

int chToInt(char ch)
{
    return int(ch-'0');
}

int main()
{
    const string operators{"+-*/"}; 
    while(true)
    {
        string postfixExpr{};
        cout << "Enter postfix expression : ";
        cin >> postfixExpr;
        stack<int> stackPostfix{};
        string::iterator strIt = postfixExpr.begin();
        char ch = *strIt;
        bool invalidPostfixExpr = false;

        while(strIt != postfixExpr.end() )
        {
            ch = *strIt;
            size_t found = operators.find(ch);
            if( isdigit(ch) )
            {
                int i = chToInt(ch);
                stackPostfix.push(i);
            }
            else if( found != string::npos )
            {
                if( stackPostfix.size() >= 2 )
                {
                    int op1 = stackPostfix.top();
                    stackPostfix.pop();
                    int op2 = stackPostfix.top();
                    stackPostfix.pop();
                    stackPostfix.push( evaluate(op2, op1, ch) );
                }
                else
                {
                    invalidPostfixExpr = true;
                    break;
                }
            }
            else
            {
                cout <<" Phew! I quit.\n";
                return EXIT_FAILURE;
            }
            ++strIt;
        }

        if( stackPostfix.size() == 0 || stackPostfix.size() > 1 || invalidPostfixExpr )
        {
            cout << "invalid postfix expression!\n";
        }
        else
        {
            cout << stackPostfix.top() << endl;
            stackPostfix.pop();
        }
    }
    return EXIT_SUCCESS;
}