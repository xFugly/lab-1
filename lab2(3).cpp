#include <iostream>
using namespace std;

int main() {
    // 1. Создайте двумерный массив размера 2х3 целых чисел
    int twoDimArray[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    // 2. Выведите сумму всех чисел созданного массива
    int totalSum = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            totalSum += twoDimArray[i][j];
        }
    }
    cout << "Сумма всех чисел: " << totalSum << endl;
    
    // 3. Создайте одномерный массив из 3-х элементов
    int oneDimArray[3];
    
    // 4. В значении массива из предыдущего пункта запишите сумму чисел из столбцов двумерного массива
    for (int j = 0; j < 3; j++) {
        oneDimArray[j] = 0;
        for (int i = 0; i < 2; i++) {
            oneDimArray[j] += twoDimArray[i][j];
        }
    }
    
    // 5. Выведите получившийся одномерный массив в консоль
    cout << "Одномерный массив: ";
    for (int i = 0; i < 3; i++) {
        cout << oneDimArray[i] << " ";
    }
    cout << endl;
    
    // 6. Создайте переменную типа float со значением 20.84
    float originalVar = 20.84f;
    cout << "Переменная типа float создана: " << originalVar << endl;
    
    // 7. Создайте 2 ссылки на созданную переменную
    float &ref1 = originalVar;
    float &ref2 = originalVar;
    cout << "Созданы 2 ссылки ref1 и ref2 на originalVar" << endl;
    
    // 8. Измените значение у ссылки на новое
    ref1 = 30.21f;
    cout << "Изменено значение через ref1 на 30.21" << endl;
    
    // 9. Убедитесь, что переменная и другая ссылка так же поменяли значение, выведя их в консоль
    cout << "   Проверка изменений:" << endl;
    cout << "   originalVar: " << originalVar << endl;
    cout << "   ref1: " << ref1 << endl;
    cout << "   ref2: " << ref2 << endl;
    
    // 10. Создайте функцию, которая принимает число и возвращает 0, если число 0 или отрицательное
    // Либо сумму чисел от 1 до данного числа, если оно положительное
    auto sumSequence = [](int n) -> int {
        if (n <= 0) {
            return 0;
        }
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i;
        }
        return sum;
    };
    
    cout << "   Функция sumSequence создана:" << endl;
    cout << "   sumSequence(-3) = " << sumSequence(-3) << endl;
    cout << "   sumSequence(5) = " << sumSequence(5) << endl;
    
    // 11. Сделайте у созданной функции значение по умолчанию у параметра равное 1
    // Убедитесь, что теперь при вызове этой функции без параметра возвращается 1
    auto sumSequenceDefault = [](int n = 1) -> int {
        if (n <= 0) {
            return 0;
        }
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i;
        }
        return sum;
    };
    
    cout << "   Функция с значением по умолчанию:" << endl;
    cout << "   sumSequenceDefault() = " << sumSequenceDefault() << " (должно быть 1)" << endl;
    cout << "   sumSequenceDefault(4) = " << sumSequenceDefault(4) << " (должно быть 10)" << endl;
    
    // 12. Создайте функцию, которая принимает 4 значения, причём 2 последних передаются по ссылке
    // 13. Внутри функции в первую ссылку запишите сумму первых двух параметров,
    // а во вторую ссылку запишите произведение двух первых параметров
    auto calculateSumAndProduct = [](int a, int b, int &sumRef, int &productRef) -> void {
        sumRef = a + b;
        productRef = a * b;
    };
    
    // 14. Вызовите функцию и убедитесь, что значения переданных переменных по ссылке после вызова функции изменились
    int x = 8, y = 3;
    int sumResult, productResult;
    
    cout << "   Функция с параметрами по ссылке:" << endl;
    cout << "   До вызова: x=" << x << ", y=" << y << endl;
    cout << "   sumResult=" << sumResult << ", productResult=" << productResult << endl;
    
    calculateSumAndProduct(x, y, sumResult, productResult);
    
    cout << "   После вызова: sumResult=" << sumResult << " (должно быть 11)" << endl;
    cout << "   productResult=" << productResult << " (должно быть 24)" << endl;
    
    // 15. Создайте переменную любого типа с любым значением и выведите её
    string message = "Hello World!";
    cout << "   Переменная message: " << message << endl;
    
    // 16. Создайте любой цикл и выведите внутри него переменную из 1-го пункта 3 раза
    // 17. В рамках цикла объявите ещё одну переменную с любым значением
    // 18. Выведите её 3 раза внутри этого цикла
    cout << "16-18. Работа с циклами и областями видимости:" << endl;
    for (int i = 0; i < 3; i++) {
        // 16. Выводим переменную из пункта 1 (сумму массива) 3 раза
        cout << "   Итерация " << i + 1 << " - totalSum: ";
        for (int j = 0; j < 3; j++) {
            cout << totalSum << " ";
        }
        
        // 17. Объявляем переменную внутри цикла
        int innerVar = i * 50;
        
        // 18. Выводим её 3 раза внутри этого цикла
        cout << " || innerVar: ";
        for (int k = 0; k < 3; k++) {
            cout << innerVar << " ";
        }
        cout << endl;
    }
    
    // Попробуйте вывести, созданную переменную внутри цикла, за его пределами
    // Убедитесь, что компилятор выдаёт ошибку
    cout << "Проверка области видимости (раскомментируйте для ошибки):" << endl;
    // cout << innerVar; // ОШИБКА: 'innerVar' was not declared in this scope
    
    return 0;
}