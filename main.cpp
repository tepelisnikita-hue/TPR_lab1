#include <iostream>
#include <locale>
#include <limits>
#include <windows.h>
#include "Keeper.h"
#include "Poet.h"
#include "Novelist.h"
#include "Fantast.h"
#include "BaseException.h"

void showMenu() {
    std::cout << "\n--- МЕНЮ УПРАВЛЕНИЯ ПЕЧАТНЫМИ ИЗДАНИЯМИ ---\n";
    std::cout << "1. Добавить поэта\n";
    std::cout << "2. Добавить романиста\n";
    std::cout << "3. Добавить фантаста\n";
    std::cout << "4. Удалить элемент по индексу\n";
    std::cout << "5. Редактировать элемент по индексу\n";
    std::cout << "6. Вывести все элементы\n";
    std::cout << "7. Сохранить данные в файл\n";
    std::cout << "8. Загрузить данные из файла\n";
    std::cout << "0. Выход\n";
    std::cout << "Выберите пункт: ";
}

int main() {
    // Корректная настройка кодировки консоли для отображения русского языка
    SetConsoleCP(1251);
    SetConsoleOutputCP(65001);
    std::setlocale(LC_ALL, "Russian");

    Keeper keeper;
    int choice = -1;

    while (choice != 0) {
        showMenu();

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Неверный ввод! Введите число.\n";
            continue;
        }

        try {
            switch (choice) {
                case 1: {
                    Poet *p = new Poet();
                    try {
                        p->input();
                        keeper.addEdition(p);
                    } catch (...) {
                        delete p;
                        throw;
                    }
                    break;
                }
                case 2: {
                    Novelist *n = new Novelist();
                    try {
                        n->input();
                        keeper.addEdition(n);
                    } catch (...) {
                        delete n;
                        throw;
                    }
                    break;
                }
                case 3: {
                    Fantast *f = new Fantast();
                    try {
                        f->input();
                        keeper.addEdition(f);
                    } catch (...) {
                        delete f;
                        throw;
                    }
                    break;
                }
                case 4: {
                    int idx;
                    std::cout << "Введите индекс элемента для удаления: ";
                    std::cin >> idx;
                    keeper.removeEdition(idx);
                    break;
                }
                case 5: {
                    int idx;
                    std::cout << "Введите индекс элемента для редактирования: ";
                    std::cin >> idx;
                    keeper.editEdition(idx);
                    break;
                }
                case 6:
                    keeper.showAll();
                    break;
                case 7:
                    keeper.saveData("editions_data.txt");
                    break;
                case 8:
                    keeper.loadData("editions_data.txt");
                    break;
                case 0:
                    std::cout << "Выход из программы.\n";
                    break;
                default:
                    std::cout << "Неверный пункт меню! Попробуйте снова.\n";
            }
        } catch (const BaseException &e) {
            e.printMessage();
        } catch (...) {
            std::cerr << "Произошла неизвестная критическая ошибка!" << std::endl;
        }
    }
    return 0;
}