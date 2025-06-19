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
    int n, mayor, imayor;
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
    mayor=empleados[0].vt;
    imayor=0;
    for (int i=1;i<=n-1;i++) {
        if (empleados[i].vt>mayor) {
            mayor=empleados[i].vt;
            imayor=i;    
        }
    }
    cout<<"El empleado con mayor ventas en el año fue: "<<empleados[imayor].nom<<" y su numero es "<<empleados[imayor].num<<endl<<endl;
    for (int i=0;i<=n-1;i++) {
        if (empleados[i].vt>100) {
            empleados[i].sal=empleados[i].sal*1.10;
            cout<<"El empleado "<<empleados[i].nom<<" por vender mas de 100 unidades durante el año tiene ahora salario de: "<<empleados[i].sal<<endl;
        }
    }
    cout<<endl;
    for (int i=0;i<=n-1;i++) {
        if (empleados[i].ven[11]<30) {
            cout<<"El empleado "<<empleados[i].nom<<" ha tenido ventas inferiores a 30 unidades en el mes de diciembre y su numero es "<<empleados[i].num<<endl;
        }
    }
    cout<<endl;
    return 0;
}