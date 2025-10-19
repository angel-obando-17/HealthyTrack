#include "Categoria.h"

void Categoria::set_nombre( string nombre ) {
    this -> nombre = nombre;
}

void Categoria::set_frases( vector<string> frases ) {
    this -> frases = frases;
}

void Categoria::set_factor( float factor ) {
    this -> factor = factor;
}

void Categoria::set_meta( float meta ) {
    this -> meta = meta;
}

string Categoria::get_nombre( ) {
    return this -> nombre;
}

vector<string> Categoria::get_frases( ) {
    return this -> frases;
}

float Categoria::get_factor( ) {
    return this -> factor;
}

float Categoria::get_meta( ) {
    return this -> meta;
}