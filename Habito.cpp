#include "Habito.h"

Habito::Habito( string nombre, Categoria* categoria ) {
    this -> nombre = nombre;
    this -> categoria = categoria;
}

string Habito::get_nombre( ) {
    return this -> nombre;
}

Categoria* Habito::get_categoria( ) {
    return this -> categoria;
}

void Habito::set_fecha( string fecha ) {
    this -> fechas.push_back( fecha );
}

void Habito::set_cumplimiento( bool cumplimiento ) {
    this -> cumplimiento.push_back( cumplimiento );
}

void Habito::set_nivelEnergia( int nivelEnergia ) {
    this -> nivelEnergia.push_back( nivelEnergia );
}

vector<string> Habito::get_fechas( ) {
    return this -> fechas;
}

vector<bool> Habito::get_cumplimiento( ) {
    return this -> cumplimiento;
}

vector<int> Habito::get_nivelEnergia( ) {
    return this -> nivelEnergia;
}

Habito::~Habito( ) {
    delete this -> categoria;
}