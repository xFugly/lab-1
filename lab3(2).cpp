#include <iostream>
using namespace std;

// 1. Создайте функцию, которая принимает 2 указателя (на начало и конец массива) 
// и которая возвращает сумму всех элементов массива.
int arraySum(int* begin, int* end) {
    int total = 0;
    for (int* ptr = begin; ptr != end; ++ptr) {
        total += *ptr;
    }
    return total;
}

// 3. Создайте 2 функции, принимающих 2 параметра и возвращающих их сумму и их разность соответственно.
int sum(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

// 4. Создайте функцию, принимающую 1 параметр типа char.
// 5. Созданная функция должна возвращать указатель на одну из двух функций (суммы или разности)
int (*getOperation(char op))(int, int) {
    if (op == '+') {
        return &sum;
    } else if (op == '-') {
        return &subtract;
    } else {
        return nullptr;
    }
}

int main() {
    cout << "=== Пункт 1-2 ===" << endl;
    // 2. Проверьте правильность работы функции, вызвав её и передав массив из нескольких чисел.
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    int result = arraySum(numbers, numbers + size);
    cout << "Сумма элементов массива: " << result << " (должно быть 15)" << endl;
    
    cout << "\n=== Пункт 3-6 ===" << endl;
    // 6. Проверьте работу созданных функций, вызвав сначала ту, что возвращает указатель,
    // а потом вызвав и эту функцию по указателю
    cout << "Проверка функций суммы и разности:" << endl;
    cout << "sum(8, 3) = " << sum(8, 3) << endl;
    cout << "subtract(8, 3) = " << subtract(8, 3) << endl;
    
    // Получаем указатель на функцию суммы
    int (*operationPtr)(int, int) = getOperation('+');
    if (operationPtr != nullptr) {
        int result1 = operationPtr(15, 7);
        cout << "Через указатель на сумму: 15 + 7 = " << result1 << endl;
    }
    
    // Получаем указатель на функцию разности
    operationPtr = getOperation('-');
    if (operationPtr != nullptr) {
        int result2 = operationPtr(15, 7);
        cout << "Через указатель на разность: 15 - 7 = " << result2 << endl;
    }
    
    cout << "\n=== Пункт 7-8 ===" << endl;
    // 7. Создайте динамический указатель типа float.
    float* dynamicFloat = new float(20.84f);
    
    // 8. Выведите его в консоль, а после удалите его из памяти с помощью delete.
    cout << "Динамический указатель:" << endl;
    cout << "Адрес указателя: " << &dynamicFloat << endl;
    cout << "Адрес в динамической памяти: " << dynamicFloat << endl;
    cout << "Значение: " << *dynamicFloat << endl;
    
    // Удаляем из памяти
    delete dynamicFloat;
    dynamicFloat = nullptr;
    
    cout << "Память освобождена, указатель обнулен" << endl;
    
    return 0;
}