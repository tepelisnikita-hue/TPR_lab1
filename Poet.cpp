#include "Poet.h"
#include "BaseException.h"
#include <limits>

Poet::Poet() : lifeYears(0) {
    std::cout << "[Конструктор] Poet (по умолчанию) создан" << std::endl;
}

Poet::Poet(std::string f, int years, std::string works)
    : fio(std::move(f)), lifeYears(years), mainWorks(std::move(works)) {
    std::cout << "[Конструктор] Poet (с параметрами) создан" << std::endl;
}

Poet::Poet(const Poet &other)
    : fio(other.fio), lifeYears(other.lifeYears), mainWorks(other.mainWorks) {
    std::cout << "[Конструктор] Poet (копирования) создан" << std::endl;
}

Poet::~Poet() {
    std::cout << "[Деструктор] Poet удален" << std::endl;
}

Poet &Poet::operator=(const Poet &other) {
    if (this != &other) {
        fio = other.fio;
        lifeYears = other.lifeYears;
        mainWorks = other.mainWorks;
    }
    return *this;
}

void Poet::input() {
    std::cout << "Введите ФИО поэта: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, fio);

    std::cout << "Введите годы жизни: ";
    if (!(std::cin >> lifeYears)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw BaseException("Ошибка: введено не число для годов жизни!");
    }
    if (lifeYears < 0) throw BaseException("Годы жизни не могут быть отрицательными!");

    std::cout << "Введите основные произведения: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, mainWorks);
}

void Poet::output() const {
    std::cout << "[Поэт] ФИО: " << fio << ", Годы жизни: " << lifeYears
              << ", Произведения: " << mainWorks << std::endl;
}

void Poet::edit() {
    std::cout << "Редактирование поэта (оставьте пустым для пропуска поля):\n";

    std::string s;

    std::cout << "Новое ФИО [" << fio << "]: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, s);
    if (!s.empty()) fio = s;

    std::cout << "Новые годы жизни [" << lifeYears << "] (Enter для пропуска): ";
    std::string yearStr;
    std::getline(std::cin, yearStr);
    if (!yearStr.empty()) {
        int y = 0;
        try {
            y = std::stoi(yearStr);
        } catch (...) {
            throw BaseException("Ошибка: некорректный формат числа при редактировании!");
        }
        if (y < 0) throw BaseException("Годы жизни не могут быть отрицательными!");
        lifeYears = y;
    }

    std::cout << "Новые произведения [" << mainWorks << "]: ";
    std::getline(std::cin, s);
    if (!s.empty()) mainWorks = s;
}

void Poet::save(std::ostream &out) const {
    out << "Poet\n" << fio << "\n" << lifeYears << "\n" << mainWorks << "\n";
}

void Poet::load(std::istream &in) {
    std::getline(in >> std::ws, fio);
    in >> lifeYears;
    in >> std::ws;
    std::getline(in, mainWorks);
    if (!in) throw BaseException("Ошибка чтения данных поэта!");
}