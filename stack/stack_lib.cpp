#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> stack1;

    cout<<"\t***** Main Menu *****"<<endl;
    cout<<"\t1. Push"<<endl;
    cout<<"\t2. Pop"<<endl;
    cout<<"\t3. Peek"<<endl;
    cout<<"\t4. Exit"<<endl;
    
    while(1)
    {
        int n, val;
        cout<<"\nEnter choice: ";
        cin>>n;

        switch(n)
        {
            case 1:
                cout<<"PUSH"<<endl;
                cout<<"Enter value to push: ";
                cin>>val;
                stack1.push(val);
                break;
            
            case 2:
                cout<<"POP"<<endl;
                if(stack1.empty())
                {
                    cout<<"Stack is empty"<<endl;
                }
                else
                {
                    cout<<stack1.top()<<" has been removed"<<endl;
                    stack1.pop();
                }
               
                break;

            case 3:
                cout<<"PEEK"<<endl;
                val = stack1.top();
                cout<<val<<endl;
                break;

            case 4:
                exit(0);

            default:
                cout<<"Invalid entry"<<endl;
        }
    }

    return 0;
}