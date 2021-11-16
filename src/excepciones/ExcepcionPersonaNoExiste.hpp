#ifndef ExcepcionLibroNoExiste_H
#define ExcepcionLibroNoExiste_H
#include <exception>

class ExcepcionPersonaNoExiste : public std::exception
{
    public:
    ExcepcionPersonaNoExiste() noexcept = default;
    ~ExcepcionPersonaNoExiste() = default;
    virtual const char* what() const noexcept {
        return "Persona no existe";
    }
};

#endif