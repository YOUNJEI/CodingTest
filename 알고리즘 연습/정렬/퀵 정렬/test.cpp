#include <iostream>
using namespace std;

/* 특정 숫자를 기준으로 왼쪽은 작은 값 / 오른쪽은 큰 값으로 정렬해주고 */
/* 재귀함수로 위 행위를 계속 분할 */
void quick_sort(int *arr, int *start, int *end)
{
    // 원소가 1개인 경우 종료.
    if (start >= end)
        return ;
    // 기준점은 시작점.
    int *pivot = start;
    // left는 왼쪽에서 오른쪽으로 진행하는 idx. 피벗보다 큰 값을 찾음
    int *left = start + 1;
    // right는 오른쪽에서 왼쪽으로 진행하는 idx. 피벗보다 작은 값을 찾음
    int *right = end;
    int temp;

    while (left <= right)
    {
        // 피벗보다 큰 데이터를 찾을때까지
        while (left <= end && *left <= *pivot)
            left += 1;
        // 피벗보다 작은 데이터를 찾을때까지
        while (right > start && *right >= *pivot)
            right -= 1;
        if (left > right) // 엇갈렸다면 작은 데이터와 피벗을 교체 swap(pivot, right)
        {
            temp = *right;
            *right = *pivot;
            *pivot = temp;
        }
        else    // 엇갈리지 않았다면 작은데이터와 큰 데이터를 교체 swap(left, right)
        {
            temp = *left;
            *left = *right;
            *right = temp;
        }
    }
    quick_sort(arr, start, right - 1);
    quick_sort(arr, right + 1, end);
}

int main(void)
{
    int N = 10;
    int arr[] = {5, 7, 9, 0, 3, 1, 6, 2, 4, 8};

    quick_sort(arr, arr, arr + 9);
    for (int i = 0; i < 10; i++)
        cout<<arr[i];
    return (0);
}
