#include <stdio.h>
#define max_size 100005
int T, n, a[max_size], temp[max_size];
void merge(int a[], int low, int mid, int high)
{
    int l1 = low, l2 = mid + 1, h1 = mid, h2 = high, l3 = low;
    while (l1 <= h1 && l2 <= h2)
        if (a[l1] < a[l2])
            temp[l3++] = a[l1++];
        else
            temp[l3++] = a[l2++];
    while (l1 <= h1)
        temp[l3++] = a[l1++];
    while (l2 <= h2)
        temp[l3++] = a[l2++];
    for (int i = low; i <= high; i++)
        a[i] = temp[i];
}
void mergesort(int a[], int low, int high)
{
    if (low >= high)
        return;
    int mid = (high + low) / 2;
    mergesort(a, low, mid);
    mergesort(a, mid + 1, high);
    merge(a, low, mid, high);
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        mergesort(a, 0, n - 1);
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
}
