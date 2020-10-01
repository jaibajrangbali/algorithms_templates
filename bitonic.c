#include <stdio.h>
#define maxsize 1000009
#define MOD 1000000007
#define debug 0
#define int long long int
int segCount[maxsize * 3], maintain[maxsize * 3], N, k, l;
int arr[maxsize][2], temp[maxsize][2], Arr[maxsize], segArr[maxsize * 3][7];
void sort(int l, int r)
{
    if (l == r)
        return;
    int l1 = l, l2 = (l + r) / 2 + 1, r1 = (l + r) / 2, r2 = r, i = l;
    sort(l1, r1);
    sort(l2, r2);
    while (l1 <= r1 || l2 <= r2)
    {
        if (l1 > r1)
        {
            temp[i][1] = arr[l2][1];
            temp[i++][0] = arr[l2++][0];
        }
        else if (l2 > r2)
        {
            temp[i][1] = arr[l1][1];
            temp[i++][0] = arr[l1++][0];
        }
        else if (arr[l1][0] <= arr[l2][0])
        {
            temp[i][1] = arr[l1][1];
            temp[i++][0] = arr[l1++][0];
        }
        else
        {
            temp[i][1] = arr[l2][1];
            temp[i++][0] = arr[l2++][0];
        }
    }
    for (i = l; i <= r; i++)
    {
        arr[i][1] = temp[i][1];
        arr[i][0] = temp[i][0];
    }
    return;
}
void putSum(int l, int r, int i, int index, int val)
{
    segCount[i] += val;
    segCount[i] %= MOD;
    if (l == r)
        return;
    int m = (l + r) / 2;
    if (index <= m)
        putSum(l, m, 2 * i, index, val);
    else
        putSum(m + 1, r, 2 * i + 1, index, val);
    return;
}
int findSum(int l, int r, int i, int lg, int rg)
{
    if (lg <= l && r <= rg)
        return segCount[i] % MOD;
    if (lg > r || rg < l)
        return 0;
    int m = (l + r) / 2, s1, s2;
    s1 = findSum(l, m, 2 * i, lg, rg);
    s2 = findSum(m + 1, r, 2 * i + 1, lg, rg);
    return (s1 + s2) % MOD;
}
signed main()
{
    scanf("%lld", &N);
    for (int j = 1; j <= N; j++)
    {
        scanf("%lld", &segArr[j][0]);
        arr[j][0] = segArr[j][0];
        arr[j][1] = j;
    }
    sort(1, N);
    k = 0;
    arr[0][0] = 0;
    for (int j = 1; j <= N; j++)
    {
        if (arr[j - 1][0] < arr[j][0])
            k++;
        segArr[arr[j][1]][0] = k;
    }
    for (int j = 0; j < N; j++)
        Arr[j] = segArr[j + 1][0];
    ///   Arr with 0 indexing
    for (int j = 0; j < maxsize * 3; j++)
    {
        maintain[j] = 0;
        segCount[j] = 0;
    }
    for (int j = 1; j <= N; j++)
    {
        segArr[j][2] = 1 + findSum(1, N, 1, 0, segArr[j][0] - 1);
        segArr[j][6] = 1 + findSum(1, N, 1, 0, segArr[j][0]);
        putSum(1, N, 1, segArr[j][0], segArr[j][6]);
        maintain[segArr[j][0]] = segArr[j][2];
    }
    if (debug)
    {
        for (int j = 1; j <= 2 * N; j++)
            printf("%lld  ", segCount[j]);
        printf("\n");
    }
    for (int j = 0; j < maxsize * 3; j++)
    {
        maintain[j] = segCount[j] = 0;
    }
    for (int j = N; j > 0; j--)
    {
        segArr[j][3] = 1 + findSum(1, N, 1, 0, segArr[j][0] - 1);
        segArr[j][5] = 1 + findSum(1, N, 1, 0, segArr[j][0]);
        putSum(1, N, 1, segArr[j][0], segArr[j][5]);
        maintain[segArr[j][0]] = segArr[j][3];
    }
    int ans = 0;
    for (int j = 1; j <= N; j++)
    {
        if (debug)
            printf("%lld ---   %lld  *   %lld\n", ans, segArr[j][2], segArr[j][3]);
        ans += ((segArr[j][6]) % MOD * (segArr[j][3]) % MOD) % MOD;
        ans = ans % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}

