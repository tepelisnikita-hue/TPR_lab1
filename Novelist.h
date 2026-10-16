#ifndef NOVELIST_H
#define NOVELIST_H

#include "BaseEdition.h"

class Novelist : public BaseEdition {
private:
    std::string fio;
    int lifeYears;
    std::string works;
    std::string biography;
public:
    Novelist();
    Novelist(std::string f, int years, std::string w, std::string bio);
    Novelist(const Novelist &other);
    ~Novelist() override;

    Novelist &operator=(const Novelist &other);

    void input() override;
    void output() const override;
    void edit() override;
    void save(std::ostream &out) const override;
    void load(std::istream &in) override;
    std::string getType() const override { return "Novelist"; }

    std::string getFio() const { return fio; }
    void setFio(const std::string &f) { fio = f; }

    int getLifeYears() const { return lifeYears; }
    void setLifeYears(int y) { lifeYears = y; }

    std::string getWorks() const { return works; }
    void setWorks(const std::string &w) { works = w; }

    std::string getBiography() const { return biography; }
    void setBiography(const std::string &b) { biography = b; }
};

#endif