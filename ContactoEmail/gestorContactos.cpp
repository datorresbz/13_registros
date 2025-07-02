#include "gestorContactos.h"
#include <iostream>
#include <string>
using namespace std;
void modificaContacto(contactoEmail lista[], int n) {
    int posicion;
    string nom, user, domain;
    char sex;
    int edad;
    
    cout<<"Ingrese la posicion del contacto a modificar (1 - "<<n<<"): ";
    cin>>posicion;
    cin.ignore();
    cout<<"Ingrese el nuevo nombre: "; getline(cin, nom);
    cout<<"Ingrese el nuevo sexo (M/F): "; cin>>sex;
    cout<<"Ingrese la nueva edad: "; cin>>edad;
    cout<<"Ingrese el nuevo correo electronico:"<<endl;
    cout<<"\tUsuario: "; cin>>user;
    cout<<"\tDominio: "; cin>>domain;

    leerCorreo(lista[posicion-1].email, user, domain);
    leerContacto(lista[posicion-1], nom, sex, edad, lista[posicion-1].email);

    cout<<"Contacto modificado exitosamente!"<<endl;
}
void eliminarContacto(contactoEmail lista[],int &n){
    int posicion;
    cout<<"Que contacto desea borrar?"<<endl;
    for(int i=0;i<n;i++){
        cout<<i+1<<". "<<lista[i].nom<<endl;
    }
    cin>>posicion;
    for(int i=posicion-1;i<n-1;i++){
        lista[i]=lista[i+1];    
    }
    n--;
}
void mostrarEmailporbusqueda(contactoEmail lista[],int n){
    cout<<"Ingrese el email a buscar y mostrar: ";
    string email;
    cin>>email;
    for(int i=0;i<n;i++){
        if(lista[i].email.domain==email){
            imprimeContacto(lista[i]);
            cout<<endl;
        }
    }
}