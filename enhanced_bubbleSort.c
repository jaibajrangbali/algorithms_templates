#include <stdio.h>
#define max_size 100005
int T, a[max_size], n;
void bubblesort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int is_swap = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
                is_swap = 1;
            }
        }
        if (is_swap == 0)
            break;
    }
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n); // The total number of elements
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]); // Adding the elements to the array
        bubblesort(a, n);
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
}
