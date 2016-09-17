/***************************************************
 * WIEDZA - Sistema de Gerenciamento de Biblioteca *
 *    "Biblioteca Para Leitura da Porta Serial"    *
 * Versão: Wiedza_Driver - Lx 1.0                  *
 * Autor: Gabriel Sousa Kraszczuk                  *
 ***************************************************/

# include "serial.h"
# include <stdio.h>
# include <sys/fcntl.h>
# include <string.h>

// Constantes de Cores para o CONSOLE
# define COLOR_RED     "\x1b[31m"
# define COLOR_GREEN   "\x1b[32m"
# define COLOR_YELLOW  "\x1b[33m"
# define COLOR_BLUE    "\x1b[34m"
# define COLOR_MAGENTA "\x1b[35m"
# define COLOR_CYAN    "\x1b[36m"
# define COLOR_RESET   "\x1b[0m"

// Porta de Comunicação;
int port = 0;
// Nome da Porta Serial Conectada
char port_name[20];

/*
 (Procedimento Público)
 Inicia a comunicação com uma porta serial do linux
*/
int start_serial_communication(void)
{
  printf("%sTentando conexão com a porta %s'/dev/ttyACM0'\n %s", COLOR_CYAN, COLOR_YELLOW, COLOR_RESET);
  port = open("/dev/ttyACM0", O_RDWR | O_NOCTTY);
  if (port == -1)
  {
    printf("%sNão foi possível conectar com a porta %s'/dev/ttyACM0'\n\n%s", COLOR_RED, COLOR_YELLOW, COLOR_RESET);
  } else {
    printf("%sConectado com sucesso a porta %s'/dev/ttyACM0'\n\n%s", COLOR_GREEN, COLOR_YELLOW, COLOR_RESET);
    strcpy(port_name,"/dev/ttyACM0");
    return 0;
  }

  printf("%sTentando conexão com a porta %s'/dev/ttyACM1'\n %s", COLOR_CYAN, COLOR_YELLOW, COLOR_RESET);
  port = open("/dev/ttyACM1", O_RDWR | O_NOCTTY);
  if (port == -1)
  {
    printf("%sNão foi possível conectar com a porta %s'/dev/ttyACM1'\n\n%s", COLOR_RED, COLOR_YELLOW, COLOR_RESET);
  } else {
    printf("%sConectado com sucesso a porta %s'/dev/ttyACM1'\n\n%s", COLOR_GREEN, COLOR_YELLOW, COLOR_RESET);
    strcpy(port_name,"/dev/ttyACM1");
    return 0;
  }

  printf("%sTentando conexão com a porta %s'/dev/ttyACM2'\n %s", COLOR_CYAN, COLOR_YELLOW, COLOR_RESET);
  port = open("/dev/ttyACM2", O_RDWR | O_NOCTTY);
  if (port == -1)
  {
    printf("%sNão foi possível conectar com a porta %s'/dev/ttyACM2'\n\n%s", COLOR_RED, COLOR_YELLOW, COLOR_RESET);
  } else {
    printf("%sConectado com sucesso a porta %s'/dev/ttyACM2'\n\n%s", COLOR_GREEN, COLOR_YELLOW, COLOR_RESET);
    strcpy(port_name,"/dev/ttyACM2");
    return 0;
  }

  printf("%sTentando conexão com a porta %s'/dev/ttyACM3'\n %s", COLOR_CYAN, COLOR_YELLOW, COLOR_RESET);
  port = open("/dev/ttyACM3", O_RDWR | O_NOCTTY);
  if (port == -1)
  {
    printf("%sNão foi possível conectar com a porta %s'/dev/ttyACM3'\n\n%s", COLOR_RED, COLOR_YELLOW, COLOR_RESET);
  } else {
    printf("%sConectado com sucesso a porta %s'/dev/ttyACM3'\n\n%s", COLOR_GREEN, COLOR_YELLOW, COLOR_RESET);
    strcpy(port_name,"/dev/ttyACM3");
    return 0;
  }

  printf("%sTentando conexão com a porta %s'/dev/ttyACM4'\n %s", COLOR_CYAN, COLOR_YELLOW, COLOR_RESET);
  port = open("/dev/ttyACM4", O_RDWR | O_NOCTTY);
  if (port == -1)
  {
    printf("%sNão foi possível conectar com a porta %s'/dev/ttyACM4'\n\n%s", COLOR_RED, COLOR_YELLOW, COLOR_RESET);
  } else {
    printf("%sConectado com sucesso a porta %s'/dev/ttyACM4'\n\n%s", COLOR_GREEN, COLOR_YELLOW, COLOR_RESET);
    strcpy(port_name,"/dev/ttyACM4");
    return 0;
  }

}

/*
  (Procedimento Privado)
  Essa função efetua a limpeza de um array de caracteres
*/
void clear_array(char *array)
{
  int size = strlen(array);
  int k = 0;
  for (k=0; k<size; k++)
  {
    array[k] = 0;
  }
}

/*
  (Procedimento Público)
  Essa função efetua a leitura da porta serial até que a variável option fique com o valor 0
*/
int read_serial_port(char *buffer)
{
  return read(port, buffer, 2);
}

/*
  (Procedimento Público)
  Finaliza a comunicação com a porta serial do linux
*/
void stop_serial_comunication(void)
{
  int c = close(port);
  if (c == 0) {
    printf("%sDesconectado com sucesso da porta serial %s'%s'\n\n%s", COLOR_GREEN, COLOR_YELLOW, port_name, COLOR_RESET);
  } else {
    printf("%sHouve um problema ao desconectar-se da porta serial %s'%s'\n\n%s", COLOR_RED, COLOR_YELLOW, port_name, COLOR_RESET);
  }
}
