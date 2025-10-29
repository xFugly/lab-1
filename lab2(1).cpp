#include <iostream>
using namespace std;

int main() {
    // 1. Получить от пользователя 2 числа
    double num1, num2;
    cout << "Введите первое число: ";
    cin >> num1;
    cout << "Введите второе число: ";
    cin >> num2;
    
    // 2. Вывести среднее арифметическое двух введённых чисел в консоль
    double average = (num1 + num2) / 2;
    cout << "Среднее арифметическое: " << average << endl;
    
    // 3. Попросить пользователя ввести знак операции: +, -, * или /
    char operation;
    cout << "Введите знак операции (+, -, *, /): ";
    // 4. Сохранить эту команду в переменную
    cin >> operation;
    
    // 5. Используя условный оператор, выполнить соответствующую операцию
    /*
    double result;
    if (operation == '+') {
        result = num1 + num2;
        cout << "Результат: " << num1 << " + " << num2 << " = " << result << endl;
    }
    else if (operation == '-') {
        result = num1 - num2;
        cout << "Результат: " << num1 << " - " << num2 << " = " << result << endl;
    }
    else if (operation == '*') {
        result = num1 * num2;
        cout << "Результат: " << num1 << " * " << num2 << " = " << result << endl;
    }
    else if (operation == '/') {
        if (num2 != 0) {
            result = num1 / num2;
            cout << "Результат: " << num1 << " / " << num2 << " = " << result << endl;
        }
        else {
            cout << "Ошибка: деление на ноль!" << endl;
        }
    }
    else {
        cout << "Ошибка: неизвестная операция!" << endl;
    }
    */
    
    // 6. Закомментировать код из предыдущего пункта и реализовать его с использованием оператора switch-case
    double result;
    bool validOperation = true; // Флаг для проверки корректности операции
    
    switch (operation) {
        case '+':
            result = num1 + num2;
            cout << "Результат: " << num1 << " + " << num2 << " = " << result << endl;
            break;
            
        case '-':
            result = num1 - num2;
            cout << "Результат: " << num1 << " - " << num2 << " = " << result << endl;
            break;
            
        case '*':
            result = num1 * num2;
            cout << "Результат: " << num1 << " * " << num2 << " = " << result << endl;
            break;
            
        case '/':
            // Проверка деления на ноль
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Результат: " << num1 << " / " << num2 << " = " << result << endl;
            } else {
                cout << "Ошибка: деление на ноль!" << endl;
                validOperation = false;
            }
            break;
            
        default:
            // Обработка неизвестной операции
            cout << "Ошибка: неизвестная операция!" << endl;
            validOperation = false;
            break;
    }
    
    return 0;
}