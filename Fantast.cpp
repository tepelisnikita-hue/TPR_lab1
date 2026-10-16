#include "Fantast.h"
#include "BaseException.h"
#include <limits>

Fantast::Fantast() {
    std::cout << "[Конструктор] Fantast (по умолчанию) создан" << std::endl;
}

Fantast::Fantast(std::string f, std::string w, std::string films)
    : fio(std::move(f)), works(std::move(w)), filmsAdapted(std::move(films)) {
    std::cout << "[Конструктор] Fantast (с параметрами) создан" << std::endl;
}

Fantast::Fantast(const Fantast &other)
    : fio(other.fio), works(other.works), filmsAdapted(other.filmsAdapted) {
    std::cout << "[Конструктор] Fantast (копирования) создан" << std::endl;
}

Fantast::~Fantast() {
    std::cout << "[Деструктор] Fantast удален" << std::endl;
}

Fantast &Fantast::operator=(const Fantast &other) {
    if (this != &other) {
        fio = other.fio;
        works = other.works;
        filmsAdapted = other.filmsAdapted;
    }
    return *this;
}

void Fantast::input() {
    std::cout << "Введите ФИО фантаста: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, fio);

    std::cout << "Введите произведения: ";
    std::getline(std::cin, works);

    std::cout << "Сняты ли фильмы по книгам (да/нет): ";
    std::getline(std::cin, filmsAdapted);
}

void Fantast::output() const {
    std::cout << "[Фантаст] ФИО: " << fio << ", Произведения: " << works
              << ", Экранизации (фильмы): " << filmsAdapted << std::endl;
}

void Fantast::edit() {
    std::cout << "Редактирование фантаста (оставьте пустым для пропуска):\n";

    std::string s;

    std::cout << "Новое ФИО [" << fio << "]: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, s);
    if (!s.empty()) fio = s;

    std::cout << "Новые произведения [" << works << "]: ";
    std::getline(std::cin, s);
    if (!s.empty()) works = s;

    std::cout << "Экранизации [" << filmsAdapted << "]: ";
    std::getline(std::cin, s);
    if (!s.empty()) filmsAdapted = s;
}

void Fantast::save(std::ostream &out) const {
    out << "Fantast\n" << fio << "\n" << works << "\n" << filmsAdapted << "\n";
}

void Fantast::load(std::istream &in) {
    std::getline(in >> std::ws, fio);
    std::getline(in >> std::ws, works);
    std::getline(in >> std::ws, filmsAdapted);
    if (!in) throw BaseException("Ошибка чтения данных фантаста!");
}