#include<bits/stdc++.h>
using namespace std;
void delete_from_sorted_array();
void delete_from_kth_position();
int main(void) {
    //delete_from_sorted_array();
    delete_from_kth_position();
    return 0;
}

//Delete item from a sorted array
void delete_from_sorted_array() {
    int n = 7, i;
    string name;
    string names[15] = {"Aishwarya", "Katrina", "Keerthy", "Parineeti", "Pooja", "Rashmika", "Zareen"};
    cout<<"\nArray before deletion:\n";
    
    for(int j = 0; j < n; j++) {
            cout<<names[j]<<" ";
        }
    cout<<"\n\nEnter the name to be deleted: ";
    getline(cin, name);
    for(i = 0; i < n; i++) {
        if(name.compare(names[i]) == 0) break;
    }
    if(i < 7) {
        for(int j = i; j < n - 1; j++) {
            names[j] = names[j+1];
        }
        n = n - 1;
        cout<<"\nArray after deleting "<<name<<" is:\n";
        for(int j = 0; j < n; j++) {
            cout<<names[j]<<" ";
        }
        cout<<"\n\n";
    }
    else {
        cout<<"\n"<<name<<" is not found in the list\n\n";
    }

}

//Delete item from k-th position
void delete_from_kth_position() {
    int n = 7, position;
    string names[15] = {"Aishwarya", "Katrina", "Keerthy", "Parineeti", "Pooja", "Rashmika", "Zareen"};
    cout<<"\n\nArray before deletion:\n";
    for(string s : names) {
        cout<<s<<" ";
    }
    cout<<"\n\n";
    cout<<"Enter the position of a name: ";
    cin>>position;
    string name = names[position-1];
    for(int i = position - 1; i < n -1; i++) {
        names[i] = names[i+1];
    }
    n = n - 1;
    cout<<"\nDeleted name: "<<name;
    cout<<"\n\nArray after deleting name from position "<<position<<" is:\n";
        for(int j = 0; j < n; j++) {
            cout<<names[j]<<" ";
        }
        cout<<"\n\n";
}
