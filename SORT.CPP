#include <iostream.h>
#include <conio.h>
#include <dos.h>
void swap(int &a, int &b)
{

    int temp = a;
    a = b;
    b = temp;
}
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
void selectionSort(int arr[], int n)
{
    for (int k = 0; k < n - 1; k++)
    {
        int minIdx = k;
        for (int m = k + 1; m < n; m++)
            if (arr[m] < arr[minIdx])
                minIdx = m;
        swap(arr[k], arr[minIdx]);
    }
}
void insertionSort(int arr[], int n)
{
    for (int a = 1; a < n; a++)
    {
        int key = arr[a], b = a - 1;
        while (b >= 0 && arr[b] > key)
            arr[b + 1] = arr[b], b--;
        arr[b + 1] = key;
    }
}
void countingSort(int arr[], int n, int exp)
{
    int output[100], count[10] = {0};
    for (int c = 0; c < n; c++)
        count[(arr[c] / exp) % 10]++;
    for (int d = 1; d < 10; d++)
        count[d] += count[d - 1];
    for (int e = n - 1; e >= 0; e--)
    {
        output[count[(arr[e] / exp) % 10] - 1] = arr[e];
        count[(arr[e] / exp) % 10]--;
    }
    for (int f = 0; f < n; f++)
        arr[f] = output[f];
}
void radixSort(int arr[], int n)
{
    int maxVal = arr[0];
    for (int g = 1; g < n; g++)
        if (arr[g] > maxVal)
            maxVal = arr[g];
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}
void main()
{
    clrscr();
    int choice, n, arr[100];
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int h = 0; h < n; h++)
    cin >> arr[h];
    cout << "Choose sorting algorithm:\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Radix Sort\nEnter your choice (1-4): ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        bubbleSort(arr, n);
        break;
    case 2:
        selectionSort(arr, n);
        break;
    case 3:
        insertionSort(arr, n);
        break;
    case 4:
        radixSort(arr, n);
        break;
    default:
        cout << "Invalid choice!" << endl;
        return;
    }
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    getch();
}
