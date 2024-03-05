def bubbleSort(arr):
    n = len(arr)
    for i in range(n):
        # Last i elements are already in place
        for j in range(0, n-i-1):
            # Traverse the array from 0 to n-i-1
            # Swap if the element found is greater than the next element
            if arr[j] > arr[j+1] :
                arr[j], arr[j+1] = arr[j+1], arr[j]

def printArray(arr):
    for i in range(len(arr)):
        print ("%d" %arr[i], end=" ")
    print()

arr = [64, 34, 25, 12, 22, 11, 90]

print("Unsorted array: ")
printArray(arr)

bubbleSort(arr)

print("Sorted array: ")
printArray(arr)