#include<bits/stdc++.h>
using namespace std;
void insert_number_in_sorted_list();
void insert_name_in_sorted_list();
void insert_number_in_kth_position();
void insert_name_in_kth_position();

int main(void) { //Call only one function at a time
    insert_name_in_kth_position();
    //insert_name_in_sorted_list();
    //insert_number_in_sorted_list();
    //insert_number_in_kth_position();
    return 0;
}

//Insert a number into a sorted list
void insert_number_in_sorted_list() {
    int n = 10, i, item, array[15] = {32, 38, 41, 46, 49, 53, 57, 59, 62, 64};
    printf("\nEnter the number to be inserted into a sorted list: ");
    cin>>item;
    cout<<"\nArray before inserting the item:\n";
    for(i = 0; i < n; i++) {
        cout<<array[i]<<" ";
    }
    cout<<"\n\n";
    for(i = 0; i < n; i++) {
        if(item < array[i]) break;
    }
    for(int j = n; j > i; j--) {
        array[j] = array[j-1];
    }
    array[i] = item;
    n = n + 1;
    cout<<"Array after inserting "<<item<<" is:\n";
    for(i = 0; i < n; i++) {
        cout<<array[i]<<" ";
    }
    cout<<"\n\n";
}

//Insert a name into a sorted list
void insert_name_in_sorted_list() {
    int m = 7, i;
    string name;
    string names[15] = {"Aishwarya", "Katrina", "Keerthy", "Parineeti", "Pooja", "Rashmika", "Zareen"};
    cout<<"\nEnter the name to be inserted: ";
    getline(cin, name);
    cout<<"\nArray before inserting the name:\n";
    for(int i = 0; i < m; i++) {
        cout<<names[i]<<" ";
    }
    cout<<"\n\n";
    for(i = 0; i < m; i++) {
        if(name.compare(names[i]) < 0) break;
    }
    for(int j = m; j > i; j--) {
        names[j] = names[j-1];
    }
    names[i] = name;
    m = m + 1;
    cout<<"Array after inserting "<<name<<" is:\n";
    for(int j = 0; j < m; j++) {
        cout<<names[j]<<" ";
    }cout<<"\n\n";
}

//Insert name in k-th position
void insert_name_in_kth_position() {
    int n = 7, position;
    string name, names[15] = {"Aishwarya", "Katrina", "Keerthy", "Parineeti", "Pooja", "Rashmika", "Zareen"};
    cout<<"\nEnter a name: ";
    getline(cin, name);
    cout<<"\nEnter its position: ";
    cin>>position;
    cout<<"\nArray before inserting the name:\n";
    for(int i = 0; i < n; i++) {
        cout<<names[i]<<" ";
    }
    cout<<"\n\n";
    for(int i = n; i >= position; i--) {
        names[i] = names[i-1];
    }
    names[position-1] = name;
    n = n + 1;
    cout<<"Array after inserting "<<name<<" at position "<<position<<" is:\n";
    for(int j = 0; j < n; j++) {
        cout<<names[j]<<" ";
    }cout<<"\n\n";
}

//Insert a number in k-th position
void insert_number_in_kth_position() {
    int n = 5, item, position, array[10] = {1, 2, 3, 4, 5};
    cout<<"\nEnter a number and its position: ";
    cin>>item>>position;
    cout<<"\nArray before inserting the item:\n";
    for(int i = 0; i < n; i++) {
        cout<<array[i]<<" ";
    }
    cout<<"\n\n";
    for(int i = n; i >= position; i--) {
        array[i] = array[i-1];
    }
    array[position-1] = item;
    n = n + 1;
    for(int i = 0; i < n; i++) {
        cout<<array[i]<<" ";
    }
    cout<<"\n\n";
}
