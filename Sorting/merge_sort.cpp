
#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int mid, int h) {
    
    int m = mid-l+1, n = h-mid;
    int left[m], right[n];
    
    for(int i = 0; i < m  ; i++)
        left[i] = arr[l+i];

    for(int i = 0; i < n; i++)
        right[i] = arr[i+mid+1];
    
    int i = 0, j = 0, k = l ;
    while(i < m and j < n) {
        if(left[i] < right[j]) 
            arr[k++] = left[i++];
        else 
            arr[k++] = right[j++];
    }
    
    while(i < m) arr[k++] = left[i++];
    while(j < n) arr[k++] = right[j++];

}

void merge_sort(int arr[], int l, int h) {
    if(l < h) {
        int m = l + (h -l)/2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, h);
        merge(arr, l, m, h);
    }
}

int main() {
    int arr[] = {3,2,5,1,6,8,9};
    int n = sizeof(arr)/sizeof(int);
    merge_sort(arr, 0, n-1);
    for(int i = 0; i < n; i++) 
        cout<<arr[i] << " ";
}
