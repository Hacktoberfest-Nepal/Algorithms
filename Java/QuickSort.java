package java;

public class QuickSort {
    private int partition(int arr[], int low, int high) {
        // Set Pivot element first
        int pivotEl = arr[high]; // last element
        int i = low - 1;  // lower smaller el;

        for (int j = low; j < high; j++) {
            // if j index el is smaller than pivot
            if (arr[j] < pivotEl) {
                i++;
                // Swap arr[i] and arr[j]
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
        // Swap arr[high] and arr[i + 1]
        int temp0 = arr[high];
        arr[high] = arr[i + 1];
        arr[i + 1] = temp0;

        return i + 1;
    }

    private void sort(int[] arr, int low, int high) {
        if(low < high) {
            // find the pivot index
            int pi = partition(arr, low, high);
            // recursively sort smaller and higher elements than the pivot element
            sort(arr, low, pi - 1);
            sort(arr, pi + 1, high);
        }
    }

    private static void printArray(int arr[]) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
    public static void main(String[] args) {
        int[] myArr = {2, 6, 9, 1, 7, 3};
        QuickSort qObj = new QuickSort();
        qObj.sort(myArr, 0, myArr.length - 1);
        System.out.println("Sorted Array:");
        printArray(myArr);
    }
}