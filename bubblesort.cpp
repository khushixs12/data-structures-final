//Write a program to implement bubble sort.
#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int a[5],i,j;
    cout << "Enter elements in the array: " << endl;
    for(i=0;i<5;i++)
    {
        cin >> a[i];
    }

    for(i=0;i<5;i++)
    {
        for(j=0;j<5-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

    for(i=0;i<5;i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
