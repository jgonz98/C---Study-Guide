// Average case Time Complexity: nlog(n)
// Worst case: n^2
// When to use: When working with a small array that is sorted randomly

// Partition - subset of Quicksort
// All elements less than or equal to the pivot are put towards the left of the pivot
// All elements greater than the pivot are put towards the right of the pivot
int partition(vector<int> &statues, int left, int right)
{
    int pivot = statues[right];
    int pIndex = left;
    for (int i = left; i < right; i++)
    {
        if (statues[i] <= pivot)
        {
            swap(statues[i], statues[pIndex]);
            pIndex++;
        }
    }
    swap(statues[pIndex], statues[right]);
    return pIndex;
}

// Quicksort
// Sort into ascending order by choosing a pivot and setting the less than or equal to on the left
// and the greater than on the right of the pivot. Repeat this for every set you break it down into.
// It will be sorted once the left and right cross each other aka left is greater than right.
void quickSort(vector<int> &statues, int left, int right)
{
    if (left < right)
    {
        int pIndex = partition(statues, left, right);
        quickSort(statues, left, pIndex - 1);
        quickSort(statues, pIndex + 1, right);
    }
}