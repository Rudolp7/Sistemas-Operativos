#include <stdio.h> //Bibiliote estandar de entrada y salida
#include <termios.h> //Biblioteca para manipular terminales en sistemas unix
#include <unistd.h> //biblioteca para acceder a las funciones POSIc del sistema operativo
#include <fcntl.h> //Biblioteca para manipulacion de descricptores de archivo 

//Funcion a detextar si una tecla ha sido presionada sin bloquear la ejecucion.
int kbhit(void)
{
  struct termios oldt, newt; //Estructura para guardar la configuracion del terminal
  int ch; //variable para almacenar la tecla presionada
  int oldf; //variable para almacenar los flags originales del terminal
 
  //Guardar la configuracion actual del terminal
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt; //Hacer una copia de la configuracion actual
  newt.c_lflag &= ~(ICANON | ECHO); //Desactivar el modo canonico y la impresion de tecla
  tcsetattr(STDIN_FILENO, TCSANOW, &newt); //Aplicar la nueva configuracion inmediatamente
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0); //Obtener las flags actuales de entrada
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK); //Hacer que la entrada sea no bloqueante
 
  ch = getchar(); //intentar leer una tecla
 
  //Restaurar la configurcion original del terminal
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF) //si se ha leido un caracter
  {
    ungetc(ch, stdin); //Devolver el caracter al buffer de entrada
    return 1; //indicar que ha una tecla presionada
  }
 
  return 0; //No se ha presionado ninguna tecla
}
