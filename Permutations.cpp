#include <iostream>

using namespace std;

void print(int arr[], int);
void copy(int source[], int destination[], int);
void printPermutations(int arr[], int i, int, int &);
void someFunFunc();

int main()
{
    int size = 0;
    int a[] = { 1, 2, 3, 4, 5, 6, 7 };
    printPermutations(a, 0, 7, size);
    cout << "Number of permutations: " << size << endl;
}

void printPermutations(int arr[], int start, int size, int &count) {
    if (start == size - 1) {
        count++;
        print(arr, size);
        return;
    }
    else {
        int * cpy = new int[size];
        for (int i = start; i < size; i++) {
            copy(arr, cpy, size);
            int j = cpy[i];
            cpy[i] = cpy[start];
            cpy[start] = j;
            printPermutations(cpy, start + 1, size, count);
        }
    }
}

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void copy(int source[], int destination[], int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}