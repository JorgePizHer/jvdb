import subprocess

comando = '"D:\\OneDrive\\Escritorio\\Entornos de desarrollo\\GitHubRepos\\jvdb\\jvdb.exe" insert miempresa clientes cliente2 "Juan Antonio"'
resultado = subprocess.run(comando,shell=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE,text=True)

if resultado.returncode == 0:
    print ("ok")
else:
    print("ko")
