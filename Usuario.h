#ifndef USUARIO_H
#define USUARIO_h

#include <string>
#include <vector>
#include "Habito.h"

using std::string;
using std::vector;

class Usuario {
    private:
        string          nombre;
        vector<Habito*> habitos;
    public:
        Usuario( );
        Usuario( string nombre );
        string  get_nombre( );
        Habito* get_habito( int index );
        void    mostrar_resumen( );
        void    registrar_progreso( );
        void    mostrar_progreso( int index );
        virtual ~Usuario( );
};

#endif