#include <stdio.h>
#include <string.h>

void actualizarRegistro (char *nombrearchivo, char *registroviejo, char *nuevoregistro) {
    
    FILE *archivo = fopen (nombrearchivo, "r");
    FILE *nuevoArchivo = fopen ("nuevo.txt","w");
    
    if (archivo == NULL || nuevoArchivo == NULL) {
        
        printf ("Error al intentar abrir el archivo para actualizar\n");
        return;
    }
    
    char linea [1024];
    
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        
        if (strstr(linea,registroviejo) == NULL) {
            fputs (linea,nuevoArchivo);
        }else {
            fputs(nuevoregistro,nuevoArchivo);
            fputs ("\n", nuevoArchivo);
        }
    }
    
    fclose(archivo);
    fclose(nuevoArchivo);
    
    remove(nombrearchivo);
    rename("nuevo.txt",nombrearchivo);
    
    printf("Registro actualizado correctamente");
}

void eliminarRegistro (char *nombrearchivo, char *registroeliminar) {
    
    FILE *archivo = fopen (nombrearchivo, "r");
    FILE *nuevoArchivo = fopen ("nuevo.txt","w");
    
    if (archivo == NULL || nuevoArchivo == NULL) {
        
        printf ("Error al intentar abrir el archivo para eliminar\n");
        return;
    }
    
    char linea [1024];
    
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        
        if (strstr(linea,registroeliminar) == NULL) {
            fputs (linea,nuevoArchivo);
        }
    }
    
    fclose(archivo);
    fclose(nuevoArchivo);
    
    remove(nombrearchivo);
    
    
    printf("Registro eliminado correctamente");
}


int main (int argc, char *argv[]) {
    
    FILE *archivo;
    char *operacion = argv[1];
    char *basededatos = argv[2];
    char *coleccion = argv[3];  
    
   if (strcmp(operacion,"select") == 0){
       
        char *documento = argv[4];
        char ruta[100];
        strcpy(ruta,"db/");
        strcat(ruta,basededatos);
        strcat(ruta,"/");
        strcat(ruta,coleccion);
        strcat(ruta,"/");
        strcat(ruta,documento);
        strcat(ruta,".json");    
       
        archivo = fopen(ruta,"r");
        printf("Te enseno los datos:\n");
        
        char linea[1024];
        
        while (fgets(linea,sizeof(linea),archivo) != NULL) {
            printf("Linea: %s",linea);           
        }
        
    }else if (strcmp(operacion,"insert") == 0){
    
        char *documento = argv[4];  
        char ruta[100];
        strcpy(ruta,"db/");
        strcat(ruta,basededatos);
        strcat(ruta,"/");
        strcat(ruta,coleccion);
        strcat(ruta,"/");
        strcat(ruta,documento);
        strcat(ruta,".json");    
        archivo = fopen(ruta,"w");
        char *texto = argv[5];
        fputs(strcat(texto,"\n"),archivo);
        fclose(archivo);
    
    }else if (strcmp(operacion,"createDatabase") == 0){
        //Crear nueva base de datos
        char rutaDB[100];
        strcpy(rutaDB,"db/");
        strcat(rutaDB,basededatos);
        
        if (mkdir(rutaDB,0777) == 0){
            printf("ok");
        }else {
            printf("ko");
        }   
       
       
    }else if (strcmp(operacion,"createCollection") == 0){
        //Crear nueva carpeta con mkdir
        char rutacoleccion[100];
        strcpy(rutacoleccion,"db/");
        strcat(rutacoleccion,basededatos);
        strcat(rutacoleccion,"/");
        strcat(rutacoleccion,coleccion);
        if (mkdir(rutacoleccion,0777) == 0){
            printf("ok");
        }else {
            printf("ko");
        }
            
            
    }else if (strcmp(operacion,"update") == 0){
      
        char *documento = argv[4];    
        char ruta[100];
        strcpy(ruta,"db/");
        strcat(ruta,basededatos);
        strcat(ruta,"/");
        strcat(ruta,coleccion);
        strcat(ruta,"/");
        strcat(ruta,documento);
        strcat(ruta,".json");
       
        char *registroviejo = argv[5];
        char *nuevoregistro = argv[6];
        actualizarRegistro(ruta,registroviejo,nuevoregistro);
      
        
    }else if (strcmp(operacion,"delete") == 0){
    
        char *documento = argv[4];    
        char ruta[100];
        strcpy(ruta,"db/");
        strcat(ruta,basededatos);
        strcat(ruta,"/");
        strcat(ruta,coleccion);
        strcat(ruta,"/");
        strcat(ruta,documento);
        strcat(ruta,".json");
       
        char *registroeliminar = argv[4];
        eliminarRegistro(ruta,registroeliminar);
    
        
    }else {
        printf("Operación no válida");
    }
    
    
    
    return 0;  
}

//crear nuevas bases de datos
// select todos los archivos de una carpeta/registros de una tabla