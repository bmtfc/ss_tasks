#include "StringList.h"

#include <iostream>
#include <string>

using namespace std;

// Stops the program until user inputs something by keyboard.
void BlockOutput();

// Prints menu options
void PrintMenuOptions();

// Prints menu
int PrintMenu(char **list);


int main()
{
    char **list;
    StringListInit(&list);
    return PrintMenu(list);
}

void BlockOutput()
{
    cout << "Press any key : \n";
    getchar();
    getchar();
}

void PrintMenuOptions()
{
    cout << "1. Add  string\n"
         << "2. Delete string by content\n"
         << "3. Index of string\n"
         << "4. Print list\n"
         << "5. Print list size\n"
         << "6. Sort list\n"
         << "7. Clear list (Destroy this list and init an empty list)\n"
         << "8. Add string examples\n"
         << "0. Exit\n";
}


int PrintMenu(char **list)
{
    int i = -1;

    while (i != 0)
    {
        cout << "---------------------------------------\n";
        PrintMenuOptions();
        cout << "Enter option : \n ";
        do
        {
            cin >> i;
        } while (!((i > -1) && (i < 9)));
        cout << "---------------------------------------\n";

        string str;

        switch (i)
        {
            case 1:
            {
                cout << "Enter a string to add : \n";
                cin >> str;
                StringListAdd(&list, const_cast<char *>(str.c_str()));
                break;
            }

            case 2:
            {
                cout << "Enter a string to remove: \n";
                cin >> str;
                StringListRemove(list, const_cast<char *>(str.c_str()));
                break;
            }

            case 3:
            {
                cout << "Enter a string to find: \n";
                cin >> str;
                size_t index = StringListIndexOf(list, const_cast<char *>(str.c_str())) + 1;
                if (index != -1)
                {
                    cout << "The index of the first occurrence is : " << index << '\n';
                }
                else
                {
                    cout << "Cannot find such string in the list" << '\n';
                }
                BlockOutput();
                break;
            }

            case 4:
            {
                cout << "\nList : " << '\n';
                StringListPrint(list);
                BlockOutput();
                break;
            }
            case 5:
            {
                cout << "List size : " << StringListSize(list) << '\n';
                BlockOutput();
                break;
            }

            case 6:
            {
                StringListSort(list);
                break;
            }
            case 7:
            {
                StringListDestroy(&list);
                StringListInit(&list);
                break;
            }
            case 8:
            {
                StringListAdd(&list, "lorem ipsum dolor sit amet");
                StringListAdd(&list, "consectetur adipiscing elit");
                StringListAdd(&list, "sed do eiusmod tempor incididunt ut");
                StringListAdd(&list, "labore et dolore magna aliqua");
                StringListAdd(&list, "ut enim ad minim veniam");
                break;
            }
            case 0:
            {
                return 0;
            }
        }
    }
    return 0;
}