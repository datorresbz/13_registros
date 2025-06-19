#include<iostream>
#include<string>
using namespace std;
struct EMP{
    int num;
    string nom;
    float ven[12], sal;
};
int main(){
    EMP EMPLEADOS[100];
    int n;
    cout<<"Ingrese la cantidad de empleados: ";
    cin>>n;
    for(int i=0; i<n; i++){
        cout<<"Ingrese el numero del empleado: ";
        cin>>EMPLEADOS[i].num;
        cout<<"Ingrese el nombre del empleado: ";
        cin.ignore();
        getline(cin,EMPLEADOS[i].nom);
        cout<<"Ingrese las ventas del empleado: ";
        for(int j=0; j<12; j++){
            cin>>EMPLEADOS[i].ven[j];
        }
        cout<<"Ingrese el salario del empleado: ";
        cin>>EMPLEADOS[i].sal;
    }
    for(int i=0; i<n; i++){
        cout<<"Numero del empleado: "<<EMPLEADOS[i].num<<endl;
        cout<<"Nombre del empleado: "<<EMPLEADOS[i].nom<<endl;
        cout<<"Ventas del empleado: "<<endl;
        for(int j=0; j<12; j++){
            cout<<EMPLEADOS[i].ven[j]<<" ";
        }
        cout<<endl;
        cout<<"Salario del empleado: "<<EMPLEADOS[i].sal<<endl<<endl;
    }
    //Parte 2//
    int mayorv, v, indicador;
    mayorv=0;
    for(int i=0; i<n; i++){
        v=0;
        for(int j=0; j<12; j++){
            v=v+EMPLEADOS[i].ven[j];
        }
        if(mayorv<v){
            mayorv=v;
            indicador=i;
        }
    }
    cout<<"Empleado con la mayor venta:"<<endl;
    cout<<"Numero: "<<EMPLEADOS[indicador].num<<endl;
    cout<<"Nombre: "<<EMPLEADOS[indicador].nom<<endl;
    //Parte 3//
    int ventastotales, indice;
        for(int i=0; i<n; i++){
            ventastotales=0;
            for(int j=0; j<12; j++){
                ventastotales=ventastotales+EMPLEADOS[i].ven[j];
           }
           if(ventastotales>100){
                EMPLEADOS[i].sal=EMPLEADOS[i].sal*11/10;
                cout<<"Empleado que recibio aumento:"<<endl;
                cout<<"Numero: "<<EMPLEADOS[i].num<<endl;
                cout<<"Nombre: "<<EMPLEADOS[i].nom<<endl;
                cout<<"Nuevo salario: "<<EMPLEADOS[i].sal<<endl<<endl;
           }
        }
    return 0;
}