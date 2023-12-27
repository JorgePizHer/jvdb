import subprocess
import os

class Jvdb:
    def __init__(self,basededatos):
        self.basededatos = basededatos
        
    def insert(self,coleccion,documento,contenido):
        
        self.operacion = "insert"
        self.coleccion = coleccion
        self.documento = documento
        self.contenido = contenido
        
        comando = '"D:\\OneDrive\\Escritorio\\Entornos de desarrollo\\GitHubRepos\\jvdb\\jvdb.exe" '+self.operacion+' '+self.basededatos+' '+self.coleccion+' '+self.documento+' "'+self.contenido+'"'
        resultado = subprocess.run(comando,shell=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE,text=True)
        
        if resultado.returncode == 0:
            return ("ok")
        else:
            return("ko")

    def update(self,coleccion,documento,contenidoviejo,contenidonuevo):
        
        self.operacion = "update"
        self.coleccion = coleccion
        self.documento = documento
        self.contenidoviejo = contenidoviejo
        self.contenidonuevo = contenidonuevo
        
        comando = '"D:\\OneDrive\\Escritorio\\Entornos de desarrollo\\GitHubRepos\\jvdb\\jvdb.exe" '+self.operacion+' '+self.basededatos+' '+self.coleccion+' '+self.documento+' "'+self.contenidoviejo+'" "'+self.contenidonuevo+'"'
        resultado = subprocess.run(comando,shell=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE,text=True)
        
        if resultado.returncode == 0:
            return ("ok")
        else:
            return("ko")
    
    def select(self,coleccion,documento):

        self.operacion = "select"
        self.coleccion = coleccion
        self.documento = documento
        
        comando = '"D:\\OneDrive\\Escritorio\\Entornos de desarrollo\\GitHubRepos\\jvdb\\jvdb.exe" '+self.operacion+' '+self.basededatos+' '+self.coleccion+' '+self.documento+''
        resultado = subprocess.run(comando,shell=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE,text=True)

        
        if resultado.returncode == 0:
            return print(resultado.stdout.strip())
        else:
            return print("ko")

    def delete(self,coleccion,documento):

        self.operacion = "delete"
        self.coleccion = coleccion
        self.documento = documento
        
        comando = '"D:\\OneDrive\\Escritorio\\Entornos de desarrollo\\GitHubRepos\\jvdb\\jvdb.exe" '+self.operacion+' '+self.basededatos+' '+self.coleccion+' '+self.documento+''
        resultado = subprocess.run(comando,shell=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE,text=True)

        if os.path.exists(documento):
              os.remove(documento)
              print("Registro eliminado correctamente")
        else:
              print("The file does not exist")

        if resultado.returncode == 0:
            return print()
        else:
            return print("ko")
