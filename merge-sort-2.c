#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef int ElementType;

void merge(ElementType*, ElementType*, int, int);
void m_sort(ElementType*, ElementType*, int, int);

void m_sort(ElementType arr[], ElementType tmp_arr[], int left, int right)
{
    if(left < right){
        int center = (left + right)/2;
        m_sort(arr, tmp_arr, left, center);
        m_sort(arr, tmp_arr, center+1, right);
        merge(arr, tmp_arr, left, right);
    }
}

void merge_sort(ElementType arr[], int len)
{
    ElementType* tmp_arr = malloc(len * sizeof(ElementType));
    if(tmp_arr != NULL){
        m_sort(arr, tmp_arr, 0, len - 1);
        free(tmp_arr);
    }
    else{
    }
}

void merge(ElementType arr[], ElementType tmp_arr[], int left, int right)
{
    int center = (left + right)/2;
    int i = left;
    int j = center + 1;
    int t = 0;

    while(1){
        if(i > center && j > right){
            break;
        }
        else if(i > center){
            tmp_arr[t++] = arr[j++];
        }
        else if(j > right){
            tmp_arr[t++] = arr[i++];
        }
        else{
            if(arr[i] > arr[j]){
                tmp_arr[t++] = arr[j++];
            }
            else{
                tmp_arr[t++] = arr[i++];
            }
        }
    }

    assert(t == (right - left + 1));
    /* Copy tmp_arr back.*/
    int m = left;
    int n = 0;
    for(; m < right+1; ++m, ++n){
        arr[m] = tmp_arr[n];
    }
}

int main()
{
    ElementType arr[20] = {1, 9, 0, 3, 5, 8, 2, 6, 4, 10, 19, 16, 15, 20, 65, 26, 7, 11, 22, 17};
    merge_sort(arr, 20);
    int i = 0;
    for(; i < 20; ++i){
        printf("%d\t", arr[i]);
    }
}
