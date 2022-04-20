#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

struct recursos{
		char nombre[30];
		int codigo;	
		char prestado[30];
	
	};
	
	struct estudiantes{
		char nombre[30];
		int codigo;
		
	};
	
	
	struct prestamo{
		char nombreEstudiante[30];
		int codigoEstudiante;
        char recurso[30];
        int codigo;
	};
	
	
	

	int cu = 0;
	int cr = 0;
	int cp = 0;
	
	vector <recursos> Recursos;
	vector <estudiantes> Estudiantes;
	vector <prestamo> Prestamos;


///adicionar
int adicionar_recurso(){
	
	
	char bf[30];
	char nombre[30];
	int codigo;
	gets(bf);
	cout << "ingrese nombre recurso: ";
	gets(nombre);
	cout << "ingrese codigo: ";
	cin >> codigo;
	recursos save = {"...", codigo,"libre" };
	
	int bol =0;
	if(cr != 0){
		for(int i = 0; i < cr; i++ ){
			if(codigo == Recursos[i].codigo){
				bol = 1;
			}
		}
		
	}
	
	
	if( bol != 1){
		Recursos.push_back(save);
		strcpy(Recursos[cr].nombre, nombre);
		cr++;
	}else{
		cout << "\n el registro no se agrego el codigo ya existe\n ";
	}
	
	
	
	return 0;
}

int adicionar_estudiante(){
	
	char bf[30];
	char nombre[30];
	int codigo;
	gets(bf);
	cout << "ingrese nombre estudiante: ";
	gets(nombre);
	cout << "ingrese codigo: ";
	cin >> codigo;
	estudiantes save = {"...", codigo};
	
	int bol =0;
	if(cu != 0){
		for(int i = 0; i < cu; i++ ){
			if(codigo == Estudiantes[i].codigo){
				bol = 1;
			}
		}
		
	}
	
	
	if( bol != 1){
		Estudiantes.push_back(save);
		strcpy(Estudiantes[cu].nombre, nombre);
		cu++;
	}else{
		cout << "\n el registro no se agrego el codigo ya existe\n";
	}
	

	
}



int consultar_recurso(){
	
	int codigo;
	cout << " \n ingrese el codigo: ";
	cin >> codigo;
	for(int i = 0; i < cr; i++){
		if(Recursos[i].codigo == codigo){
			cout << "Consulta recurso \n";
		    cout << Recursos[i].codigo << "\n";
			cout << Recursos[i].nombre << "\n";
			cout << Recursos[i].prestado << "\n";
			cout << "......................\n";	
		}
	}
}


int consultar_estudiante(){
	
	int codigo;
	cout << " \n ingrese el codigo: ";
	cin >> codigo;
	for(int i = 0; i < cu; i++){
		if(Estudiantes[i].codigo == codigo){
			cout << "Consulta estudiante \n";
		    cout << Estudiantes[i].codigo << "\n";
			cout << Estudiantes[i].nombre << "\n";
			cout << "......................\n";
		}
	}
   
}

int mostrar_recursos(){
    cout << "\n   Consulta recurso  \n";
    cout << "Codigo  -  Nombre  -  estado";
	for(int i = 0; i < cr; i++){
			cout << "\n";
		    cout << Recursos[i].codigo << " - ";
			cout << Recursos[i].nombre << " - ";
			cout << Recursos[i].prestado << "\n";
			
		
	}

}

int eliminar_recursos(){
    
    int codigo;
    cout << "Ingrese el codigo del recurso a eliminar: ";
    cin >> codigo ;
    int puesto ;
	int bol = 0;
    for(int i = 0; i < cr; i++){
        if (Recursos[i].codigo == codigo){
            puesto = i;
        }

		if( (strcmp(Recursos[i].prestado, "Prestado") == 0)   &&  (Recursos[i].codigo == codigo)){
			bol = 1;
		}


    }

    if(bol == 0){
    	Recursos.erase(Recursos.begin() + puesto);
    	cr--;
		cout << "\n\nrecurso borrado\n\n";
	}else{
		cout << "\n\nrecurso esta prestado no se puede eliminar\n\n";

	}

}


int mostrar_estudiantes(){
    cout << "\n Mostrar estudiante \n";
    cout << "Codigo  -  Nombre";
    for(int i = 0; i < cu; i++){
        cout << "\n";
		cout << Estudiantes[i].codigo << " - ";
		cout << Estudiantes[i].nombre << "\n";
		//cout << "......................\n";
		
	}
}

int prestamo_recursos(){
    int codigor;
    int codigoe;
    cout << "codigo recurso a prestar: ";
    cin >> codigor;
    cout << "codigo estudiante a prestar recurso: ";
    cin >> codigoe;
    char nombre[30];
    char recurso[30];
    int bole = 0, bolr = 0;
    for(int i = 0; i < cr; i++){

        if(Recursos[i].codigo == codigor && (strcmp(Recursos[i].prestado, "libre") == 0) ) {
            bolr = 1;
            strcpy( recurso, Recursos[i].nombre);
            strcpy(Recursos[i].prestado, "Prestado");

        }else{
            cout << "\nrecurso no existe o esta prestado\n";
        }
    }

    for(int i = 0; i < cu; i++){
        if(Estudiantes[i].codigo == codigoe){
            bole = 1;
            strcpy(nombre, Estudiantes[i].nombre);

        }else{
            cout << "\nestudiante no existe\n";
        }
    }

    if((bole && bolr) == 1){
        prestamo save = {"..", codigoe, "..", codigor};
        Prestamos.push_back(save);
        strcpy(Prestamos[cp].nombreEstudiante, nombre);
        strcpy(Prestamos[cp].recurso, recurso);
        cp++;
        cout << "recurso prestado\n" << bole <<" "<<bolr;
   }else{
       cout << "no se pudo prestar\n";
   }


    
}



int consulta_prestamo(){

    int codigo;
    cout << "ingrese codigo estudiante: ";
    cin >> codigo ;
    cout << "prestamos\n";
    cout << "Estudiante - codigo - Recurso - codigo Recurso\n";
    for(int i = 0; i < cp; i++){

        if(Prestamos[i].codigoEstudiante == codigo){
            cout << Prestamos[i].nombreEstudiante << " - ";
            cout << Prestamos[i].codigoEstudiante << " - ";
            cout << Prestamos[i].recurso << " - ";
            cout << Prestamos[i].codigo << " - \n";
        }
    }

}
int mostrar_prestamo(){
    cout << "prestamos\n";
    cout << "Estudiante - codigo - Recurso - codigo Recurso\n";
    for(int i = 0; i < cp; i++){
        cout << Prestamos[i].nombreEstudiante << " - ";
        cout << Prestamos[i].codigoEstudiante << " - ";
        cout << Prestamos[i].recurso << " - ";
        cout << Prestamos[i].codigo << " - \n";
    
    }

}


int eliminar_prestamo(){
    
    mostrar_recursos();
    int codigo;
    cout << "Ingrese el codigo del recurso a devolver: ";
    cin >> codigo;
    int puesto;
    for(int i = 0; i < cp; i++){
        if (Prestamos[i].codigo == codigo){
            puesto = i;
        }
    }

    for (int j = 0; j < cr ; j++)
    {
       if (Recursos[j].codigo == codigo)
        {
           strcpy(Recursos[j].prestado, "libre");
    }
        
  }

 auto elem_to_remove = Prestamos.begin() + puesto;
 Prestamos.erase(elem_to_remove);
 cp--;

}


int menurecursos(){
	int sel;
	do {
	
	
	system("cls");
	cout << "Menu principal\n";
	cout << "1. Adicionar recurso\n";
	cout << "2. Consultar recurso\n";
	cout << "3. Mostrar recursos\n";
	cout << "4. Eliminar recursos\n";
	cout << "5. Salir\n";
	
	cout << "ingrese el numero seleccionado: ";
	cin >> sel;
	
	switch (sel)
	{
  	case 1: 
  			adicionar_recurso();
  			system("pause");
  	        break;
    case 2: 
			consultar_recurso();
			system("pause");
            break;
  	case 3: 
  			mostrar_recursos();
  			system("pause");
            break;
    case 4:
            eliminar_recursos();
    		break;
    		
    case 5:
    		break;
	};
	
	
	
 }while(sel != 5);
	
    return 0;
}

int menuusuario(){
	
	int sel;
		
	do {
	
	
	system("cls");
	cout << "Menu principal\n";
	cout << "1. Adicionar Estudiante\n";
	cout << "2. Consultar Estudiante\n";
	cout << "3. Mostrar Estudiantes\n";
	cout << "4. Salir\n";
	
	cout << "ingrese el numero seleccionado: ";
	cin >> sel;
	
	switch (sel)
	{
  	case 1: 
  			adicionar_estudiante();
  			system("pause");
  	        break;
    case 2: 
			consultar_estudiante();
			system("pause");
            break;
  	case 3: 
  			mostrar_estudiantes();
  			system("pause");
            break;

    case 4:
    		break;
	};
	
	
	
  }while(sel != 4);
}

int menuprestamos_y_devoluiones(){
	int sel;
	do {
	
	
	system("cls");
	cout << "Menu principal\n";
	cout << "1. Prestamo de Recurso\n";
	cout << "2. Devolucion de un recurso\n";
	cout << "3. Mostrar prestamo usuario\n";
	cout << "4. Mostrar prestamos usuarios\n";
	cout << "5. salir\n";
	
	cout << "ingrese el numero seleccionado: ";
	cin >> sel;
	
	switch (sel)
	{
  	case 1: 
  			prestamo_recursos();
  			system("pause");
  	        break;
    case 2: 
			eliminar_prestamo();
			system("pause");
            break;
  	case 3: 
  			consulta_prestamo();
  			system("pause");
            break;
    case 4:
            mostrar_prestamo();
    		system("pause");
    		break;
    case 5:
    		break;
	};
	
	
	
 }while(sel != 5);
	
	
}


int main(){
	

	
	
	int sel;	
	do {
	
	
	system("cls");
	cout << "Menu principal\n";
	cout << "1. Manejo de Recursos\n";
	cout << "2. Manejo de Usuarios\n";
	cout << "3. Manejo de prestamos y Devoluciones\n";
	cout << "4. Salir\n";
	
	cout << "ingrese el numero seleccionado: ";
	cin >> sel;
	
	switch (sel)
	{
  	case 1: 
  			menurecursos();
  			system("pause");
  	        break;
    case 2: 
			menuusuario();
			system("pause");
            break;
  	case 3: 
  			menuprestamos_y_devoluiones();
  			system("pause");
            break;
    case 4:
    		break;
	}
	
	
	
 }while(sel != 4);
	
	
}
