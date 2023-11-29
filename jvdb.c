#include <stdio.h>
#include <string.h>
#include <time.h>

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
    rename("nuevo.txt",nombrearchivo);
    
    printf("Registro eliminado correctamente");
}


int main (int argc, char *argv[]) {
    
    FILE *archivo;
    char *operacion = argv[1];
    char *basededatos = argv[2];
    char *coleccion = argv[3];
    char *documento = argv[4];
    
    char ruta[100];
    strcpy(ruta,basededatos);
    strcat(ruta,"/");
    strcat(ruta,coleccion);
    strcat(ruta,"/");
    strcat(ruta,documento);
    strcat(ruta,".json");
    
    printf("la ruta es: %s",ruta);
    
    
    
   if (strcmp(operacion,"select") == 0){
        archivo = fopen(ruta,"r");
        printf("Te enseno los datos:\n");
        
        char linea[1024];
        
        while (fgets(linea,sizeof(linea),archivo) != NULL) {
            printf("Linea: %s",linea);           
        }
        
    }else if (strcmp(operacion,"insert") == 0){
        
    archivo = fopen(ruta,"w");
    char *texto = argv[5];
    fputs(strcat(texto,"\n"),archivo);
    fclose(archivo);
        
    }else if (strcmp(operacion,"update") == 0){
        
    char *registroviejo = argv[5];
    char *nuevoregistro = argv[6];
    actualizarRegistro(ruta,registroviejo,nuevoregistro);
      
        
    }else if (strcmp(operacion,"delete") == 0){
    
    char *registroeliminar = argv[5];
    eliminarRegistro(ruta,registroeliminar);
    
        
    }else {
        printf("Operación no válida");
    }
    
    
    
    return 0;  
}

