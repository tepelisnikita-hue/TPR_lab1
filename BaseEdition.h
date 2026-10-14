#ifndef BASE_EDITION_H
#define BASE_EDITION_H

#include <string>
#include <iostream>

class BaseEdition {
public:
    BaseEdition();
    virtual ~BaseEdition();

    virtual void input() = 0;
    virtual void output() const = 0;
    virtual void edit() = 0;
    virtual void save(std::ostream &out) const = 0;
    virtual void load(std::istream &in) = 0;
    virtual std::string getType() const = 0;
};

#endif