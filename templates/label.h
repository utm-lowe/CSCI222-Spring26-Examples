#include <string>

#ifndef LABEL_H
#define LABEL_H


template<typename T> 
class Label
{
public:
    Label(const std::string &label, const T& v)
    {
        this->label = label;
        this->v = v;
    }

    Label(const std::string &label) : Label(label, T())
    {
        // nothing to do here
    }

    std::string getLabel() const
    {
        return label;
    }

    T getValue() const
    {
        return v;
    }

    // Implicit conversion to T references; static_cast works as well.
    operator T&()
    {
        return v;
    }

    operator const T&() const
    {
        return v;
    }

    // assignment copies the value only
    Label<T>& operator=(const T& v)
    {
        this->v = v;
        return *this;
    }

private:
    std::string label;
    T v;
};

template<typename T>
std::ostream& operator<<(std::ostream &os, const Label<T> &l) 
{
    os << l.getLabel() << ": " << l.getValue();
    return os;
}
#endif