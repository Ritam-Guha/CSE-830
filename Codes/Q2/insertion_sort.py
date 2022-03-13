# Function to do insertion sort
def insertion_sort(arr):
    # Traverse through 1 to len(arr)
    for i in range(1, len(arr)):

        key = arr[i]

        # Move elements of arr[0..i-1], that are
        # greater than key, to one position ahead
        # of their current position
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def main():
    arr = [5, 1, 6, 12, 14, 7, 8]
    print(f"Array before sorting: {arr}")
    insertion_sort(arr)
    print(f"Array after sorting: {arr}")

if __name__ == "__main__":
    main()