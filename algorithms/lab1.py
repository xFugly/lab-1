# #Задание 1
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
arr = []
for k in range(random.randint(5, 25)):
    arr.append(random.randint(2, 103))
print("До сортировки:", arr)
print("После сортировки:", selection_sort(arr.copy()))

#Задание 2
arr2 = [random.randint(0, 100) for _ in range(5, 25)]
def sort_reverse(arr):
    return sorted(arr)[::-1]
print("до сортировки:", arr2)
print("после сортировки:", sort_reverse(arr2))

#Задание 3
phoness = ["23-45-67", "12-34-56", "98-76-54", "11-11-11", "34-56-78"]
def sort_phone(phones):
    phonesarr = [(int(p.replace('-', '')), p) for p in phones]
    n = len(phonesarr)
    for i in range(n):
        min_index = i
        for j in range(i + 1, n):
            if phonesarr[j][0] < phonesarr[min_index][0]:
                min_index = j
        phonesarr[i], phonesarr[min_index] = phonesarr[min_index], phonesarr[i]
    return [p[1] for p in phonesarr]
print("до сортировки:", phoness)
print("после сортировки:", sort_phone(phoness))