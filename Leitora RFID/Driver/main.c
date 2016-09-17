/***************************************************
 * WIEDZA - Sistema de Gerenciamento de Biblioteca *
 *                                                 *
 * Versão: Wiedza_Driver - Lx 1.0                  *
 * Autor: Gabriel Sousa Kraszczuk                  *
 ***************************************************/

// Bibliotecas Padrão
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

// Bibliotecas Customizadas
# include <serial.h>

// Variáveis Globais
char buffer[2];
int option = 1;

// TREADS - FUNCTIONS
pthread_t threads[2];
/*
  Inicia a comunicação serial com o Arduino
*/
void *thread_comunicacao_driver()
{
  int info;
  start_serial_communication();
  do {
    info = read_serial_port(buffer);
  } while(!strcmp(buffer, "_stop_"));
}

/*
  Fica monitorando o buffer
*/
void *thread_ler_dados_do_buffer()
{
  while(1)
  {
    if (strlen(buffer) > 0)
    {
      printf("%s", buffer);
    }
  }
}

int main(void)
{
    pthread_create(&(threads[0]), NULL, thread_comunicacao_driver, NULL);
    pthread_create(&(threads[1]), NULL, thread_ler_dados_do_buffer, NULL);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
}
