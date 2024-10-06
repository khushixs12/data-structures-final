#include <iostream>
#include <conio.h>
using namespace std;
#define MAX 100
int main()
{
    int len=0, top=-1, option;
    char str[MAX], st[MAX];
    cout << "SIZE OF STRING ARRAY IS 100" << endl;
    cout << "1: ENTER STRING" << endl;
    do
    {
        cout << "\nEnter your option: ";
        cin >> option;
        switch(option)
        {
        case 1:
            cout << "Enter the string: ";
            cin >> str;
            for(int i=0; str[i] != '\0'; i++)
            {
                len++;
            }
            for(int i=0; i<len; i++)
            {
                top++;
                st[top]=str[i];
            }
            while(top!=-1)
            {
                cout << st[top];
                top--;
            }
		break;
        }
    }while(option==1);
    getch();
    return 0;
}
