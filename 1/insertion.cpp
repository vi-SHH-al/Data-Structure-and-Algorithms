#include <stdio.h>
#include <time.h>

void insertion(int arr[])
{

    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;

        while (arr[j] > temp && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
int main()
{

    int arr[] = {23, 1, 10, 5, 2};
    int n = 5;

    printf("Before Insertion Sort:  ");
    for (int i = 0; i < n; i++)
        printf(" %d ", arr[i]);

    printf("\nAfter Insertion Sort :  ");
    for (int i = 0; i < n; i++)
        printf(" %d ", arr[i]);

    printf("\n");
    return 0;
}