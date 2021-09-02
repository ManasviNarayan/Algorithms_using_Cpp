#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *start = NULL;

void display()
{
    if(start == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        struct node *ptr;
        ptr = start;
        cout << endl;
        while (ptr->next != NULL)
        {
            cout << ptr->data << "-->";
            ptr = ptr->next;
        }
        cout << ptr->data << endl
             << endl;
    }
}

void insert_begin(int val)
{
    struct node *newnode = new struct node;
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = start;
    if(start != NULL)
        start->prev = newnode;
    start = newnode;
    display();
}

void insert_end(int val)
{
    if(start == NULL)
    {
        insert_begin(val);
    }
    else
    {
        struct node *newnode = new struct node;
        newnode->data = val;
        newnode->next = NULL;
        struct node *ptr;
        ptr = start;
        while(ptr->next!=NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->prev = ptr;
        display();
    }
}

void insert_after(int val, int pos)
{
    struct node *newnode = new struct node;
    newnode->data = val;
    
    struct node *ptr = start;
    while(ptr->data!= pos)
    {
        ptr = ptr->next;
    }
    newnode->next = ptr->next;
    newnode->prev = ptr;
    ptr->next->prev = newnode;
    ptr->next = newnode;

    display();
}

void insert_before(int val, int pos)
{
    struct node *newnode = new struct node;
    newnode->data = val;

    struct node *ptr = start;
    while (ptr->data != pos)
    {
        ptr = ptr->next;
    }
    newnode->next = ptr;
    newnode->prev = ptr->prev;
    ptr->prev->next = newnode;
    ptr->prev = newnode;

    display();
}

void delete_begin()
{
    if(start==NULL)
    {
        cout<<"Undeflow"<<endl;
    }
    else
    {
        struct node *ptr;
        ptr = start;
        if(start->next == NULL)
            start = NULL;
        else
        {
            start = start->next;
            start->prev = NULL;
        }
        free(ptr);
    }
    display();
}

void delete_end()
{
    if(start == NULL)
    {
        cout<<"undeflow"<<endl;
    }
    else if(start->next == NULL)
    {
        struct node *ptr = start;
        start = NULL;
        free(ptr);
    }
    else
    {
        struct node *ptr = start;
        while(ptr->next!=NULL)
        {
            ptr = ptr->next; 
        }
        ptr->prev->next=NULL;
        free(ptr);
    }
    display();
}

void delete_after(int pos)
{
    if(start == NULL)
    {
        cout<<"Underflow"<<endl;
    }
    else
    {
        struct node *ptr = start;
        while(ptr->data != pos)
        {
            ptr = ptr->next;
        }
        struct node *temp;
        temp = ptr->next;
        ptr -> next = temp->next;
        temp->next->prev = ptr;
        free(temp);
    }
    display();
}

void delete_before(int pos)
{
    if (start == NULL)
    {
        cout << "Underflow" << endl;
    }
    else
    {
        struct node *ptr = start;
        while (ptr->data != pos)
        {
            ptr = ptr->next;
        }
        struct node *temp;
        temp = ptr->prev;
        temp->prev->next = ptr;
        ptr->prev = temp->prev;
        free(temp);
    }
    display();
}

int main()
{
    cout << "\t***** Main Menu *****" << endl;
    cout << "\t1. insert begin" << endl;
    cout << "\t2. insert end" << endl;
    cout << "\t3. insert after" << endl;
    cout << "\t4. insert before" << endl;
    cout << "\t5. delete begin" << endl;
    cout << "\t6. delete end" << endl;
    cout << "\t7. delete after" << endl;
    cout << "\t8. delete before" << endl;
    cout << "\t9. display" << endl;
    cout << "\t10. exit" << endl;

    int n, x, p, pos;

    while (1)
    {
        cout << "enter choice: ";
        cin >> n;
        switch (n)
        {

        case 1:
            cout<<"INSERT AT BEGINNING"<<endl;
            cout << "Enter value to insert: ";
            cin >> x;
            insert_begin(x);
            break;

        case 2:
            cout << "INSERT AT END" << endl;
            cout << "Enter value to insert: ";
            cin >> x;
            insert_end(x);
            break;

        case 3:
            cout << "INSERT AFTER VALUE " << endl;
            cout << "Enter value to insert: ";
            cin >> x;
            cout << "Enter value after which to insert: ";
            cin >> p;
            insert_after(x, p);
            break;

        case 4:
            cout << "INSERT BEFORE VALUE " << endl;
            cout << "Enter value to insert: ";
            cin >> x;
            cout << "Enter value before which to insert: ";
            cin >> p;
            insert_before(x, p);
            break;

        case 5:
            cout << "DELETE FROM BEGINNING " << endl;
            delete_begin();
            break;

        case 6:
            cout << "DELETE FROM END " << endl;
            delete_end();
            break;

        case 7:
            cout << "DELETE AFTER VALUE" << endl;
            cout << "Enter value after which to delete: ";
            cin >> p;
            delete_after(p);
            break;

        case 8:
            cout << "DELETE BEFORE VALUE" << endl;
            cout << "Enter value before which to delete: ";
            cin >> p;
            delete_before(p);
            break;

        case 9:
            cout << "DISPLAY" << endl;
            display();
            break;

        case 10:
            exit(0);

        default:
            cout << "invalid entry" << endl;
            break;
        }
    }
    return 0;
}