#include "gestorcontactos.h"
#include "contacto.h"
#include <iostream>
#include <string>
using namespace std;

void modificaContacto(contactoEmail &c) {
    string nom, user, domain;
    char sex;
    int edad;
    correo email;
    
    cout << "Ingrese los nuevos datos:" << endl;
    cin.ignore();
    cout << "Ingrese el nombre del contacto: "; getline(cin, nom);
    cout << "Ingrese el sexo (M/F): "; cin >> sex;
    cout << "Ingrese la edad: "; cin >> edad;
    cout << "Ingrese el correo electronico (usuario@dominio): " << endl;
    cout << "Ingrese el usuario: "; cin >> user;
    cout << "Ingrese el dominio: "; cin >> domain;
    
    leerCorreo(email, user, domain);
    leerContacto(c, nom, sex, edad, email);
}

void borrarContacto(contactoEmail lista[], int &n) {
    int indice;
    cout << "Ingrese el numero del contacto a borrar (0-" << n-1 << "): ";
    cin >> indice;
    
    if(indice >= 0 && indice < n) {
        cout << "Borrando el siguiente contacto:" << endl;
        imprimeContacto(lista[indice]);
        for(int i = indice; i < n-1; i++) {
            lista[i] = lista[i+1];
        }
        n--;
        cout << "¡Contacto borrado exitosamente!" << endl;
    } else {
        cout << "Indice no valido!" << endl;
    }
}

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
   