//Reverse Array Program


/*
This program takes an integer array and reverses the contents of the array. Then, it prints the original array and the reversed array to the console.
*/


#include <iostream>

using namespace std;
/*
Function: ReverseArray
Purpose: To reverse the contents of an array
Parameters:
 - int const arr[]: The array to be reversed
 - int size: The size of the array
Returns: A pointer to the reversed array
Preconditions: The array must be populated with values
Postconditions: The array is reversed
*/

int *ReverseArray(int const arr[], int size);

/* 
Function: print
Purpose: To print the contents of an array
Parameters:
 - int const arr[]: The array to be printed
 - int size: The size of the array
Returns: None
Preconditions: The array must be populated with values
Postconditions: The array is printed to the console
*/

void print(int const arr[], int size);

int main() { 
    //Create an array of integers that will be reversed. The array size and the contents may be changed if desired.
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    //Call the ReverseArray function and store the returned pointer in a pointer variable.
    int *reversed = ReverseArray(arr, 10);
    
    //Use the print function to print the original array and the reversed array.
    cout << "Original array:" << endl;
    print(arr, 10);
    cout << endl;
    cout << "Reversed array:" << endl;
    print(reversed, 10);

   //Delete the reversed array and end the program.
    delete[] reversed;
    return 0;
}

int *ReverseArray(int const arr[], int size) {
    int *reversed = new int[size];
    for (int i = 0; i < size; i++) {
        reversed[i] = arr[size - i - 1];
    }
    return reversed;
}

void print(int const arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}