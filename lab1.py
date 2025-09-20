import random
def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr
arr = [random.randint(2, 103) for _ in range(15)]
print("До сортировки:", arr)
print("После сортировки:", selection_sort(arr.copy()))
