#include<bits/stdc++.h>
using namespace std;

int main()
{
    int max;
    cout<<"Enter max size of que: ";
    cin>>max;
    int que[max];
    int front, rear;
    front = rear = -1;

    cout << "\t***** Main Menu *****" << endl;
    cout << "\t1. Insert" << endl;
    cout << "\t2. Delete" << endl;
    cout << "\t3. Display" << endl;
    cout << "\t4. Exit" << endl;

    while (1)
    {
        int n, val;
        cout << "\nEnter choice: ";
        cin >> n;

        switch (n)
        {
        case 1:
            cout << "Insert" << endl;
            cout<<"Enter value to insert: ";
            cin>>val; 
            if(front==0 && rear == max-1)
            {
                cout<<"Overflow"<<endl;
                break;
            }
            if(front == -1 && rear==-1)
            {
                front = rear = 0;
            }
            else if(rear == max-1 && front!=0)
            {
                rear = rear%max;
            }
            else
            {
                rear = rear + 1;
            }
            que[rear] = val;

            break;
           

        case 2:
            cout << "Delete" << endl;
            if (front == -1)
            {
                cout << "Underflow" << endl;
                break;
            }
            val = que[front];
            cout << val << endl;

            if(front==rear)
            {
                front = rear = -1;
            }
            else
            {
               if(front == max-1)
               {
                   front = 0;
               }
               else
               {
                   front = front +1;
               }
            }
            break;

        case 3:
            cout << "Display" << endl;
            cout << "Front -> ";
            for (int i = front; i <= rear; i++)
            {
                cout << que[i] << " -> ";
            }
            cout << "Rear" << endl;
            break;

        case 4:
            exit(0);

        default:
            cout << "Invalid entry" << endl;
        }
    }

    return 0;
}