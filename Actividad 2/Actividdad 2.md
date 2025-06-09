 
Identificar comandos de la forma: comando parametro1 parametro2
Uso de sscanf para separar cadena en tokens.

Comandos a reconocer:
CARGAR/LOAD nombre_archivo
Validar que el parámetro1 no sea vacío
En caso de serlo, indicar el modo de uso del comando.
Validar que el archivo indicado en param1 exista, en caso contrario indicar el error con un mensaje.
Abrir el archivo en modo de texto y de lectura
Encender una bandera para que el ciclo de ejecución, sepa que debe leer una línea del mismo en cada iteración.
SALIR/EXIT
Modularizar el código de la siguiente manera:
Una función para el manejo de la linea de comandos donde se revise si se presionó tecla y realizar con ella lo pertinente
Una función para evaluar el comando solicitado al presionar ENTER
Una función, para leer la siguiente línea de un archivo de texto.
Ojo: Sólo debe leer una línea (la siguiente) y regresar sin cerrar el archivo.
Una función main con:
Las variables de control necesarias.
Un ciclo que iterará continuamente hasta que se indique el comando SALIR. Dicho ciclo realizará:
La impresión de un Prompt (definido por el usuario), y el bufer de lo tecleado hasta el momento.
Dicha impresión deberá realizarse, sólo cuando se detecte un cambio en la entrada del teclado (evitar imprimirlo en cada iteración).
Verificar si la bandera de lectura de archivo está activa:
Verificar si el archivo aún tiene líneas por leer, de ser así imprimir la siguiente línea.
En caso de haber concluido de leer el archivo, cerrarlo y desactivar la bandera de lectura de archivo.
Un delay de N milisegundos que se detendrá la ejecución del programa entre cada iteración
Todas las funciones deberán recibir sus parámetros por referencia y regresar un valor indicativo del estado de ejecución de la misma.
El uso de variables globales se penalizará, a menos que no exista otra manera de implementarlas.
Deberá preparar una documentación de cada función implementada donde especifique:
Nombre de la función
Descripción de parámetros que recibe
Descripción del valor regresado
Objetivo de la función (¿Que hace?)
Descripción de la función (¿Cómo lo hace?)

Nota: considere la posibilidad de incluir teclas especiales a su línea de comandos (Backspace, Esc, ...)
