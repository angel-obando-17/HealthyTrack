#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include <vector>
#include "Usuario.h"
#include "Categoria.h"

using std::vector;
using std::string;

class Sistema {
    private:
        vector<string>           categorias;
        vector< vector<string> > frases;
        vector<string>           habitos;
        vector<Usuario*>         usuarios;
    public:
        Sistema( );
        void registrarUsuario( );
        void verInfoUsuario( );
        float cumplimiento( Usuario* usuario );
        float promedioEnergia( Usuario* usuario );
        float indiceBase( Usuario* usuario );
        float indiceFinal( Usuario* usuario );
        Categoria* set_categoria( );
        virtual ~Sistema( );
};

#endif