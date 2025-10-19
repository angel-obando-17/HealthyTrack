#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include "Habito.h"

using std::string;
using std::vector;

class Sistema;

class Usuario {
    private:
        string          nombre;
        vector<Habito*> habitos;
    public:
        Usuario( ) = default;
        Usuario( string nombre );
        string          get_nombre( );
        Habito*         get_habito( int index );
        void            registrar_habito( Habito* habito );
        void            mostrar_resumen( Sistema* sistema );
        void            registrar_progreso( string nombre_habito );
        void            mostrar_progreso( string nombre_habito );
        virtual ~Usuario( );
};

#endif