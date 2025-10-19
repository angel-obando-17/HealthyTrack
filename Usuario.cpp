#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Sistema.h"
#include "Usuario.h"

using std::cout;
using std::cin;
using std::endl;
using std::srand;
using std::rand;
using std::time;

Usuario::Usuario( string nombre ) {
    this -> nombre = nombre;
}

string Usuario::get_nombre( ) {
    return this -> nombre;
}

void Usuario::registrar_habito( Habito* habito ) {
    this -> habitos.push_back( habito );
}

Habito* Usuario::get_habito( int index ) {
    if( index < 0 || index >= this -> habitos.size( ) ) {
        cout << "Error: Indice no valido." << endl;
        return nullptr;
    }

    return this -> habitos[ index ];
}

void Usuario::mostrar_resumen( Sistema* sistema ) {
    srand( time( 0 ) );
    cout << "Usuario: " << this -> nombre << endl;
    cout << "Habitos registrados: " << endl;
    for( int i = 0; i < this -> habitos.size( ); i++ ) {
        int MAX = this -> habitos[ i ] -> get_categoria( ) -> get_frases( ).size( ); 
        cout << "- Habito: " << this -> habitos[ i ] -> get_nombre( ) << " | Categoria: " << 
        this -> habitos[ i ] -> get_categoria( ) -> get_nombre( ) << " | Indice: " << 
        sistema -> indiceFinal( this, i ) <<
        " | Recomendacion: " << this -> habitos[ i ] -> get_categoria( ) -> get_frases( )[ rand( ) % MAX ] << endl;
    }

    return;
}

void Usuario::registrar_progreso( string nombre_habito ) {
    bool found = false;
    Habito* habito = nullptr;
    for( int i = 0; i < this -> habitos.size( ) && !found; i++ ) {
        if( this -> habitos[ i ] -> get_nombre( ) == nombre_habito ) {
            found = true;
            habito = this -> habitos[ i ];
        }
    }

    if( found ) {
        string fecha;
        string cumplimiento_string;
        bool cumplimiento;
        int nivelEnergia;
        cout << "Ingresar fecha: " << endl;
        cin >> fecha;
        cout << "¿Cumpliste con el proposito? ( Digite 'true' or 'false' ): ";
        cin >> cumplimiento_string;
        if( cumplimiento_string == "true" ) {
            cumplimiento = true;
        } else {
            cumplimiento = false;
        }
        cout << "¿Cual fue tu nivel de Energia? ( Digite un numero entre 1 y 10 ): " << endl;
        cin >> nivelEnergia;
        habito -> set_fecha( fecha );
        habito -> set_cumplimiento( cumplimiento );
        habito -> set_nivelEnergia( nivelEnergia );
        cout << "Progreso registrado con exito!\n" << endl;
    } else {
        cout << "Habito seleccionado no registrado." << endl;
    }

    return;
}

void Usuario::mostrar_progreso( string nombre_habito ) {
    bool found = false;
    Habito* habito = nullptr;
    for( int i = 0; i < this -> habitos.size( ) && !found; i++ ) {
        if( this -> habitos[ i ] -> get_nombre( ) == nombre_habito ) {
            found = true;
            habito = this -> habitos[ i ];
        }
    }

    if( found ) {
        cout << "Progreso del Habito: " << habito -> get_nombre( ) << endl;
        cout << "\nFecha          |     Cumplido     |     Nivel de Energia" << endl;
        for( int i = 0; i < habito -> get_fechas( ).size( ); i++ ) {
            cout << habito -> get_fechas( )[ i ] << "     |     " << 
            ( habito -> get_cumplimiento( )[ i ] ? "true         |             " : "false        |             " ) <<
            habito -> get_nivelEnergia( )[ i ] << endl;
        }
    } else {
        cout << "Habito seleccionado no registrado." << endl;
    }

    return;
}

Usuario::~Usuario( ) {
    for( int i = 0; i < this -> habitos.size( ); i++ ) {
        delete this -> habitos[ i ];
    }
}