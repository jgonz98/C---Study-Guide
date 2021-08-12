#include <iostream>
#include <stdio.h>

using namespace std;

// Insertion Sort
// Average Case: O(n^2)
// Worst Case: O(n^2)
// Best Case: O(n)

// Explanation: Insertion sort works by sorting an array left to right. If the ith position is smaller swap it with the left position or ith-1.
// This process is repeated until the ith position is greater than the left position. This causes it to slowly sort into increasing order from left to right.
// In worst case it will have to run the while loop inside for the entire lenght of the array for all numbers from left to right and repeat for all positions.
// This makes it O(n^2). Best case it never runs the while loop since it is in order making it O(n)
void insertion_sort(int *a, int siz)
{
    if (siz == 1)
    {
        return;
    }
    for (int i = 1; i < siz; i++)
    {
        int j = i;
        while (a[j] < a[j - 1] && j > 0)
        {
            int temp = a[j - 1];
            a[j - 1] = a[j];
            a[j] = temp;
            j--;
        }
    }
}

int main()
{
    int example[] = {1, 8, 3, 9, 5, 2, 0};
    insertion_sort(example, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << example[i] << " ";
    }
}