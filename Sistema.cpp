#include <iostream>
#include "Sistema.h"

using std::cout;
using std::cin;
using std::endl;

void Sistema::InicializarDatos( ) {
    Usuario* usuario1 = new Usuario( "Angel" );
    Usuario* usuario2 = new Usuario( "Katalina" );
    Usuario* usuario3 = new Usuario( "Criqui" );
    Usuario* usuario4 = new Usuario( "Angela" );
    this -> usuarios.push_back( usuario1 );
    this -> usuarios.push_back( usuario2 );
    this -> usuarios.push_back( usuario3 );
    this -> usuarios.push_back( usuario4 );
    string categoria0 = "Salud Fisica";
    string categoria1 = "Productividad";
    string categoria2 = "Salud Mental";
    float    meta1 = 0.90;
    float    meta2 = 0.80;
    float    meta3 = 0.95;
    this -> categorias.push_back( categoria0 );
    this -> categorias.push_back( categoria1 );
    this -> categorias.push_back( categoria2 );
    this -> metas.push_back( meta1 );
    this -> metas.push_back( meta2 );
    this -> metas.push_back( meta3 );
    string frase0_categoria0 = "Recuerda mantener tus horarios de sueño.";
    string frase1_categoria0 = "Pequeños pasos constantes mejoran tu energia.";
    string frase2_categoria0 = "El descanso tambien es parte del progreso.";
    string frase0_categoria1 = "Excelente avance en tus habitos diarios.";
    string frase1_categoria1 = "Tu disciplina esta dando resultados.";
    string frase2_categoria1 = "Organiza tus tiempos y continua avanzando.";
    string frase0_categoria2 = "Respira profundo, todo toma su tiempo.";
    string frase1_categoria2 = "Tu paz mental vale más que la prisa.";
    string frase2_categoria2 = "Reconoce tus emociones y trátate con amabilidad.";
    this -> frases[ 0 ].push_back( frase0_categoria0 );
    this -> frases[ 0 ].push_back( frase1_categoria0 );
    this -> frases[ 0 ].push_back( frase2_categoria0 );
    this -> frases[ 1 ].push_back( frase0_categoria1 );
    this -> frases[ 1 ].push_back( frase1_categoria1 );
    this -> frases[ 1 ].push_back( frase2_categoria1 );
    this -> frases[ 2 ].push_back( frase0_categoria2 );
    this -> frases[ 2 ].push_back( frase1_categoria2 );
    this -> frases[ 2 ].push_back( frase2_categoria2 );
    float factor1 = 1.5;
    float factor2 = 1.2;
    float factor3 = 1.8;
    this -> factores.push_back( factor1 );
    this -> factores.push_back( factor2 );
    this -> factores.push_back( factor3 );
}

Usuario* Sistema::crearUsuario( ) {
    string nombre_usuario;
    cout << "Ingrese su nombre: " << endl;
    cin >> nombre_usuario;
    Usuario* usuario = new Usuario( nombre_usuario );

    return usuario;
}

void Sistema::registrarUsuario( ) {
    Usuario* usuario = this -> crearUsuario( );
    this -> usuarios.push_back( usuario );
}

void Sistema::registrarHabitoUsuario( string nombre_usuario ) {
    bool found = false;
    Usuario* usuario = nullptr;
    for( int i = 0; i < this -> usuarios.size( ) && !found; i++ ) {
        if( this -> usuarios[ i ] -> get_nombre( ) == nombre_usuario ) {
            found = true;
            usuario = this -> usuarios[ i ];
        }
    }

    if( found ) {
        cout << "Ingrese el nombre del habito que desea registrar: " << endl;
        string nombre_habito;
        cin >> nombre_habito;
        cout << "Seleccione la categoria de su habito: " << endl;
        cout << "============ Categorias ============" << endl;
        for( int i = 0; i < this -> categorias.size( ); i++ ) {
            cout << i + 1 << ". " << this -> categorias[ i ] << "." << endl;
        }
        cout << "Ingrese la opcion escogida: " << endl;
        int opc;
        switch( opc ) {
            case 1:
                cout << "Usted escogio la opcion: " << this -> categorias[ opc ] << "." << endl;
                Categoria* categoria = new Categoria( );
                categoria -> set_nombre( this -> categorias[ opc ] );
                categoria -> set_frases( this -> frases[ opc ] );
                categoria -> set_factor( this -> factores[ opc ] );
                categoria -> set_meta( this -> metas[ opc ] );
                Habito* habito = new Habito( nombre_habito, categoria );
                usuario -> registrar_habito( habito );
                cout << "Habito registrado con exito!" << endl;
            case 2: 

            case 3:
            
            default:
                break;
        }
    } else {
        cout << "El usuario ingresado no esta registrado." << endl;
    }
}

void Sistema::verInfoUsuario( string nombre_usuario ) {
    bool found = false;
    Usuario* usuario = nullptr;
    for( int i = 0; i < this -> usuarios.size( ) && !found; i++ ) {
        if( this -> usuarios[ i ] -> get_nombre( ) == nombre_usuario ) {
            found = true;
            usuario = this -> usuarios[ i ];
        }
    }

    if( found ) {
        usuario -> mostrar_resumen( this );
    } else {
        cout << "El usuario ingresado no esta registrado." << endl;
    }

    return;
}

void Sistema::verProgresoUsuario( string nombre_usuario, string nombre_habito ) {
    bool found = false;
    Usuario* usuario = nullptr;
    for( int i = 0; i < this -> usuarios.size( ) && !found; i++ ) {
        if( this -> usuarios[ i ] -> get_nombre( ) == nombre_usuario ) {
            found = true;
            usuario = this -> usuarios[ i ];
        }
    }

    if( found ) {
        usuario -> mostrar_progreso( nombre_habito );
    } else {
        cout << "El usuario ingresado no esta registrado." << endl;
    }

    return;
}

float Sistema::cumplimiento( Usuario* usuario, int index ) {
    float cumplimiento = 0;
    Habito* habito = usuario -> get_habito( index );
    int contador = 0;
    for( int i = 0; i < habito -> get_cumplimiento( ).size( ); i++ ) {
        if( habito -> get_cumplimiento( )[ i ] ) {
            contador++;
        }
    }

    cumplimiento = ( contador / habito -> get_cumplimiento( ).size( ) ) * 100;

    return cumplimiento;
}

float Sistema::promedioEnergia( Usuario* usuario, int index ) {
    float promedioEnergia;
    Habito* habito = usuario -> get_habito( index );
    int contador = 0;
    for( int i = 0; i < habito -> get_nivelEnergia( ).size( ); i++ ) {
        contador += habito -> get_nivelEnergia( )[ i ];
    }

    promedioEnergia = contador / habito -> get_nivelEnergia( ).size( );

    return promedioEnergia;
}

float Sistema::indiceBase( Usuario* usuario, int index ) {
    float indiceBase = ( this -> cumplimiento( usuario, index ) * 0.7 ) + ( this -> promedioEnergia( usuario, index ) * 3.0 );
    
    return indiceBase;
}

float Sistema::indiceFinal( Usuario* usuario, int index ) {
    float indiceFinal;
    Habito* habito = usuario -> get_habito( index );
    float factor = habito -> get_categoria( ) -> get_factor( );
    indiceFinal = this -> indiceBase( usuario, index ) * factor;

    return indiceFinal;
}

Sistema::~Sistema( ) {
    for( int i = 0; i < this -> usuarios.size( ); i++ ) {
        delete this -> usuarios[ i ];
    }
}