#include "busquedas.h"
#include <iostream>
#include <string>
using namespace std;

void mostrarPorDominio(contactoEmail lista[], int n) {
    string dominio;
    int contador = 0;
    
    cout << "\n--- CONTACTOS POR DOMINIO ---" << endl;
    cout << "Ingrese el dominio a buscar (ej: gmail.com): ";
    cin >> dominio;
    
    cout << "\nContactos con dominio @" << dominio << ":" << endl;
    for(int i = 0; i < n; i++) {
        if(lista[i].email.domain == dominio) {
            cout << "\nContacto #" << i << endl;
            imprimeContacto(lista[i]);
            contador++;
        }
    }
    
    if(contador == 0) {
        cout << "\nNo se encontraron contactos con ese dominio." << endl;
    } else {
        cout << "\nTotal encontrados: " << contador << endl;
    }
}

void buscarPorEmail(contactoEmail lista[], int n) {
    string usuario, dominio;
    int encontrado = -1;
    
    cout << "\n--- BUSCAR CONTACTO POR EMAIL ---" << endl;
    cout << "Ingrese el email completo (usuario@dominio):" << endl;
    cout << "Usuario: "; cin >> usuario;
    cout << "Dominio: "; cin >> dominio;
    
    for(int i = 0; i < n; i++) {
        if(lista[i].email.user == usuario && lista[i].email.domain == dominio) {
            encontrado = i;
            break;
        }
    }
    
    if(encontrado != -1) {
        cout << "\nContacto encontrado en la posicion #" << encontrado << endl;
        imprimeContacto(lista[encontrado]);
    } else {
        cout << "\nNo se encontro ningun contacto con ese email." << endl;
    }
}
   