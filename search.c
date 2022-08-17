#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#define SIZE 1000000
// Basically outputting time taken to search all elements in the array.

bool sequential_search(int arr[], int n, int value);
bool binary_search(int arr[], int lower, int upper, int value);

int main()
{
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++)
        arr[i] = i;
    
    for (int sz = 10; sz <= SIZE; sz *= 10)
    {
        int start = clock();
        for (int val = 0; val < sz; val++)
            if (!sequential_search(arr, SIZE, val))
                printf("Not sequntial\n");
        double linear_time = (double)(clock() - start) / CLOCKS_PER_SEC;

        start = clock();
        for (int val = 0; val < sz; val++)
            if (!binary_search(arr, 0, SIZE, val))
                printf("Not sequntial\n");
        double binary_time = (double)(clock() - start) / CLOCKS_PER_SEC;

        printf("Size: %i\tLinear: %lf\tBinary: %lf\n", sz, linear_time, binary_time);
    }

    return 0;
}

bool sequential_search(int arr[], int n, int value)
{
    for (int i = 0; i < n; i++)
        if (value == i)
            return true;
    return false;
}

bool binary_search(int arr[], int lower, int upper, int value)
{
    if (lower > upper)
        return false;
    int mid = (lower + upper) / 2;
    if (arr[mid] == value)
        return true;
    else if (value > arr[mid])
        return binary_search(arr, mid + 1, upper, value);
    else
        return binary_search(arr, lower, mid - 1, value);
}