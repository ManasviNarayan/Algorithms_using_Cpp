#include <bits/stdc++.h>
using namespace std;

int main()
{
    int max;
    cout << "Enter max size of que: ";
    cin >> max;
    int que[max];
    int front, rear;
    front = rear = -1;

    cout << "\t***** Main Menu *****" << endl;
    cout << "\t1. Insert in end" << endl;
    cout << "\t2. Insert in begin" << endl;
    cout << "\t3. Delete from begin" << endl;
    cout << "\t4. Delete from end" << endl;
    cout << "\t5. Display" << endl;
    cout << "\t6. Exit" << endl;

    while (1)
    {
        int n, val;
        cout << "\nEnter choice: ";
        cin >> n;

        switch (n)
        {
        case 1:
            cout<<"Insert at end"<<endl;
            if (rear == max - 1)
            {
                cout << "Queue is full! Cannot insert" << endl;
                break;
            }
            cout << "Enter value to insert: ";
            cin >> val;
            if (front == -1 && rear == -1)
            {
                front = rear = 0;
            }
            else
            {
                rear = rear + 1;
            }
            que[rear] = val;
            break;

        case 2:
            cout << "Insert at begin"<<endl;
            if (front<=0)
            {
                cout << "Cannot insert at front" << endl;
                break;
            }
            cout << "Enter value to insert: ";
            cin >> val;
            front = front-1;
            que[front] = val;
            break;

        case 3:
            cout<<"Delete from begin"<<endl;
            if (front == -1)
            {
                cout<<"Underflow"<<endl;
                break;
            }
            else
            {
                val = que[front];
                cout<<val<<endl;
                if (front == rear)
                {
                    front = rear = -1;
                }
                else
                {
                    front = front + 1;
                }
            }
            break;

        case 4:
            cout << "Delete from end" << endl;
            if (rear==-1)
            {
                cout << "Cannot delete from end" << endl;
                break;
            }
            else
            {
                val = que[rear];
                cout << val << endl;
                if(front==rear)
                {
                    front=rear=-1;
                }
                else
                {
                    rear= rear-1;
                }
            }
            break;

        case 5:
            cout << "Display" << endl;
            cout << "Front -> ";
            for (int i = front; i <= rear; i++)
            {
                cout << que[i] << " -> ";
            }
            cout << "Rear" << endl;
            break;

        case 6:
            exit(0);

        default:
            cout << "Invalid entry" << endl;
        }
    }

    return 0;
}