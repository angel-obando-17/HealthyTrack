#ifndef HABITO_H
#define HABITO_H

#include <string>
#include <vector>
#include "Categoria.h" 

using std::string;
using std::vector;

class Habito {
    private:
        string          nombre;
        Categoria*      categoria;
        vector<string>  fechas;
        vector<bool>    cumplimiento;
        vector<int>     nivelEnergia;
    public:
        Habito( );
        Habito( string nombre, Categoria* categoria );
        string          get_nombre( );
        Categoria*      get_categoria( );
        vector<string>  get_fechas( );
        vector<bool>    get_cumplimiento( );
        vector<int>     get_nivelEnergia( );
        virtual         ~Habito( );
};

#endif