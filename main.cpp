#include <iostream>
#include "Sistema.h"
#include "Usuario.h"
#include "Habito.h"
#include "Categoria.h"

using std::cout;
using std::cin;
using std::endl;

void menuSistema( Sistema* sistema ) {
    cout << "===== Menu de Sistema =====\n" << endl;
    cout << "1. Mostrar Resumen de Todos los Usuarios." << endl;
    cout << "0. Regresar al Menu Principal." << endl;
    cout << "Seleccione una opcion: " << endl;
    int opc;
    cin >> opc;
    switch( opc ) {
        case 1:
            sistema -> mostrarInfoUsuarios( );
            break;
        default:
            cout << "Regresando al Menu Principal... " << endl;
    }
}

void menuUsuario( Sistema* sistema ) {
    cout << "===== Menu de Usuario =====\n" << endl;
    cout << "1. Registrarse." << endl;
    cout << "2. Registrar Habito." << endl;
    cout << "3. Registrar Progreso." << endl;
    cout << "4. Mostrar Progreso." << endl;
    cout << "5. Mostrar Resumen." << endl;
    cout << "0. Regresar al Menu Principal." << endl;
    cout << "Seleccione una opcion: " << endl;
    int opc;
    string nombre_usuario;
    cin >> opc;
    switch( opc ) {
        case 1:
            sistema -> registrarUsuario( );
            break;
        case 2:
            cout << "Ingrese su nombre de usuario: " << endl;
            cin >> nombre_usuario;
            sistema -> registrarHabitoUsuario( nombre_usuario );
            break;
        case 3:
            cout << "Ingrese su nombre de usuario: " << endl;
            cin >> nombre_usuario;
            sistema -> registrarProgresoUsuario( nombre_usuario );
            break;
        case 4:
            cout << "Ingrese su nombre de usuario: " << endl;
            cin >> nombre_usuario;
            sistema -> verProgresoUsuario( nombre_usuario );
            break;
        case 5:
            cout << "Ingrese su nombre de usuario: " << endl;
            cin >> nombre_usuario;
            sistema -> verInfoUsuario( nombre_usuario );
            break;
        default:
            cout << "Regresando al Menu Principal... " << endl;
            break;
    }
}

void menu( Sistema* sistema ) {
    int opc;
    do {
        cout << "===== Bienvenido a Healthy Track =====\n" << endl;
        cout << "1. Menu de Sistema." << endl;
        cout << "1. Menu de Usuario." << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: " << endl;
            cin >> opc;
        switch( opc ) {
            case 1:
                menuSistema( sistema );
                break;
            case 2:
                menuUsuario( sistema );
                break;
            default:
                cout << "Saliendo del sistema..." << endl;
                break;
        }
    } while( opc != 0 );
}

int main( ) {
    Sistema sistema;
    sistema.InicializarDatos( );
    menu( &sistema );

    return 0;
}