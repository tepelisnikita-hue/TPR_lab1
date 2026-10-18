#include "Keeper.h"
#include "Poet.h"
#include "Novelist.h"
#include "Fantast.h"
#include "BaseException.h"
#include <fstream>
#include <windows.h>

Keeper::Keeper() : data(nullptr), size(0) {
    std::cout << "[Конструктор] Keeper создан" << std::endl;
}

Keeper::~Keeper() {
    for (int i = 0; i < size; ++i) {
        delete data[i];
    }
    delete[] data;
    std::cout << "[Деструктор] Keeper удален" << std::endl;
}

void Keeper::addEdition(BaseEdition *edition) {
    BaseEdition **newData = new BaseEdition*[size + 1];
    for (int i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    newData[size] = edition;
    delete[] data;
    data = newData;
    size++;
}

void Keeper::removeEdition(int index) {
    if (index < 0 || index >= size) {
        throw BaseException("Неверный индекс для удаления элемента!");
    }
    delete data[index];
    BaseEdition **newData = (size > 1) ? new BaseEdition*[size - 1] : nullptr;
    for (int i = 0, j = 0; i < size; ++i) {
        if (i == index) continue;
        newData[j++] = data[i];
    }
    delete[] data;
    data = newData;
    size--;
}

void Keeper::editEdition(int index) {
    if (index < 0 || index >= size) {
        throw BaseException("Неверный индекс для редактирования элемента!");
    }
    data[index]->edit();
}

void Keeper::showAll() const {
    if (size == 0) {
        std::cout << "Хранилище пусто." << std::endl;
        return;
    }
    for (int i = 0; i < size; ++i) {
        std::cout << i << ". ";
        data[i]->output();
    }
}

void Keeper::saveData(const std::string &filename) const {
    char path[MAX_PATH];
    GetModuleFileNameA(NULL, path, MAX_PATH);
    std::string dir(path);
    dir = dir.substr(0, dir.find_last_of("\\") + 1);
    std::string fullPath = dir + filename;

    std::ofstream file(fullPath);
    if (!file.is_open()) throw BaseException("Не удалось открыть файл для записи!");
    file << size << "\n";
    for (int i = 0; i < size; ++i) {
        data[i]->save(file);
    }
    file.close();
    std::cout << "Данные успешно сохранены в файл." << std::endl;
}

void Keeper::loadData(const std::string &filename) {
    char path[MAX_PATH];
    GetModuleFileNameA(NULL, path, MAX_PATH);
    std::string dir(path);
    dir = dir.substr(0, dir.find_last_of("\\") + 1);
    std::string fullPath = dir + filename;

    std::ifstream file(fullPath);
    if (!file.is_open()) throw BaseException("Не удалось открыть файл для чтения!");

    for (int i = 0; i < size; ++i) {
        delete data[i];
    }
    delete[] data;
    data = nullptr;
    size = 0;

    int newSize;
    file >> newSize;
    if (!file || newSize < 0) throw BaseException("Некорректный файл данных!");

    for (int i = 0; i < newSize; ++i) {
        std::string type;
        file >> type;
        file >> std::ws;

        BaseEdition *edition = nullptr;
        if (type == "Poet") {
            edition = new Poet();
        } else if (type == "Novelist") {
            edition = new Novelist();
        } else if (type == "Fantast") {
            edition = new Fantast();
        }

        if (edition) {
            edition->load(file);
            addEdition(edition);
        }
    }
    file.close();
    std::cout << "Данные успешно загружены из файла." << std::endl;
}