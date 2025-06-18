#include <iostream>
#include <string>
using namespace std;
struct EMP {
    int num;
    string nom;
    double ven [12];
    double sal;
    double vt;
};
int main ( ) {
    int n;
    EMP empleados [100];
    cout<<"Ingrese el numero de empleados"<<endl;
    cin>>n;
    for (int i=0;i<=n-1;i++) {
        empleados[i].vt=0;
        cout<<"Ingrese datos del empleado "<<i+1<<": "<<endl;
        cout<<"Numero: ";
        cin>>empleados[i].num;
        cout<<"Nombre: ";
        cin.ignore ();
        getline (cin,empleados[i].nom);
        for (int j=0;j<=11;j++) {
            cout<<"venta "<<j+1<<": ";
            cin>>empleados[i].ven[j];
            empleados[i].vt=empleados[i].vt+empleados[i].ven[j];
        }
        cout<<"Salario: ";
        cin>>empleados[i].sal;
        cout<<endl<<endl; 
    }
    for (int i=0;i<=n-1;i++) {
        cout<<"Empleado "<<i+1<<": "<<endl;
        cout<<"numero: "<<empleados[i].num<<endl;
        cout<<"nombre: "<<empleados[i].nom<<endl;
        cout<<"12 ventas:"<<endl;
        for (int j=0;j<=11;j++) {
            cout<<empleados[i].ven[j]<<" ";
        }
        cout<<endl<<"venta total: "<<empleados[i].vt<<endl;
        cout<<"salario: "<<empleados[i].sal<<endl<<endl;
    } 
    return 0;
}