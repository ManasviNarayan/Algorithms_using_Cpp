#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

void display()
{
    struct node *ptr = start;
    if (start == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        while (ptr->next != start)
        {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        cout << ptr->data << endl;
    }
}

void insert_begin(int val)
{
    struct node *newnode = new struct node;
    newnode->data = val;
    if(start==NULL)
    {
        start = newnode;
        newnode->next = start;
    }
    else
    {
        struct node *ptr = start;
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        newnode->next = start;
        ptr->next = newnode;
        start = newnode;
    }
    display();
}

void insert_end(int val)
{
    struct node *newnode = new struct node;
    newnode->data = val;
    newnode->next = start;
    if (start == NULL)
    {
        start = newnode;
        newnode->next = start;
    }
    else
    {
        struct node *ptr = start;
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
    display();
}

void delete_first()
{
    if(start==NULL)
    {
        cout<<"Underflow"<<endl;
        return;
    }
    struct node *ptr = start;
    while(ptr->next!=start)
    {
        ptr = ptr->next;
    }
    ptr->next = start->next;
    free(start);
    start= ptr->next;
    display();
}

void delete_last()
{
    if (start == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }

    struct node *ptr = start;
    struct node *preptr = ptr;
    
    while(ptr->next!=start)
    {
        preptr=ptr;
        ptr = ptr->next;
    }
    preptr->next=start;
    free(ptr);
    display();
}



int main()
{
    cout << "\t***** Main Menu *****" << endl;
    cout << "\t1. insert begin" << endl;
    cout << "\t2. insert end" << endl;
    cout << "\t3. delete begin" << endl;
    cout << "\t4. delete end" << endl;
    cout << "\t5. display" << endl;
    cout << "\t6. exit" << endl;


    while (1)
    {
        cout << "enter choice: ";
        int n, x;
        cin >> n;


        switch (n)
        {
        case 1:
            cout<<"Insert begin"<<endl;
            cout << "Enter value to insert: ";
            cin >> x;
            insert_begin(x);
            break;

        case 2:
            cout << "Insert end" << endl;
            cout << "Enter value to insert: ";
            cin >> x;
            insert_end(x);
            break;

        case 3:
            cout << "Delete First" << endl;
            delete_first();
            break;

        case 4:
            cout << "Delete Last" << endl;
            delete_last();
            break;

        case 5:
            display();
            break;

        case 6:
            exit(0);

        default:
            cout << "invalid entry" << endl;
            break;
        }
    }
    return 0;
}