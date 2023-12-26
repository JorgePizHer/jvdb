import subprocess

operacion = "insert"
basededatos = "miempresa"
coleccion = "clientes"
documento = "cliente3"
contenido = "Este es un contenido de prueba"



comando = '"D:\\OneDrive\\Escritorio\\Entornos de desarrollo\\GitHubRepos\\jvdb\\jvdb.exe" '+operacion+' '+basededatos+' '+coleccion+' '+documento+' "'+contenido+'"'
resultado = subprocess.run(comando,shell=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE,text=True)

if resultado.returncode == 0:
    print ("ok")
else:
    print("ko")
