from insertion_sort import insertion_sort
from merge_sort import merge_sort

def tim_sort(arr, transition):
    if len(arr) > 1:
        if len(arr) <= transition:
            insertion_sort(arr)
            return

        # Finding the mid of the array
        mid = len(arr) // 2

        # Dividing the array elements
        L = arr[:mid]

        # into 2 halves
        R = arr[mid:]

        # Sorting the first half
        tim_sort(L, transition)
    
        # Sorting the second half
        tim_sort(R, transition) 

        i = j = k = 0

        # Copy data to temp arrays L[] and R[]
        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1

        # Checking if any element was left
        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1

        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1

def main():
    arr = [9, 4, 0, 1, 9, 0, 1, 8, 9, 0]
    print(f"Array before sorting: {arr}")
    tim_sort(arr, 3)
    print(f"Array after sorting: {arr}")

if __name__ == "__main__":
    main()