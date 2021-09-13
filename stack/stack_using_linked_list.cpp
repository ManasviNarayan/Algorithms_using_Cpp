#include<bits/stdc++.h>
using namespace std;

struct node 
{
    int data;
    struct node *next;
};

struct stacks
{
    struct node *top;
};

void initialize(struct stacks *stack)
{
    stack->top = NULL;
}

void push(int val, struct stacks *stack)
{
    struct node *newnode = new struct node;
    newnode->data = val;

    newnode->next = stack->top;
    stack->top = newnode;

}

void pop(struct stacks * stack)
{
    if(stack->top == NULL)
    {
        cout<<"Stack is empty! Cannot pop"<<endl;
    }
    else
    {
        struct node *ptr;
        ptr = stack->top;
        stack->top = stack->top->next;
        cout<<ptr->data<<" has been removed"<<endl;
        free(ptr);
    }
}

void peek(struct stacks *stack)
{
    cout<<stack->top->data<<endl;
}

void display(struct stacks *stack)
{
    struct node *ptr;
    ptr = stack->top;

    cout<<"TOP->";
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}

int main()
{
    struct stacks *stack1 = new struct stacks;
    initialize(stack1);
    cout << "\t***** Main Menu *****" << endl;
    cout << "\t1. Push" << endl;
    cout << "\t2. Pop" << endl;
    cout << "\t3. Peek" << endl;
    cout << "\t4. Display"<<endl;
    cout << "\t5. Exit" << endl;

    while (1)
    {
        int n, val;
        cout << "\nEnter choice: ";
        cin >> n;

        switch (n)
        {
        case 1:
            cout << "PUSH" << endl;
            cout << "Enter value to push: ";
            cin >> val;
            push(val, stack1);
            break;

        case 2:
            cout << "PUSH" << endl;
            pop(stack1);
            break;

        case 3:
            cout << "PEEK" << endl;
            peek(stack1);
            break;

        case 4:
            cout<<"DISPLAY"<<endl;
            display(stack1);
            break;

        case 5:
            exit(0);

        default:
            cout << "Invalid entry" << endl;
        }
    }

    return 0;
}