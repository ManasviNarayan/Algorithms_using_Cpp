#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct que
{
    struct node *front, *rear;
};


void initialize(struct que *queue)
{
    queue->front = NULL;
    queue->rear = NULL;
}

void insert(int val, struct que *que)
{
    struct node *newnode = new struct node;
    newnode->data = val;

    if(que->front == NULL)
    {
        que->front = que->rear = newnode;
        que->front->next = que->rear->next = NULL;
    }
    else
    {
        que->rear->next = newnode;
        que->rear = newnode;
        que->rear->next = NULL;
    }
}

void del(struct que *que)
{
    if(que->front == NULL)
    {
        cout<<"Underflow"<<endl;
    }
    else
    {
        struct node *ptr;
        ptr = que->front;
        que->front = que->front->next;
        cout<<ptr->data<<" has been removed"<<endl;
        free(ptr);
    }
}

void display(struct que *que)
{
    if(que->front==NULL)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        struct node *ptr;
        ptr= que->front;
        cout<<"FRONT -> ";
        while(ptr->next!=NULL)
        {
            cout<<ptr->data<<" -> ";
            ptr = ptr->next;
        }
        cout<<ptr->data<<endl;
    }
}

int main()
{
    cout << "\t***** Main Menu *****" << endl;
    cout << "\t1. Insert" << endl;
    cout << "\t2. Delete" << endl;
    cout << "\t3. Display" << endl;
    cout << "\t4. Exit" << endl;

    struct que *queue1 = new struct que;
    initialize(queue1);

    while (1)
    {
        int n, val;
        cout << "\nEnter choice: ";
        cin >> n;

        switch (n)
        {
        case 1:
            cout << "Insert" << endl;
            cout << "Enter value to push: ";
            cin >> val;
            insert(val, queue1);
            break;

        case 2:
            cout << "Delete" << endl;
            del(queue1);
            break;

        case 3:
            cout << "Display" << endl;
            display(queue1);
            break;

        case 4:
            exit(0);

        default:
            cout << "Invalid entry" << endl;
        }
    }

    return 0;
}