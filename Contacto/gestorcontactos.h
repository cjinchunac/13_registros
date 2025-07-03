#ifndef GESTORCONTACTOS_H
#define GESTORCONTACTOS_H

#include "contacto.h"

// Funciones avanzadas
void modificaContacto(contactoEmail &c);
void borrarContacto(contactoEmail lista[], int &n);
void mostrarPorDominio(contactoEmail lista[], int n);
void buscarPorEmail(contactoEmail lista[], int n);

#endif