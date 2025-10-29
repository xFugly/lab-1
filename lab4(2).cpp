#include <iostream>
#include <string>
using namespace std;

class Weapon {
private:
    string name;
    int damage;
    float weight;

public:
    // Конструктор с параметрами
    Weapon(string weaponName, int weaponDamage, float weaponWeight) 
        : name(weaponName), damage(weaponDamage), weight(weaponWeight) {
        cout << "Создано оружие: " << name << endl;
    }

    // Конструктор без параметров
    Weapon() : Weapon("Стандартный меч", 10, 2.5f) {}

    // 1. Создайте деструктор для класса оружия
    ~Weapon() {
        cout << "=== ДЕСТРУКТОР ВЫЗВАН ===" << endl;
        cout << "Удаляется оружие: " << name << endl;
        cout << "Урон: " << damage << endl;
        cout << "Вес: " << weight << " кг" << endl;
        cout << "=========================" << endl << endl;
    }

    // Метод для вывода информации об оружии
    void displayInfo() const {
        cout << "Оружие: " << name << endl;
        cout << "Урон: " << damage << endl;
        cout << "Вес: " << weight << " кг" << endl;
        cout << "-------------------" << endl;
    }

    // 5. Метод для проверки, сможет ли поднять оружие
    bool isTooHeavy(float maxWeight) const {
        return weight > maxWeight;
    }

    // 6. Метод, возвращающий суммарный вес текущего объекта и переданного
    float getTotalWeight(const Weapon& otherWeapon) const {
        return weight + otherWeapon.weight;
    }

    // 7. Перегрузка метода - принимает просто вес
    float getTotalWeight(float additionalWeight) const {
        return weight + additionalWeight;
    }

    // 8. Переписываем функцию, принимающую объект оружия, чтобы она использовала перегрузку
    float getTotalWeightOptimized(const Weapon& otherWeapon) const {
        return getTotalWeight(otherWeapon.weight);  // Используем перегруженную версию
    }
};

int main() {
    cout << "=== ПУНКТ 1-4: ДЕСТРУКТОРЫ ===" << endl;
    
    // 2. Создайте объект оружия и выведите его переменные в консоль
    cout << "1. Создание обычного объекта:" << endl;
    Weapon sword("Стальной меч", 20, 3.8f);
    sword.displayInfo();
    
    // 3. Создайте динамический объект оружия
    cout << "2. Создание динамического объекта:" << endl;
    Weapon* bow = new Weapon("Лучный лук", 15, 1.5f);
    bow->displayInfo();
    
    // 4. Убедитесь, что в обоих случаях вызывается деструктор
    cout << "3. Удаление динамического объекта:" << endl;
    delete bow;  // Вызываем деструктор для динамического объекта
    
    cout << "4. Конец блока main - вызов деструктора для обычного объекта:" << endl;
    // Деструктор для sword вызовется автоматически при выходе из блока
    
    cout << endl << "=== ПУНКТ 5-9: МЕТОДЫ КЛАССА ===" << endl;
    
    // Создаем объекты для тестирования методов
    Weapon axe("Топор воина", 25, 4.2f);
    Weapon dagger("Легкий кинжал", 8, 0.8f);
    
    cout << "Тестовые объекты:" << endl;
    axe.displayInfo();
    dagger.displayInfo();
    
    // 9. Проверьте работу всех созданных функций класса
    
    // Тестирование метода isTooHeavy (пункт 5)
    cout << "5. Проверка веса оружия:" << endl;
    float maxCarryWeight = 3.0f;
    cout << "Максимальный вес: " << maxCarryWeight << " кг" << endl;
    cout << "Топор слишком тяжелый? " << (axe.isTooHeavy(maxCarryWeight) ? "Да" : "Нет") << endl;
    cout << "Кинжал слишком тяжелый? " << (dagger.isTooHeavy(maxCarryWeight) ? "Да" : "Нет") << endl;
    
    // Тестирование метода getTotalWeight с объектом (пункт 6)
    cout << endl << "6. Суммарный вес двух оружий:" << endl;
    float totalWeight1 = axe.getTotalWeight(dagger);
    cout << "Топор + Кинжал = " << totalWeight1 << " кг" << endl;
    
    // Тестирование перегруженного метода с весом (пункт 7)
    cout << endl << "7. Суммарный вес оружия и дополнительного веса:" << endl;
    float additionalWeight = 2.0f;
    float totalWeight2 = axe.getTotalWeight(additionalWeight);
    cout << "Топор + " << additionalWeight << " кг = " << totalWeight2 << " кг" << endl;
    
    // Тестирование оптимизированного метода (пункт 8)
    cout << endl << "8. Оптимизированный метод суммарного веса:" << endl;
    float totalWeight3 = axe.getTotalWeightOptimized(dagger);
    cout << "Топор + Кинжал (оптимизировано) = " << totalWeight3 << " кг" << endl;
    
    // Дополнительное тестирование
    cout << endl << "9. Дополнительные тесты:" << endl;
    
    // Тест с разными максимальными весами
    float weights[] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    for (float w : weights) {
        cout << "Макс. вес " << w << " кг - Топор слишком тяжелый? " 
             << (axe.isTooHeavy(w) ? "Да" : "Нет") << endl;
    }
    
    cout << endl << "=== КОНЕЦ ПРОГРАММЫ ===" << endl;
    // Деструкторы для axe и dagger вызовутся автоматически здесь
    
    return 0;
}  