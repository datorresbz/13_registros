#include<iostream>
#include "contac.h"
#include "gestorContactos.h"
#define MAX 10
using namespace std;


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
        cout<<"4. Eliminar un contacto"<<endl;
        cout<<"5. Mostrar listado de contactos segun el correro(domain)"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Elige una opcion: "; cin>>op;
        switch(op){
            case 1:
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
                    cout<<"Contacto #"<<i+1<<endl;
                    imprimeContacto(lista[i]);
                    cout<<endl;
                }
                system("pause");
                break;
            case 3:
                modificaContacto(lista, n);
                system("pause");
                break;
            case 4:
                eliminarContacto(lista, n);
                system("pause");
                break;
            case 5:
                mostrarEmailporbusqueda(lista,n);
                system("pause");
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





