#ifndef CONTACTO_H
#define CONTACTO_H //guarda

#include <string>
using namespace std;

struct correo{
    string user;
    string domain;
};

struct contactoEmail{
    string nom;
    char sex;
    int edad;
    correo email;
};

void modificaContacto(contactoEmail &);
void leerCorreo(correo &, string, string);
void leerContacto(contactoEmail &, string, char, int, correo);
void imprimeContacto(contactoEmail &);
void imprimeContacto(contactoEmail &);
void borrarContacto(contactoEmail lista[], int &n);

#endif