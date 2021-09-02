#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;

void display()
{
    if (start==NULL)
    {
        cout<<"List is empty"<<endl;
    }
    else
    {
        struct node *ptr;
        ptr = start;
        cout<<endl;
        while(ptr->next != NULL)
        {
            cout<<ptr->data<<"-->";
            ptr = ptr->next;
        }
        cout<<ptr->data<<endl<<endl;
    }
}

int search(int val)
{
    struct node *ptr;
    ptr = start;
    int count = 1;
    while(ptr!=NULL)
    {
        if (val == ptr->data)
        {
            return (count);
        }
        else
        {
            ptr = ptr->next;
        }
        count++;
    }
    return (-1);
}

void insert_begin(int val)
{
    struct node *newnode = new struct node;
    newnode->data = val;
    
    newnode->next = start;
    start=newnode;
    display();
}

void insert_end(int val)
{
    if(start==NULL)
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
        display();
    }
    
}

void insert_after(int val, int pos)
{
    struct node *newnode = new struct node;
    newnode->data = val;

    struct node *ptr, *preptr;
    ptr = start;
    preptr = ptr;

    while(preptr->data!=pos)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = newnode;
    newnode->next = ptr;
    display();
}

void insert_before(int val, int pos)
{
    struct node *newnode = new struct node;
    newnode->data = val;

    struct node *ptr, *preptr;
    ptr = start;
    preptr = ptr;
    while(ptr->data!=pos)
    {
        preptr=ptr;
        ptr = ptr->next;
    }
    preptr->next = newnode;
    newnode->next = ptr;
    display();
}

void delete_begin()
{
    if(start==NULL)
    {
        cout<<"List is empty. Can't delete from empty list"<<endl;
    }
    else
    {
        struct node *ptr;
        ptr = start;
        start = start->next;
        free(ptr);
    }
    display();
}   

void delete_end()
{
    if(start == NULL)
    {
        cout<<"List is empty. Can;t delete from empty list"<<endl;
    }
    else
    {
        struct node *ptr, *preptr;
        ptr = start;
        preptr = ptr;

        while(ptr->next!=NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = NULL;
        free(ptr);
    }
    display();
}

void delete_after(int pos)
{
    
    if(start==NULL)
    {
        cout<<"List is empty. Can't delete from empty list"<<endl;
    }
    else
    {
        struct node *ptr, *preptr;
        ptr = start;
        preptr = ptr;

        while(preptr->data != pos)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
    }
    display();
}

void delete_before(int pos)
{
    if(start==NULL)
    {
        cout<<"List is empty. Can't delete from empty list"<<endl;
    }
    else
    {
        struct node *ptr, *preptr;
        ptr = start;
        preptr = ptr;

        while(ptr->next->data != pos)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
    }
    display();
}

void delete_num(int pos)
{
    if(start==NULL)
    {
        cout<<"List is empty. Can't delete from empty list"<<endl;
    }
    else
    {
        struct node *ptr;
        struct node *preptr, *temp;
        ptr = start;
        preptr = ptr;

        while(ptr->data != pos)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        temp = ptr;
        preptr->next = ptr->next;
        free(temp);
    } 
    display();
}

int main()
{   
    
    cout<<"\t\t\t\t***** Main Menu *****"<<endl;
    cout<<"\t\t\t\t1. display"<<endl;
    cout<<"\t\t\t\t2. insert begin"<<endl;
    cout<<"\t\t\t\t3. insert end"<<endl;
    cout<<"\t\t\t\t4. insert after"<<endl;
    cout<<"\t\t\t\t5. insert before"<<endl;
    cout<<"\t\t\t\t6. delete begin"<<endl;
    cout<<"\t\t\t\t7. delete end"<<endl;
    cout<<"\t\t\t\t8. delete after"<<endl;
    cout<<"\t\t\t\t9. delete before"<<endl;
    cout<<"\t\t\t\t10. delete num"<<endl;
    cout<<"\t\t\t\t11. search"<<endl;
    cout<<"\t\t\t\t12. exit"<<endl;

    int n, x, p, pos;
    

    while(1)
    {
        cout<<"enter choice: ";
        cin>>n;
        switch(n)
        {
            case 1:
                display();
                break;

            case 2:
                cout<<"Enter value to insert: ";
                cin>>x;
                insert_begin(x);
                break;

            case 3:
                cout<<"Enter value to insert: ";
                cin>>x;
                insert_end(x);
                break;
            
            case 4:
                cout<<"Enter value to insert: ";
                cin>>x;
                cout<<"Enter value after which to insert: ";
                cin>>p;
                insert_after(x, p);
                break;

            case 5:
                cout<<"Enter value to insert: ";
                cin>>x;
                cout<<"Enter value before which to insert: ";
                cin>>p;
                insert_before(x, p);
                break;

            case 6:
                delete_begin();
                break;

            case 7:
                delete_end();
                break;

            case 8:
                cout<<"Enter value after which to delete: ";
                cin>>p;
                delete_after(p);
                break;

            case 9:
                cout<<"Enter value before which to delete: ";
                cin>>p;
                delete_before(p);
                break;

            case 10:
                cout<<"Enter value to delete: ";
                cin>>p;
                delete_num(p);
                break;
            
            case 11:
                cout<<"Enter number to search: ";
                cin>>x;
                pos = search(x);
                if(pos != -1)
                    cout<<x<<" found at location "<<pos<<endl;
                else
                    cout<<x<<" not found in list"<<endl;
                break;

            case 12:
                exit(0);

            default:
                cout<<"invalid entry"<<endl;
                break;

        }   
    }
    
}