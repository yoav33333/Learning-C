#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int minrun_length(int n) {
    int r = 0;
    while (n >= 64) {
        r |= n & 1;
        n >>= 1;
    }
    return n + r;
}

void insertion_sort(int arr[], int left, int right) {
    for (int i = left + 1; i < right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int left, int mid, int right) {
    int len1 = mid - left;
    int len2 = right - mid;

    int *leftArr = (int *)malloc(len1 * sizeof(int));
    int *rightArr = (int *)malloc(len2 * sizeof(int));

    for (int i = 0; i < len1; i++) leftArr[i] = arr[left + i];
    for (int i = 0; i < len2; i++) rightArr[i] = arr[mid + i];

    int i = 0, j = 0, k = left;
    while (i < len1 && j < len2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < len1) arr[k++] = leftArr[i++];
    while (j < len2) arr[k++] = rightArr[j++];

    free(leftArr);
    free(rightArr);
}

void timsort(int arr[], int n) {
    int minrun = minrun_length(n);
    int *runs = (int *)malloc(n * sizeof(int));
    int run_count = 0;

    int i = 0;
    while (i < n) {
        int run_start = i;
        int run_end = i + 1;
        while (run_end < n && arr[run_end] >= arr[run_end - 1]) run_end++;
        while (run_end - run_start < minrun && run_end < n) run_end++;
        insertion_sort(arr, run_start, run_end);
        runs[run_count++] = run_start;
        runs[run_count++] = run_end;
        i = run_end;
    }

    while (run_count > 2) {
        int run1_end = runs[--run_count];
        int run1_start = runs[--run_count];
        int run2_end = runs[--run_count];
        int run2_start = runs[--run_count];
        merge(arr, run2_start, run1_start, run1_end);
        runs[run_count++] = run2_start;
        runs[run_count++] = run1_end;
    }

    free(runs);
}