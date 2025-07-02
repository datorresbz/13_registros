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

void leerCorreo(correo &, string, string);
void leerContacto(contactoEmail &, string, char, int, correo);
void imprimeContacto(contactoEmail &);
void modificaContacto(contactoEmail[], int);
void eliminarContacto(contactoEmail[],int &);
void mostrarEmailporbusqueda(contactoEmail[], int);
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
        cout<<"5. Buscar contato por domain (usuario@dominio)"<<endl;
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