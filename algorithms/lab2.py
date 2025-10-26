import math

#Задание 1
def print_numbers(n):
    def start(current):
        if current > n:
            return
        print(current, end='')
        start(current + 1)
    
    start(1)

#Задание 2
def print_range(A, B):
    def start(current):
        print(current, end=' ')
        if A < B:
            if current < B:
                start(current + 1)
        else:
            if current > B:
                start(current - 1)
    
    start(A)
    print()

#Задание 3
def sum(N):
    if N < 10:
        return N
    return N % 10 + sum(N // 10)

#Задание 4
def factors(n):
    def find(num, div):
        if div * div > num:
            return num
        if num % div == 0:
            return div
        return find(num, div + 1)
    
    def factorize(num):
        if num == 1:
            return
        factor = find(num, 2)
        print(factor, end=' ')
        factorize(num // factor)
    
    factorize(n)
    print()