#include<bits/stdc++.h>
using namespace std;
void sort_integer_data();
void sort_string_data();
void print_integer_array(int[], int);
void print_string_array(string[], int);

int main(void) {
    sort_integer_data();
    sort_string_data();
    return 0;
}

//Sort integer data using bubble sort
void sort_integer_data() {
    int n = 10, array[10] = {5, 3, 2, 4, 1, 0, 9, 8, 7, 6};
    printf("\nArray before sorting: ");
    print_integer_array(array, n);
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(array[j] > array[j+1]) swap(array[j], array[j+1]);
        }
    }
    printf("\nArray after sorting: ");
    print_integer_array(array, n);
    printf("\n\n");
}

//Sort string data using bubble sort
void sort_string_data() {
    int n = 7;
    string names[7] = {"Rashmika", "Katrina", "Keerthy", "Zareen", "Pooja", "Aishwarya", "Parineeti"};
    printf("\nArray before sorting: ");
    print_string_array(names, n);
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(names[j].compare(names[j+1]) > 0) swap(names[j], names[j+1]);
        }
    }
    printf("\nArray after sorting: ");
    print_string_array(names, n);
    printf("\n\n");
}

//Print integer array
void print_integer_array(int array[], int n) {
    for(int i = 0; i < n; i++) {
        cout<<array[i]<<" ";
    }
    cout<<"\n";
}

//Print string arry
void print_string_array(string names[], int n) {
    for(int i = 0; i < n; i++) {
        cout<<names[i]<<" ";
    }
    cout<<"\n";
}
