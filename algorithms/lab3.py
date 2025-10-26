import random
from pprint import pprint

#Задание 1 
def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)

#задание 2 
def sort50(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return sort50(left) + middle + sort50(right)

#Задание 3
def sortmatrix(arr):
    if len(arr) <= 1: return arr
    pivot = arr[len(arr)//2][0]
    left = [x for x in arr if x[0] < pivot]
    middle = [x for x in arr if x[0] == pivot]
    right = [x for x in arr if x[0] > pivot]
    return quick_sort(left) + middle + quick_sort(right)
table = [[random.randint(6, 60) for _ in range(3)] for _ in range(5)]
sorted_table = sortmatrix(table)
pprint(sorted_table, width=20)

#Задание 4
def students(arr):
    arr.sort()
    return arr