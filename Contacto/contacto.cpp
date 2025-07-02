#include "contacto.h"
#include <iostream>
#include <string>
using namespace std;


void leerContacto(contactoEmail &c, string n, char s, int e, correo em){
    c.nom = n;
    c.sex = s;
    c.edad = e;
    c.email = em;
}

void leerCorreo(correo &c, string u, string d){
    c.user = u;
    c.domain = d;
}

void imprimeContacto(contactoEmail &c){
    cout<<"Nombre: "<<c.nom<<endl;
    cout<<"Sexo: "<<c.sex<<endl;
    cout<<"Edad: "<<c.edad<<endl;
    cout<<"Email: "<<c.email.user<<"@"<<c.email.domain<<endl;
}

void modificaContacto(contactoEmail &c) {
    string nom, user, domain;
    char sex;
    int edad;
    correo email;
    
    cout<<"Ingrese los nuevos datos:" << endl;
    cin.ignore();
    cout<<"Ingrese el nombre del contacto: "; getline(cin, nom);
    cout<<"Ingrese el sexo (M/F): "; cin>>sex;
    cout<<"Ingrese la edad: "; cin>>edad;
    cout<<"Ingrese el correo electronico (usuario@dominio): " << endl;
    cout<<"Ingrese el usuario: "; cin>>user;
    cout<<"Ingrese el dominio: "; cin>>domain;
    
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
        n=n-1;
        cout << "¡Contacto borrado exitosamente!" << endl;
    } 
    else {
        cout << "Indice no valido!" << endl;
    }
}
