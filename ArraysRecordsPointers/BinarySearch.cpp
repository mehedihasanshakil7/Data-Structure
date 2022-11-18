#include <bits/stdc++.h>
using namespace std;
void search_in_integer_array();
void search_in_string_array();

int main(void)
{
    //search_in_integer_array();
    search_in_string_array();
    return 0;
}

// Search an item using binary search in integer array
void search_in_integer_array()
{
    int n = 10, array[10] = {32, 38, 41, 43, 49, 53, 57, 59, 77, 89};
    int item, position = 0;
    cout<<"\nEnter your search item: ";
    cin>>item;
    int beg = 0, end = n - 1, mid = (beg + end) / 2;
    for (int i = 0; i < n; i++)
    {
        if (array[mid] < item)
        {
            beg = mid + 1;
        }
        else if (array[mid] > item)
        {
            end = mid - 1;
        }
        else
        {
            position = mid + 1;
            break;
        }
        mid = (beg + end) / 2;
    }
    if (position == 0)
    {
        cout << "\n"
             << item << " not found in the array\n\n";
    }
    else
    {
        cout << "\n"
             << item << " found at location " << position << "\n\n";
    }
    cout<<"\nThe array is:\n";
    for(int i = 0; i < n; i++) {
        cout<<array[i]<<" ";
    }
    cout<<"\n\n";
}

// Search an item using binary search in string array
void search_in_string_array()
{
    int n = 7, position = 0;
    string names[7] = {"Aishwarya", "Katrina", "Keerthy", "Parineeti", "Pooja", "Rashmika", "Zareen"};
    int beg = 0, end = n - 1, mid = (beg + end) / 2;
    string name;
    cout<<"\nEnter your desired name: ";
    getline(cin, name);
    
    for (int i = 0; i < n; i++)
    {
        if (name.compare(names[mid]) > 0) beg = mid + 1;
        else if (name.compare(names[mid]) < 0) end = mid - 1;
        else
        {
            position = mid + 1;
            break;
        }
        mid = (beg + end) / 2;
    }
    if (position == 0)
    {
        cout <<"\n"<< name << " is not found in the list\n\n";
    }
    else
    {
        cout <<"\n"<< name << " is found at " << position << "\n\n";
    }
    cout<<"\nThe array is:\n";
    for(string s : names) {
        cout<<s<<" ";
    }
    cout<<"\n\n";
}
