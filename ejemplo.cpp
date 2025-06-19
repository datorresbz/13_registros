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
        cout<<EMPLEADOS[i].num<<endl;
        cout<<EMPLEADOS[i].nom<<endl;
        for(int j=0; j<12; j++){
            cout<<EMPLEADOS[i].ven[j]<<" ";
        }
        cout<<endl;
        cout<<EMPLEADOS[i].sal<<endl<<endl;
    }
    return 0;
}