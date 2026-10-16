#ifndef FANTAST_H
#define FANTAST_H

#include "BaseEdition.h"

class Fantast : public BaseEdition {
private:
    std::string fio;
    std::string works;
    std::string filmsAdapted;
public:
    Fantast();
    Fantast(std::string f, std::string w, std::string films);
    Fantast(const Fantast &other);
    ~Fantast() override;

    Fantast &operator=(const Fantast &other);

    void input() override;
    void output() const override;
    void edit() override;
    void save(std::ostream &out) const override;
    void load(std::istream &in) override;
    std::string getType() const override { return "Fantast"; }

    std::string getFio() const { return fio; }
    void setFio(const std::string &f) { fio = f; }

    std::string getWorks() const { return works; }
    void setWorks(const std::string &w) { works = w; }

    std::string getFilmsAdapted() const { return filmsAdapted; }
    void setFilmsAdapted(const std::string &f) { filmsAdapted = f; }
};

#endif