#ifndef KEEPER_H
#define KEEPER_H

#include "BaseEdition.h"
#include <string>

class Keeper {
private:
    BaseEdition **data;
    int size;
public:
    Keeper();
    ~Keeper();

    Keeper(const Keeper &) = delete;
    Keeper &operator=(const Keeper &) = delete;

    void addEdition(BaseEdition *edition);
    void removeEdition(int index);
    void editEdition(int index);
    void showAll() const;
    void saveData(const std::string &filename) const;
    void loadData(const std::string &filename);

    int getSize() const { return size; }
};

#endif