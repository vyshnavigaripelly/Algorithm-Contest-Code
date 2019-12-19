#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const long long MAXN = 1e6 + 5;
long long ans; // 存放逆序数，比较大，必须用long long
long long a[MAXN], b[MAXN], c[MAXN];

// 将已经排好序的left~mid,mid+1~right进行归并
void merge(long long a[], long long left, long long mid, long long right)
{
    long long i, j;
    i = 0;
    for (j = left; j <= mid; j++)
        b[i++] = a[j];
    long long len1 = mid - left + 1;
    i = 0;
    for (j = mid + 1; j <= right; j++)
        c[i++] = a[j];
    long long len2 = right - mid;
    i = 0;
    j = 0;
    long long k = left;
    while (i < len1 && j < len2 && k <= right)
    {
        if (b[i] <= c[j])
        {
            a[k++] = b[i++];
        }
        else
        {
            a[k++] = c[j++];
            ans += (len1 - i); // 逆序数就是累加后面比自己小的数的个数
            // 此时b[i]>c[j],那么c[j]会给b[i]后面的len1-i个数造成逆序数
        }
    }
    while (i < len1)
        a[k++] = b[i++];
    while (j < len2)
        a[k++] = c[j++];
}

void merge_sort(long long a[], long long left, long long right) // 对a[left~right-1]进行归并排序
{
    if (left < right)
    {
        long long mid = (left + right) / 2;
        merge_sort(a, left, mid);
        merge_sort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

int main()
{
    long long n;
    scanf("%lld", &n);
    for (long long i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    ans = 0;
    merge_sort(a, 0, n - 1);
    if ((3 * n - ans) % 2 == 0)
        printf("Petr");
    else
        printf("Um_nik");
    return 0;
}
