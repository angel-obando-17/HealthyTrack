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
        vector<Usuario*>         usuarios;
        vector<int>              metas;
        vector<float>            factores;
    public:
        Sistema( ) = default;
        void InicializarDatos( );
        Usuario* crearUsuario( );
        void registrarUsuario( );
        Usuario* buscarUsuario( string nombre_usuario );
        void registrarHabitoUsuario( string nombre_usuario );
        void registrarProgresoUsuario( string nombre_usuario );
        void verInfoUsuario( string nombre_usuario );
        void verProgresoUsuario( string nombre_usuario );
        void mostrarInfoUsuarios( );
        float cumplimiento( Usuario* usuario, int index );
        float promedioEnergia( Usuario* usuario, int index );
        float indiceBase( Usuario* usuario, int index );
        float indiceFinal( Usuario* usuario, int index );
        virtual ~Sistema( );
};

#endif