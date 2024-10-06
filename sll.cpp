#include <iostream>
#include <conio.h>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node()
    {
        next=NULL;
    }
};

class slinkedlist
{
private:
    int node_count=0;
public:
    node *newnode, *start, *ptr, *preptr, *temp, *ptr1, *ptr2, *second_half;

    slinkedlist()
    {
        start=NULL;
        node_count=0;
    }

    void insert_at_beginning()
    {
        newnode=new node();
        cout << "Enter the value: ";
        cin >> newnode->data;
        if(start==NULL)
        {
            start=newnode;
        }
        else
        {
            newnode->next=start;
            start=newnode;
        }
        node_count++;
    }

    void insert_at_ending()
    {
        newnode = new node();
        cout << "Enter the value: ";
        cin >> newnode->data;
        if(start == NULL)
        {
            start = newnode;
        }
        else
        {
            ptr = start;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newnode;
        }
        node_count++;
    }

    void insert_before_node()
    {
        if(start==NULL)
        {
            cout << "No linked list.";
        }
        else
        {
            ptr=start;
            int i=1,userpos, pos;
            cout << "Enter the position before which you want to add a node: ";
            cin >> userpos;
            pos=userpos;
            if(pos>node_count)
            {
                cout << "Position does not exist." << endl;
            }
            else
            {
                newnode = new node();
                cout << "Enter the value: ";
                cin >> newnode->data;

                if(pos==1)//insert at beginning
                {
                    newnode->next=start;
                    start=newnode;
                }
                else //inserting in middle
                {
                    ptr=start;
                    while(i<pos)
                    {
                        preptr=ptr;
                        ptr=ptr->next;
                        i++;
                    }
                    preptr->next=newnode;
                    newnode->next=ptr;
                }
            }
        }
        node_count++;
    }

    void insert_after_node()
    {
        if(start==NULL)
        {
            cout << "No linked list.";
        }
        else
        {
            ptr=start;
            int i=1, userpos, pos;
            cout << "Enter the position after which you want to add a node: ";
            cin >> userpos;
            pos=userpos;
            if(pos>node_count)
            {
                cout << "Position does not exist." << endl;
            }
            else
            {
                newnode = new node();
                cout << "Enter the value: ";
                cin >> newnode->data;

                if(pos==node_count)//insert at end
                {
                    ptr = start;
                    while(ptr->next != NULL)
                    {
                        ptr = ptr->next;
                    }
                    ptr->next = newnode;
                }
                else //inserting in middle
                {
                    ptr=start;
                    while(i<=pos)
                    {
                        preptr=ptr;
                        ptr=ptr->next;
                        i++;
                    }
                    preptr->next=newnode;
                    newnode->next=ptr;
                }
            }
        }
        node_count++;
    }

    void delete_first_node()
    {
        if(start==NULL)
        {
            cout << "No linked list";
        }
        else
        {
            ptr=start;
            start=start->next;
            delete ptr;
        }
        node_count--;
    }

    void delete_last_node()
    {
        if(start==NULL)
        {
            cout << "No linked list." << endl;
        }
        else
        {
            ptr=start;
            while(ptr->next!=NULL)
            {
                preptr=ptr;
                ptr=ptr->next;
            }
            preptr->next=NULL;
            delete ptr;
        }
        node_count--;
    }

    void delete_before_node()
    {
        if(start==NULL)
        {
            cout << "No linked list." << endl;
            return;
        }

        int pos;
        cout << "Enter the position before which the node has to be deleted: ";
        cin >> pos;
        if(pos>node_count)
        {
            cout << "Nodes don't exist after it." << endl;
        }
        else if(pos==1)
        {
            cout << "Nodes don't exist before it." << endl;
        }
        else if(pos==2)
        {
            ptr=start;
            start=start->next;
            delete ptr;
        }
        else
        {
            ptr=start;
            for(int i=1; i<pos-2; i++)
            {
                ptr=ptr->next;
            }
            temp=ptr->next;
            ptr->next=temp->next;
            delete temp;
        }
        node_count--;
    }

    void delete_after_node()
    {
        if(start==NULL)
        {
            cout << "No linked list." << endl;
            return;
        }

        int pos;
        cout << "Enter the position after which the node has to be deleted: ";
        cin >> pos;
        if(pos>=node_count)
        {
            cout << "Nodes don't exist after it." << endl;
        }
        else
        {
            ptr=start;
            for(int i=1; i<pos; i++)
            {
                ptr=ptr->next;
            }
            temp=ptr->next;
            ptr->next=temp->next;
            delete temp;
        }
        node_count--;
    }

    void bubble_sort()
    {
        if (start == NULL)
        {
            cout << "No linked list." << endl;
            return;
        }

        for (int i = 0; i < node_count - 1; i++)
        {
            ptr1 = start;
            ptr2 = start->next;

            for (int j = 0; j < node_count - i - 1; j++)
            {
                if (ptr1->data > ptr2->data)
                {
                    int temp = ptr1->data;
                    ptr1->data = ptr2->data;
                    ptr2->data = temp;
                }
                ptr1 = ptr2;
                ptr2 = ptr2->next;
            }
        }
    }

    void split()
    {
        if(node_count < 2)
        {
            cout << "Linked list is too small to split." << endl;
            return;
        }
        int pos=node_count/2;
        ptr=start;
        for(int i=1; i<pos; i++)
        {
            ptr=ptr->next;
        }
        second_half=ptr->next;
        ptr->next=NULL;

        cout << "First half sll: ";
        split_merge_sll(start);
        cout << "Second half sll: ";
        split_merge_sll(second_half);
    }

    void merge()
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=second_half;
        cout << "Merged List: ";
        split_merge_sll(start);
    }

    void split_merge_sll(node *start)
    {
        ptr=start;
        while(ptr!=NULL)
        {
            cout << ptr->data << " ";
            ptr=ptr->next;
        }
        cout << endl;
    }

    void count()
    {
        node_count=0;
        if(start==NULL)
        {
            cout << "No linked list!";
        }
        else
        {
            ptr=start;
            while(ptr!=NULL)
            {
                node_count++;
                ptr=ptr->next;
            }
        }
        cout << "The number of elements in linked list is " << node_count << endl;
    }

    void even_odd_count()
    {
        int odd=0, even=0;
        ptr=start;
        while(ptr!=NULL)
        {
            if(ptr->data%2==0)
                even++;
            else
                odd++;
            ptr=ptr->next;
        }
        cout << "\nEven number of nodes: " << even << endl << "Odd number of nodes: " << odd << endl;
    }

    void display_ll()
    {
        ptr = start;
        while(ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
};

int main()
{
    slinkedlist sll;
    int option;
    cout << "1: Add a node at the beginning" << endl;
    cout << "2: Add a node at the end" << endl;
    cout << "3: Add a node before the given node" << endl;
    cout << "4: Add a node after a given node" << endl;
    cout << "5: Delete a node from the beginning" << endl;
    cout << "6: Delete a node from the end" << endl;
    cout << "7: Delete before a given node" << endl;
    cout << "8: Delete after a given node" << endl;
    cout << "9: Sorting" << endl;
    cout << "10: Splitting" << endl;
    cout << "11: Merging" << endl;
    cout << "12: Count the number of nodes" << endl;
    cout << "13: Count even and odd number of nodes" << endl;
    cout << "14: Display linked list" << endl;

    do
    {
        cout << "Enter your option: ";
        cin >> option;
        switch(option)
        {
        case 1:
            sll.insert_at_beginning();
            break;
        case 2:
            sll.insert_at_ending();
            break;
        case 3:
            sll.insert_before_node();
            break;
        case 4:
            sll.insert_after_node();
            break;
        case 5:
            sll.delete_first_node();
            break;
        case 6:
            sll.delete_last_node();
            break;
        case 7:
            sll.delete_before_node();
            break;
        case 8:
            sll.delete_after_node();
            break;
        case 9:
            sll.bubble_sort();
            break;
        case 10:
            sll.split();
            break;
        case 11:
            sll.merge();
            break;
        case 12:
            sll.count();
            break;
        case 13:
            sll.even_odd_count();
            break;
        case 14:
            sll.display_ll();
            cout << endl;
            break;
        }
    }while(option!=15);
    return 0;
}
