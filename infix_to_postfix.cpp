#include<bits/stdc++.h>
using namespace std;

int precedence(char x)
{
    if(x == '^')
        return 3;
    else if (x == '*' || x=='/')
        return 2;
    else if (x=='+' || x=='-')
        return 1;
    else
        return -1;
}

void infix_to_postfix(string a)
{
    stack<char> op;
    string output = "";
    int i, len=a.length();
    for(i=0;i<len;i++)
    {
        char x = a[i];

        if((x>='a' && x<='z') || (x>='A' && x<='Z') || (x>='0' && x<='9'))
        {
            output = output+x;
        }
        else if(x=='(')
        {
            op.push('(');
        }
        else if (x==')')
        {
            while (op.top() != '(')
            {
                output = output+op.top();
                op.pop();
            }
            op.pop();
        }
        else
        {
            while(!op.empty() && precedence(x)<=precedence(op.top()))
            {
                output += op.top();
                op.pop();
            }
            op.push(x);
        }
    }

    while(!op.empty())
    {
        output+= op.top();
        op.pop();
    }

    cout<<"Postfix expression:\n\t"<<output;
}

int main()
{
    string infix;
    cout<<"Enter an infix expression(No Sopaces): "<<endl;
    cin>>infix;

    infix_to_postfix(infix);
}