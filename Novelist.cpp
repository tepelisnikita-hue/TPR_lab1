#include "Novelist.h"
#include "BaseException.h"
#include <limits>

Novelist::Novelist() : lifeYears(0) {
    std::cout << "[Конструктор] Novelist (по умолчанию) создан" << std::endl;
}

Novelist::Novelist(std::string f, int years, std::string w, std::string bio)
    : fio(std::move(f)), lifeYears(years), works(std::move(w)), biography(std::move(bio)) {
    std::cout << "[Конструктор] Novelist (с параметрами) создан" << std::endl;
}

Novelist::Novelist(const Novelist &other)
    : fio(other.fio), lifeYears(other.lifeYears), works(other.works), biography(other.biography) {
    std::cout << "[Конструктор] Novelist (копирования) создан" << std::endl;
}

Novelist::~Novelist() {
    std::cout << "[Деструктор] Novelist удален" << std::endl;
}

Novelist &Novelist::operator=(const Novelist &other) {
    if (this != &other) {
        fio = other.fio;
        lifeYears = other.lifeYears;
        works = other.works;
        biography = other.biography;
    }
    return *this;
}

void Novelist::input() {
    std::cout << "Введите ФИО романиста: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, fio);

    std::cout << "Введите годы жизни: ";
    if (!(std::cin >> lifeYears)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw BaseException("Ошибка: введено не число для годов жизни!");
    }
    if (lifeYears < 0) throw BaseException("Годы жизни не могут быть отрицательными!");

    std::cout << "Введите произведения: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, works);

    std::cout << "Введите краткую биографию: ";
    std::getline(std::cin, biography);
}

void Novelist::output() const {
    std::cout << "[Романист] ФИО: " << fio << ", Годы жизни: " << lifeYears
              << ", Произведения: " << works << ", Биография: " << biography << std::endl;
}

void Novelist::edit() {
    std::cout << "Редактирование романиста (оставьте пустым для пропуска):\n";

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

    std::cout << "Новые произведения [" << works << "]: ";
    std::getline(std::cin, s);
    if (!s.empty()) works = s;

    std::cout << "Новая биография [" << biography << "]: ";
    std::getline(std::cin, s);
    if (!s.empty()) biography = s;
}

void Novelist::save(std::ostream &out) const {
    out << "Novelist\n" << fio << "\n" << lifeYears << "\n" << works << "\n" << biography << "\n";
}

void Novelist::load(std::istream &in) {
    std::getline(in >> std::ws, fio);
    in >> lifeYears;
    in >> std::ws;
    std::getline(in, works);
    std::getline(in >> std::ws, biography);
    if (!in) throw BaseException("Ошибка чтения данных романиста!");
}