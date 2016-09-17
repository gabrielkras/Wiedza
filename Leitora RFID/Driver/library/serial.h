/***************************************************
 * WIEDZA - Sistema de Gerenciamento de Biblioteca *
 *    "Biblioteca Para Leitura da Porta Serial"    *
 * Versão: Wiedza_Driver - Lx 1.0                  *
 * Autor: Gabriel Sousa Kraszczuk                  *
 ***************************************************/

# ifndef _serial_h
# define _serial_h

int start_serial_communication(void);
int read_serial_port(char *buffer);
void stop_serial_comunication(void);

# endif
