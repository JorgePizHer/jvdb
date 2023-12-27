from jvdb_conector import Jvdb

##Conexion1 = Jvdb("miempresa")
##Conexion1.insert("clientes","cliente5","Más contenido de prueba")

##Conexion2 = Jvdb("miempresa")
##contenido = Conexion2.select("clientes","cliente5")

##Conexion3 = Jvdb("miempresa")
##Conexion3.insert("clientes","cliente4","Y ahora qué eedfdsfh")

##Conexion4 = Jvdb("miempresa")
##Conexion4.delete("clientes","cliente4")

Conexion2 = Jvdb("miempresa")
Conexion2.update("clientes","cliente2","Pepe","Pablo")
