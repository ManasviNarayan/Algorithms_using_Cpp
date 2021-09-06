#include <bits/stdc++.h>
using namespace std;

int main()
{
    int max;
    cout << "Enter max queue size: ";
    cin >> max;
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
        int n, val, i,j;
        cout << "\nEnter choice: ";
        cin >> n;

        switch (n)
        {
            case 1:
                if (rear==max-1)
                {
                    cout<<"Overflow"<<endl;
                    break;
                }
                cout<<"Enter value to insert: ";
                cin>>val;
                if(front==-1 && rear==-1)
                {
                    front++;
                    rear++;
                    queue[rear] = val;
                    break;
                }
                else
                {
                    for(i=0; i<=rear; i++)
                    {
                        if(val>=queue[i])
                        {
                            for (j=rear+1; j>i; j--)
                            {
                                queue[j] = queue[j-1];
                            }
                            queue[i]=val;
                            break;
                        }
                    }
                    queue[i]=val;
                }
                break;

            case 2:
                if(front==-1 && rear == -1)
                {
                    cout<<"Queue is empty"<<endl;
                    break;
                }
                cout << "Enter value to delete: ";
                cin >> val;
                for(i=0; i<=rear; i++)
                {
                    if(val == queue[i])
                    {
                        for(;i<rear;i++)
                        {
                            queue[i] = queue[i+1];
                        }
                        rear--;

                        if(rear==-1)
                        {
                            front = -1;
                        }
                        break;
                    }
                }
                cout<<"Value not found in queue"<<endl;
                break;

            case 3:
                if(front==-1 and rear == -1)
                {
                    cout<<"Queue is empty"<<endl;
                    break;
                }
                for(i=0;i<max; i++)
                {
                    cout<<queue[i]<<" -> ";
                }
                cout<<queue[rear];
                break;

            case 4:
                exit(0);

            default:
                cout<<"Invalid entry"<<endl;
        }
    }
}