// dz251.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Завдання 2
//Контейнер - вектор, Тип елементів - Date.Заповнити його елементами.
//Виконати набір дій за допомогою стандартних алгоритмів.Після виконання кожної дії виводити на екран результат.
//
//1.	Знайти в контейнері заданий елемент(алгоритм find())
//2.	Знайти мінімальний елемент і видалити його з контейнера(алгоритм min_element() і метод вектора erase())
//3. знайти елемент із заданим ключем і видалити його з контейнера(алгоритм find() і метод вектора erase())
//4.	Замінити всі минулі дати на поточну(алгоритм replace_if())
//5.	Відсортувати контейнер за спаданням і за зростанням(алгоритм sort()).

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <iterator>
//using namespace std;
//
//// Структура для збереження дати
//struct Date {
//    int day, month, year;
//
//    // Оператор порівняння для сортування (менше)
//    bool operator<(const Date& other) const {
//        if (year != other.year) {
//            return year < other.year;
//        }
//        if (month != other.month) {
//            return month < other.month;
//        }
//        return day < other.day;
//    }
//
//    // Оператор порівняння для сортування (більше)
//    bool operator>(const Date& other) const {
//        if (year != other.year) {
//            return year > other.year;
//        }
//        if (month != other.month) {
//            return month > other.month;
//        }
//        return day > other.day;
//    }
//
//    // Оператор рівності для пошуку
//    bool operator==(const Date& other) const {
//        return day == other.day && month == other.month && year == other.year;
//    }
//};
//
//// Оператор виводу для зручного виведення дати
//ostream& operator<<(ostream& os, const Date& date) {
//    os << date.day << "/" << date.month << "/" << date.year;
//    return os;
//}
//
//int main() {
//    std::vector<Date> dates = {
//        {1, 1, 2000},
//        {2, 2, 2001},
//        {3, 3, 2002},
//        {4, 4, 2003},
//        {5, 5, 2004},
//    };
//
//    // 1. Пошук конкретного елемента (алгоритм find)
//    auto it = find(dates.begin(), dates.end(), Date{ 3, 3, 2002 });
//    if (it != dates.end()) {
//        cout << "Found element: " << *it << endl;
//    }
//    else {
//        cout << "Element not found." << endl;
//    }
//
//    // 2. Пошук мінімального елемента і видалення його з вектора (алгоритм min_element і метод erase)
//    it = min_element(dates.begin(), dates.end());
//    if (it != dates.end()) {
//        cout << "Minimum element: " << *it << endl;
//        dates.erase(it);
//    }
//    else {
//        cout << "No minimum element." << endl;
//    }
//
//    // 3. Пошук елемента за конкретним ключем і видалення його з вектора (алгоритм find_if і метод erase)
//    it = find_if(dates.begin(), dates.end(), [](const Date& d) { return d.year == 2003; });
//    if (it != dates.end()) {
//        cout << "Found element with year 2003: " << *it << endl;
//        dates.erase(it);
//    }
//    else {
//        cout << "No element with year 2003." << endl;
//    }
//
//    // 4. Замінити всі минулі дати на поточну дату (алгоритм replace_if)
//    Date current_date = { 1, 1, 2023 };
//    replace_if(dates.begin(), dates.end(), [current_date](const Date& d) { return d.year < current_date.year; }, current_date);
//    cout << "Replaced all past dates with the current date." << endl;
//
//    // 5. Сортування вектора у спадному і зростаючому порядку (алгоритм sort)
//    sort(dates.begin(), dates.end(), greater<Date>());
//    cout << "Sorted in descending order:" << endl;
//    for (const Date& d : dates) {
//        cout << d << endl;
//    }
//
//    sort(dates.begin(), dates.end());
//    cout << "Sorted in ascending order:" << endl;
//    for (const Date& d : dates) {
//cout << d << endl;
//    }
//
//    return 0;
//}


//Завдання 3
//Створити клас Airplane(літак: номер рейсу, напрямок, поточна кількість пасажирів, максимальна кількість пасажирів)
//
//За допомогою перевантаження операторів реалізувати :
//1. Перевірка на рівність за номером рейсу(операції == , != )
//2. Збільшення і зменшення пасажирів у салоні літака(операції Інкременту, Декременту у префіксній(++і, --i) та постфіксній(і++, i--)  формах)
//3. Порівняння двох літаків за максимально можливою кількістю пасажирів на борту(операції > , >= , < , <= )
//
//	Створити систему(клас Airport), що керує масивом об'єктів (vector < Airplane> schedule): 
//	- Додавання
//	- Видалення
//	- Пошук зазначеного рейсу
//	- Сортування
//	- Посадка, Висадка пасажирів


#include <iostream>
#include <vector>
#include <algorithm>
 using namespace std;

class Airplane {
public:
    int flight_number;
    string direction;
    int current_passengers;
    int max_passengers;

    Airplane(int flight_number, const string& direction, int max_passengers)
        : flight_number(flight_number), direction(direction), max_passengers(max_passengers), current_passengers(0) {}

    bool operator==(const Airplane& other) const {
        return flight_number == other.flight_number;
    }

    bool operator!=(const Airplane& other) const {
        return!(*this == other);
    }

    Airplane& operator++() {
        if (current_passengers < max_passengers) {
            current_passengers++;
        }
        return *this;
    }

    Airplane operator++(int) {
        Airplane tmp(*this);
        operator++();
        return tmp;
    }

    Airplane& operator--() {
        if (current_passengers > 0) {
            current_passengers--;
        }
        return *this;
    }

    Airplane operator--(int) {
        Airplane tmp(*this);
        operator--();
        return tmp;
    }

    bool operator>(const Airplane& other) const {
        return max_passengers > other.max_passengers;
    }

    bool operator>=(const Airplane& other) const {
        return max_passengers >= other.max_passengers;
    }

    bool operator<(const Airplane& other) const {
        return max_passengers < other.max_passengers;
    }

    bool operator<=(const Airplane& other) const {
        return max_passengers <= other.max_passengers;
    }
};

class Airport {
public:
    vector<Airplane> schedule;

    void add(Airplane&& airplane) {
        schedule.push_back(move(airplane));
    }

    void remove(const Airplane& airplane) {
        schedule.erase(std::remove(schedule.begin(), schedule.end(), airplane), schedule.end());
    }

    Airplane* find(int flight_number) {
        for (Airplane& airplane : schedule) {
            if (airplane.flight_number == flight_number) {
                return &airplane;
            }
        }
        return nullptr;
    }

    void sort() {
        std::sort(schedule.begin(), schedule.end(), [](const Airplane& a, const Airplane& b) {
            return a.max_passengers < b.max_passengers;
            });
    }

    void boarding(Airplane& airplane, int passengers) {
        if (passengers <= airplane.max_passengers - airplane.current_passengers) {
            airplane.current_passengers += passengers;
        }
        else {
            cout << "Not enough seats." << endl;
        }
    }

    void disembarkation(Airplane& airplane, int passengers) {
        if (passengers <= airplane.current_passengers) {
            airplane.current_passengers -= passengers;
        }
        else {
            cout << "Not enough passengers." << endl;
        }
    }
};

int main() {
    Airport airport;

    Airplane airplane1(1, "Kyiv-London", 200);
    Airplane airplane2(2, "Kyiv-Paris", 150);
    Airplane airplane3(3, "Kyiv-Warshaw", 250);

    airport.add(move(airplane1));
    airport.add(move(airplane2));
    airport.add(move(airplane3));

    Airplane* airplane = airport.find(2);
    if (airplane) {
        cout << "Found airplane with flight number 2." << endl;
    }

    airport.sort();

    Airplane* airplane_to_board = airport.find(1);
    if (airplane_to_board) {
        airport.boarding(*airplane_to_board, 100);
    }

    Airplane* airplane_to_disembark = airport.find(2);
    if (airplane_to_disembark) {
        airport.disembarkation(*airplane_to_disembark, 50);
    }

    return 0;
}