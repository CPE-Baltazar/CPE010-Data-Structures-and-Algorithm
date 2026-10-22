#ifndef SORTINGALGO2_H
#define SORTINGALGO2_H
/* 
shellSort(array, size)
    for interval i <= size/2n down to 1
        for each interval "i" in array
            sort all the elements at interval "i"
end shellsort
*/
template <typename T>
void shellSort(T arr[], int size){
    int interval = size / 2;
    while (interval >= 1) {
        for (int i = interval; i < size; i++) {
            T temp = arr[i];
            int j = i;
            while (j >= interval && arr[j - interval] > temp) {
                arr[j] = arr[j - interval];
                j = j - interval;
            }
            arr[j] = temp;
        }
        interval = interval / 2;
    }
}

/* 
Declare an array Arr of length N
If N=1, Arr is already sorted
If N>1,
Left = 0, right = N-1
Find middle = (left + right)/2
Call merge_sort(Arr,left,middle) =>sort first half recursively
Call merge_sort(Arr,middle+1,right) => sort second half recursively
Call merge(Arr, left, middle, right) to merge sorted arrays in above steps.
Exit
*/
template <typename T>
void merge(T array[],int left,int middle,int right,int maxSize){
    T temp[maxSize];
    int i = left;
    int j = middle + 1;
    int k = left;
    while(i <= middle && j <= right){
        if (array[i] < array[j]) {
            temp[k] = array[i];
            i++;
        }else {
            temp[k] = array[j];
            j++;
        }
        k++;
    }
    while(i <= middle){temp[k] = array[i]; i++; k++;}
    while(j <= right){temp[k] = array[j]; j++; k++;}

    for(int x = left; x <= right; x++){
        array[x] = temp[x];
    }
}

template <typename T>
void mergeSort(T array[],int left,int right,int maxSize){
    if(left < right) {
        int middle = (left + right) / 2;
        mergeSort(array, left, middle, maxSize);
        mergeSort(array, middle + 1, right, maxSize);
        merge(array, left, middle, right, maxSize);
    }
}

/*
quicksort(A, low, high)
begin
Declare array A[N] to be sorted
    low = 1st element; high = last element; pivot
if(low < high)
    begin
    pivot = partition (A,low,high);
    quicksort(A,low,pivot-1)
    quicksort(A,pivot+1,high)
    End
end
*/
template <typename T>
int partition(T array[], int low, int high) {
    T pivotValue = array[high];
    int position = low;

    for(int i = low; i < high; i++){
        if (array[i] < pivotValue) {
            std::swap(array[i], array[position]);
            position++;
        }
    }
    std::swap(array[position], array[high]);

    return position;
}

template <typename T>
void quickSort(T array[], int low, int high) {
    if(low < high){
        int pivot = partition(array, low, high);

        quickSort(array, low, pivot - 1);
        quickSort(array, pivot + 1, high);
    }
}

#endif