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
        float           meta;
    public:
        Categoria( );
        void            set_nombre( string nombre );
        void            set_frases( vector<string> frases );
        void            set_factor( float factor );
        void            set_meta( float meta );
        string          get_nombre( );
        vector<string>  get_frases( );
        float           get_factor( );
        float           get_meta( );
};

#endif