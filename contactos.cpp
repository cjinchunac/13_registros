#include<iostream>
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
void borrarContacto(contactoEmail lista[], int &n);

int main(){
    int n, op;
    string nom, user, domain;
    char sex;
    int edad;
    correo email;
    contactoEmail cont, lista[100];
    n = 0;
    do{
        system("cls");
        cout<<"Menu de opciones -------------------------"<<endl;
        cout<<"1. Agregar contacto"<<endl;
        cout<<"2. Mostrar contactos"<<endl;
        cout<<"3. Modificar contactos"<<endl;
        cout<<"4. Borrar contacto"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Elige una opcion: "; cin>>op;
        switch(op){
            case 1:
                cout<<"Ingrese los datos de un usuario: "<<endl;
                cin.ignore();
                cout<<"Ingrese el nombre del contacto: "; getline(cin,nom);
                cout<<"Ingrese el sexo (M/F): "; cin>>sex;
                cout<<"Ingrese la edad: "; cin>>edad;
                cout<<"Ingrese el correo electronico (usuario@dominio): "<<endl;
                cout<<"\tIngrese el usuario: "; cin>>user;
                cout<<"\tIngrese el dominio: "; cin>>domain;
                
                leerCorreo(email,user,domain);
                leerContacto(cont,nom,sex,edad,email);
                //imprimeContacto(cont);

                lista[n] = cont;
                n++;
                system("pause");
                break;
            case 2:
                for(int i = 0; i < n; i++){
                    cout<<"Contacto #"<<i<<endl;
                    imprimeContacto(lista[i]);
                    cout<<endl;
                }
                system("pause");
                break;
            case 3:
                if(n == 0) {
                cout << "No hay contactos para modificar." << endl;
                } 
                else {
                int indice;
                cout << "Ingrese el numero del contacto a modificar (0-" << n-1 << "): ";
                cin >> indice;

                if(indice >= 0 && indice < n) {
                cout << "Datos actuales del contacto #"<<indice<<":"<<endl;
                cout<<endl<<"Ingrese nuevos datos de contacto"<<endl;
                imprimeContacto(lista[indice]);
                modificaContacto(lista[indice]);
                cout << "Contacto modificado exitosamente!" << endl;
                } 
                else {
                cout << "Indice no valido!" << endl;
                }
                }
                system("pause");
            break;
            case 4:
                if(n == 0) {
                    cout << "No hay contactos para borrar." << endl;
                } else {
                    borrarContacto(lista, n);
                }
                system("pause");
                break;
            case 0:
                cout<<"Esta seguro de salir? (S/N): ";
                break;
            default:
                cout<<"Opcion no valida!"<<endl;
                system("pause");
                break;
        }
    } while(op != 0);
    return 0;
}

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