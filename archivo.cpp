#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>

using namespace std;
const char *nombre_archivo="archivo.dat";
struct Estudiante{
int codigo;
char nombres[50];
char apellidos[50];
int telefono;
};
void abrir();
void ingresar();
void buscar_indice();
void modificar();
void buscar_codigo();
void eliminar();
main(){
	abrir();
	ingresar();
buscar_indice();
modificar();
   buscar_codigo();
    eliminar();

}
void abrir(){
	system("cls");
	FILE* archivo=fopen(nombre_archivo,"rb");
	if(!archivo){
		archivo=fopen(nombre_archivo,"w+b");;
	}
	
	Estudiante estudiante;
	int registro=0;
fread(&estudiante,sizeof(Estudiante),1,archivo);
cout<<"_____________________________"<<endl;
cout<<"id"<<" codigo"<<"       Nombres      "<<"   apellidos   "<<"     telefono    "<<endl;
do{
	cout<<registro<<"  |  "<<estudiante.codigo<<" | "<<estudiante.nombres<<" | "<<estudiante.apellidos<<" | "<<estudiante.telefono<<endl;
	fread(&estudiante,sizeof(Estudiante),1,archivo);
registro+=1;	
} while(feof(archivo)==0); 
cout<<endl;
fclose(archivo);	
system("pause");	
	
}
void ingresar(){
char continuar;
FILE* archivo=fopen(nombre_archivo,"ab");
Estudiante estudiante;
string nombre,apellido;	
do{
	fflush(stdin);
	system("cls");
cout<<"ingrese el codigo:";
cin>>estudiante.codigo;
cin.ignore();
cout<<"ingrese los nombres:";
getline(cin,nombre);
strcpy(estudiante.nombres,nombre.c_str());
cout<<"ingrese los apellidos:";
getline(cin,apellido);
strcpy(estudiante.apellidos,apellido.c_str());
cout<<"ingrese el telefono:";
cin>>estudiante.telefono;
fwrite(&estudiante,sizeof(Estudiante),1,archivo);

	cout<<"desea agregar otro nombre (s/n):";
	cin>>continuar;
}while(continuar=='s'||continuar=='S');
fclose(archivo);
abrir();
}
void buscar_indice(){
FILE* archivo=fopen(nombre_archivo,"rb");
int pos=0;
cout<<"que resistro desea viasualizar (id):";
cin>>pos;	
fseek(archivo,pos * sizeof(Estudiante),SEEK_SET);
Estudiante estudiante;
fread(&estudiante,sizeof(Estudiante),1,archivo);
cout<<"codigo: "<<estudiante.codigo<<endl;
cout<<"nombres:"<<estudiante.nombres<<endl;
cout<<"apellido:"<<estudiante.apellidos<<endl;
cout<<"telefono:"<<estudiante.telefono<<endl;
fclose(archivo);
}
void modificar(){
	FILE* archivo=fopen(nombre_archivo,"r+b");
	string nombre,apellido;
	Estudiante estudiante;
	int id=0;
cout<<"que resistro desea modificar (id):";
cin>>id;
fseek(archivo,id * sizeof(Estudiante),SEEK_SET);
cout<<"ingrese nuevo codigo: ";
cin>>estudiante.codigo;
cin.ignore();
cout<<"ingrese nuevo nombres: ";
getline(cin,nombre);
strcpy(estudiante.nombres,nombre.c_str());	
cout<<"ingrese nuevo apellidos: ";
getline(cin,apellido);
strcpy(estudiante.apellidos,apellido.c_str());
cout<<"ingrese nuevo telefono: ";
cin>>estudiante.telefono;	
fwrite(&estudiante,sizeof(Estudiante ),1,archivo);
fclose(archivo);
system("pause");
abrir();
}
void buscar_codigo(){
FILE* archivo=fopen(nombre_archivo,"rb");	
int indice=0,pos=0,cod=0;
cout<<"buscar codigo:";
cin>>cod;
Estudiante estudiante;
fread(&estudiante,sizeof(Estudiante),1,archivo);
	do{
		if(estudiante.codigo==cod){
        pos = indice;
		}
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		indice+=1;
	}while(feof(archivo)==0);
	cout<<"____________"<<pos<<"________________"<<endl;
	fseek(archivo,pos * sizeof(Estudiante),SEEK_SET);
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	cout<<"codigo: "<<estudiante.codigo<<endl;
cout<<"nombres:"<<estudiante.nombres<<endl;
cout<<"apellido:"<<estudiante.apellidos<<endl;
cout<<"telefono:"<<estudiante.telefono<<endl;
fclose(archivo);
system("pause");
}
void eliminar(){
    
    
    int pos=0;
    cout<<"\nIngresa el codigo a eliminar: "<<endl;
    cin>>pos;
      
    FILE* archivo = fopen(nombre_archivo, "rb");
	FILE* archivo2 = fopen("auxi.dat", "a+b");
    Estudiante estudiante;
    fread ( &estudiante, sizeof(Estudiante), 1, archivo );

	while (feof( archivo ) == 0){
    
	if (pos == estudiante.codigo){
        cout<<"Registro Eliminado"<<endl;
        cout<<endl;
    } else
        fwrite( &estudiante, sizeof(Estudiante), 1, archivo2 );
    fread ( &estudiante, sizeof(Estudiante), 1, archivo );
    
    }
    fclose(archivo);
    fclose(archivo2);
    remove("archivo.dat");
    rename("auxi.dat","archivo.dat");
    system("pause");
	abrir();

}

