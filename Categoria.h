#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class Categoria {
    private:
        string          nombre;
        vector<string>  frases;
        float           factor;
    public:
        Categoria( );
        void            set_nombre( string nombre );
        void            set_frases( vector<string> frases );
        void            set_factor( float factor );
        string          get_nombre( );
        vector<string>  get_frases( );
        float           get_factor( );
};

#endif