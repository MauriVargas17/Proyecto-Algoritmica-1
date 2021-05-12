# Proyecto-Algoritmica-1
## Archivo EncriptadorDeLocacion.cpp

El programa consiste en poder encriptar una locación entre las disponibles, de manera que haciendo uso de llaves públicas y privadas
se pueda comunicar un mensaje secreto entre emisores y receptores, aplicando el algoritmo RSA y utilizando algoritmos para manejar primos como a criba de Eratóstenes.

> El archivo se ejecuta únicamente en consola.
>
> > Debemos abrir el archivo en un entorno de desarrollo integrado (IDE)
>
> La interacción en consola implica el ingreso y salida de datos.
> 

###### Una vez abierto, pasamos a ver los pasos de ejecución #######

 ## Ejecución
 
 El archivo lanzará un menú con 4 opciones:
 1.   Encriptar una locación
 2.   Desencriptar una locación
 3.   Mostrar la lista de locaciones
 4.   Terminar el programa
 
 Para selecionar una opción solo se debe ingresar el número correspondiente en la consola.
 Escoger la primera opción nos pedirá ingresar una serie de valores, como ser:
 
     "Ingrese a continuación dos números a elección no mayores a 2^32"
 A lo que se debe responder ingresando valores enteros; también nos pedirá el nombre del país que queremos encriptar. 
 Para saber los países disponibles, podemos ingresar a la opción número 3 y desplegar el arreglo de locaciones:
 
       Argentina Bolivia Chile Dinamarca Ecuador Francia Guyana Holanda Islandia Jerusalem Kyoto Libano...
> Al concluir de ingresar los datos solicitados para encriptar una locación, el programa devolverá las llaves públicas, llaves privadas
> y el mensaje original junto al mensaje encriptado.
> 
> Haciendo uso de las llaves creadas y el mensaje encriptado, podemos usar la segunda opción del menú para hacer el proceso inverso, donde
> nos pedirá las llaves privadas y el mensaje secreto. En algunos casos el mensaje es muy grande, por lo cual será expresado en notación 
> científica (si no es el caso, el siguiente detalle no es importante).
> 
>   + Si el mensaje encriptado está en notación científica, ingresaremos primero el valor numérico del mensaje sin el exponencial.
>   + A continuación, el programa nos dará la opción de ingresar el exponencial. Si no aplica, 0 es el valor adecuado a ingresar.
>   
> Finalmente, podemos salir del programa ingresando 4.


*   El archivo cuenta con varios métodos, que aplican por ejemplo la criba 
    de Eratóstenes para manejar primos, y en la implementación del RSA podemos
    hacer uso de los primos conseguidos de manera aleatoria.
*   El programa usa como método de encriptación de "string" a "int" la conversión
    por medio de los valores ASCII.

