#ifndef LECTOR_TXT
#define LECTOR_TXT

#include <string>
#include <fstream>
using namespace std;

class Lector_txt {
    string personas;
    public:
    Lector_txt(string);
    void lectorPersonas(string);
};

#endif