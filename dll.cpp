#include <iostream>
#include <conio.h>
using namespace std;
class node
{
public:
    node *prev;
    int data;
    node *next;

    node()
    {
        prev=NULL;
        next=NULL;
    }
};

class dlinkedlist
{
private:
    int node_count;
public:
    node *newnode, *start, *ptr, *temp, *ptr1, *ptr2, *second_half;

    dlinkedlist()
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
            newnode->prev=NULL;
            newnode->next=start;
            start->prev=newnode;
            start=newnode;
        }
        node_count++;
    }

    void insert_at_end()
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
            newnode->next=NULL;
            ptr=start;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=newnode;
            newnode->prev=ptr;
        }
        node_count++;
    }

    void insert_after_node()
    {
        int num,val;
        if(start==NULL)
        {
            cout << "No linked list.";
        }
        else
        {
            cout << "Enter the value after which the data has to be inserted: ";
            cin >> num;

            newnode= new node();
            cout << "Enter the value: ";
            cin >> newnode->data;

            ptr=start;
            while(ptr->data!=num)
            {
                ptr=ptr->next;
            }
            newnode->prev=ptr;
            newnode->next=ptr->next;
            ptr->next->prev=newnode;
            ptr->next=newnode;

            node_count++;
        }
    }

    void insert_before_node()
    {
        int num,val;
        if(start==NULL)
        {
            cout << "No linked list.";
        }
        else
        {
            cout << "Enter the value before which the data has to be inserted: ";
            cin >> num;

            newnode= new node();
            cout << "Enter the value: ";
            cin >> newnode->data;

            ptr=start;
            while(ptr->data!=num)
            {
                ptr=ptr->next;
            }
            newnode->next=ptr;
            newnode->prev=ptr->prev;
            ptr->prev->next=newnode;
            ptr->prev=newnode;

            node_count++;
        }
    }

    void delete_first_node()
    {
        if (start==NULL)
        {
            cout << "No linked list." << endl;
        }
        else
        {
            ptr=start;
            start=start->next;
            start->prev=NULL;
            delete ptr;
            cout << "Node deleted" << endl;

            node_count--;
        }
    }

    void delete_last_node()
    {
        if (start==NULL)
        {
            cout << "No linked list." << endl;
        }
        else
        {
            ptr=start;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->prev->next=NULL;
            delete ptr;
            cout << "Node deleted" << endl;

            node_count--;
        }
    }

    void delete_after_node()
    {
        if (start==NULL)
        {
            cout << "No linked list.";
        }
        else
        {
            int num;
            cout << "Enter the value after which the data has to deleted: ";
            cin >> num;
            ptr=start;
            while(ptr->data!=num)
            {
                ptr=ptr->next;
            }
            temp=ptr->next;
            ptr->next=temp->next;
            temp->next->prev=ptr;
            delete temp;
            cout << "Node deleted" << endl;

            node_count--;
        }
    }

    void delete_before_node()
    {
        if (start==NULL)
        {
            cout << "No linked list.";
        }
        else
        {
            int num;
            cout << "Enter the value before which the data has to deleted: ";
            cin >> num;
            ptr=start;
            while(ptr->data!=num)
            {
                ptr=ptr->next;
            }
            temp=ptr->prev;
            if(temp==start)
            {
                delete_first_node();
            }
            else
            {
                temp->prev->next=ptr;
                ptr->prev=temp->prev;
                delete temp;
                cout << "Node deleted" << endl;
            }
            node_count--;
        }
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
        cout << "Linked List Sorted" << endl;
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
        second_half->prev=NULL;
        ptr->next=NULL;

        cout << "First half dll: ";
        split_merge_sll(start);
        cout << "Second half dll: ";
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
        if(second_half!=NULL)
        {
            second_half->prev=ptr;
        }
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
        int count =0;
        if(start==NULL)
        {
            cout << "No linked list!";
        }
        else
        {
            ptr=start;
            while(ptr!=NULL)
            {
                count++;
                ptr=ptr->next;
            }
        }
        cout << "The number of elements in linked list is " << count << endl;
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
        ptr=start;
        while(ptr!=NULL)
        {
            cout << ptr->data << " ";
            ptr=ptr->next;
        }
    }
    /*void display_ll()//backward traversal
    {
        ptr=start;
        while(ptr!=NULL && ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        while(ptr!=NULL)
        {
            cout << ptr->data << " ";
            ptr=ptr->prev;
        }
    }*/
};

int main()
{
    dlinkedlist dll;
    int option;
    cout << "1: Add a node at the beginning" << endl;
    cout << "2: Add a node at the end" << endl;
    cout << "3: Add a node after node" << endl;
    cout << "4: Add a node before node" << endl;
    cout << "5: Delete a node from the beginning" << endl;
    cout << "6: Delete a node from the end" << endl;
    cout << "7: Delete a node after node" << endl;
    cout << "8: Delete a node before node" << endl;
    cout << "9: Sorting" << endl;
    cout << "10: Splitting" << endl;
    cout << "11: Merging" << endl;
    cout << "12: Count total number of nodes" << endl;
    cout << "13: Count even and odd number of nodes" << endl;
    cout << "14: Display" << endl << endl;

    do
    {
        cout << "Enter your option: ";
        cin >> option;

        switch(option)
        {
        case 1:
            dll.insert_at_beginning();
            break;
        case 2:
            dll.insert_at_end();
            break;
        case 3:
            dll.insert_after_node();
            break;
        case 4:
            dll.insert_before_node();
            break;
        case 5:
            dll.delete_first_node();
            break;
        case 6:
            dll.delete_last_node();
            break;
        case 7:
            dll.delete_after_node();
            break;
        case 8:
            dll.delete_before_node();
            break;
        case 9:
            dll.bubble_sort();
            break;
        case 10:
            dll.split();
            break;
        case 11:
            dll.merge();
            break;
        case 12:
            dll.count();
            break;
        case 13:
            dll.even_odd_count();
            break;
        case 14:
            dll.display_ll();
            cout << endl;
            break;
        }
    }
    while(option!=15);
    getch();
    return 0;
}
