#ifndef ExcepcionErrorEnTXT_H
#define ExcepcionErrorEnTXT_H
#include <exception>

class ExcepcionErrorEnTXT : public std::exception
{
    public:
    ExcepcionErrorEnTXT() noexcept = default;
    ~ExcepcionErrorEnTXT() = default;

    virtual const char* what() const noexcept {
        return "Error en datos del TXT";
    }

};
#endif