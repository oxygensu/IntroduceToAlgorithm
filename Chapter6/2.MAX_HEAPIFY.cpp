#include <iostream>

using namespace std;

void max_heapify(int *array, int k);

int main()
{
    int test1[14] = {27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
    int test2[10] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    max_heapify(test1, 3);
    max_heapify(test2, 1);
    for (int i = 0; i < 14; i++)
        cout << test1[i] << " ";
    cout << endl;
    for (int i = 0; i < 10; i++)
        cout << test2[i] << " ";
    cout << endl;

    return 0;
}

void max_heapify(int *array, int k)
{
    if ((2 * k + 1) >= sizeof(array) / sizeof(int))
        return;
    int max_index;
    if (array[2 * k + 1] > array[2 * k + 2])
        max_index = 2 * k + 1;
    else
        max_index = 2 * k + 2;
    if (array[k] < array[max_index])
    {
        int temp = array[k];
        array[k] = array[max_index];
        array[max_index] = temp;
        max_heapify(array, max_index);
    }
    return;
}