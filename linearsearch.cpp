 //Write a program to implement sequential search.
#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int a[5];
    int i, val;
    cout << "Enter the values of the array: " << endl;
    for(i=0;i<5;i++)
    {
        cin >> a[i];
    }
    cout << "Enter the value you want to search: " << endl;
    cin >> val;
    int pos = -1;
    i=0;
    while(i<5)
    {
        if(a[i]==val)
        {
            pos=i;
            cout << pos;
            break;
        }
        i++;
    }
    if(pos==-1)
    {
        cout << "value not found";
    }
    return 0;
}

