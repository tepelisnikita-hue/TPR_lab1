#ifndef POET_H
#define POET_H

#include "BaseEdition.h"

class Poet : public BaseEdition {
private:
    std::string fio;
    int lifeYears;
    std::string mainWorks;
public:
    Poet();
    Poet(std::string f, int years, std::string works);
    Poet(const Poet &other);
    ~Poet() override;

    Poet &operator=(const Poet &other);

    void input() override;
    void output() const override;
    void edit() override;
    void save(std::ostream &out) const override;
    void load(std::istream &in) override;
    std::string getType() const override { return "Poet"; }

    std::string getFio() const { return fio; }
    void setFio(const std::string &f) { fio = f; }

    int getLifeYears() const { return lifeYears; }
    void setLifeYears(int y) { lifeYears = y; }

    std::string getMainWorks() const { return mainWorks; }
    void setMainWorks(const std::string &w) { mainWorks = w; }
};

#endif