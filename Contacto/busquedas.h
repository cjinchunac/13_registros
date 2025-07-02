#ifndef BUSQUEDASCONTACTO_H
#define BUSQUEDASCONTACTO_H //guarda

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

void mostrarPorDominio(contactoEmail lista[], int n);
void buscarPorEmail(contactoEmail lista[], int n);

#endif