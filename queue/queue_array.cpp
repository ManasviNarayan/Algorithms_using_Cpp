#include<bits/stdc++.h>
using namespace std;

int main()
{
    int max;
    cout<<"Enter max queue size: ";
    cin>>max;
    int queue[max];
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

            if(rear == max-1)
            {
                cout<<"Queue is full! Cannot insert"<<endl;
                break;
            }
            cout<<"Enter value to insert: ";
            cin>>val;
            if(front==-1 && rear == -1)
            {
                front = rear = 0;
            }
            else
            {
                rear = rear +1;
            }
            queue[rear] = val;
            break;

        case 2:
            cout << "Delete" << endl;
            if(front== -1 || front>rear)
            {
                cout<<"Underflow"<<endl;
            }
            else
            {
                val = queue[front];
                cout<<val<<endl;
                front = front+1;
            }
            break;

        case 3:
            cout << "Display" << endl;
            cout<<"Front -> ";
            for(int i=front; i<=rear; i++)
            {
                cout<<queue[i]<<" -> ";
            }
            cout<<"Rear"<<endl;
            break;

        case 4:
            exit(0);

        default:
            cout << "Invalid entry" << endl;
        }
    }

    return 0;
}