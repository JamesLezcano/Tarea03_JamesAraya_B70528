#ifndef ExcepcionArchivoNoAbre_H
#define ExcepcionArchivoNoAbre_H
#include <exception>

class ExcepcionArchivoNoAbre : public std::exception
{
    public:
    ExcepcionArchivoNoAbre() noexcept = default;
    ~ExcepcionArchivoNoAbre() = default;

    virtual const char* what() const noexcept {
        return "No se puede abrir archivo";
    }

};
#endif