#include <iostream>
#include <iomanip>
using namespace std;


#ifndef SORTARRAY_H_INCLUDED
#define SORTARRAY_H_INCLUDED


void swap1(int &a, int &b){
    if(a!=b){
        int t = a;
        a = b;
        b = t;
    }
}

void printArray(int a[], int n){
    for(int i =0;i<n;i++){
        cout << "  " <<a[i];
    }
        cout<<endl;

}
void scanArray (int *a, int n){
    cout << "array with "<<n<<" elements\n";
    for(int i =0;i<n;i++){
        cout << "A["<<i<<"]=";
        cin >>a[i];
    }
}

void bubbleSort(int  *arr, int size) {
    int i, j, tmp;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap1(arr[j],arr[j+1]);
            }

        }
    }
     cout<<"The sorted array using bubbleSort is :\n";
       printArray(arr,5);

}



void insertionSort(int arr[], int size) {
    int i, j, temp;

    for (i = 1; i < size; i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
     cout<<"The sorted array using insertionSort is :\n";
           printArray(arr,5);

}

void selectionSort(int arr[], int size) {
    int i, j, minIndex, temp;

    for (i = 0; i < size - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
     cout<<"The sorted array using selectionSort is :\n";

       printArray(arr,5);

    cout<<endl;
}
void menu(){
    system("pause");
    system("cls");
    cout<<"Press 1 for bubbleSort : \n";
    cout<<"Press 2 for insetionSort : \n";
    cout<<"Press 3 for selectionSort : \n";
    cout << "Press 4 for quickSort : \n";
    cout << "Press 5 for mergeSort : \n";
    cout<<"Press 0 for Exit : \n";
    cout<<"whats your choice?  \n";

}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int leftArr[n1];
    int rightArr[n2];

    // Copy data to temporary arrays leftArr[] and rightArr[]
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if there are any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if there are any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Same as (left + right) / 2, but avoids overflow for large left and right
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/*

struct node{
int Data;
node *next;
};


node *head =nullptr;
void insertHead(int data){
    node *liste = new node;
    liste->Data = data;
    liste->next = head;
}

void swaptr(node *a,node *b){
   int t=a->Data;
   a->Data=b->Data;
   b->Data=t;
}
node *current=head;
void printlist(current){
while(current){
    cout<< current->Data;
    current =  current->next;
}
}
*/
#endif // SORTARRAY_H_INCLUDED
