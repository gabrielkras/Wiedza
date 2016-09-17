/************************************************
 *      LEITORA RFID RC522 - PROJETO WIEDZA     *
 ************************************************
 * AUTOR: Gabriel Sousa Kraszczuk               *
 * DATA: 11/11/2015                             *
 * VERSÃO: 1.0                                  *
 * OBS: LINK PARA DEBUG:http://www.arduinoecia.com.br/2014/12/controle-de-acesso-modulo-rfid-rc522.html
 ************************************************/
#include <SPI.h>
#include <MFRC522.h>

/******LED'S INDICADORES*********/
int LED_POWER = 5; //LED VERMELHO
int LED_LEITURA = 7; //LED VERDE
int LED_CONEXAO = 6; //LED BRANCO

/******DEFINICAO DOS PINOS MODULO RFID RC522*******/
#define SS_PIN 10
#define RST_PIN 9
MFRC522 rfid(SS_PIN, RST_PIN);

/******VARIÁVEIS GLOBAIS********/
String uidDaTag=" ";
long tempoAnteriorMillis = 0;
long intervaloDeTempo = 30000;

/*******INICIALIZAÇÃO DOS LED'S INDICADORES******/
void inicializarLeds(){
  pinMode(LED_POWER, OUTPUT);
  pinMode(LED_LEITURA, OUTPUT);
  pinMode(LED_CONEXAO, OUTPUT); 
}

/*******INICIALIZAÇÃO DA SERIAL********/
void iniciarSerial(){
  Serial.begin(9600); 
}

/********INICIALIZAÇÃO DA LEITORA*********/
void inicializarLeitora(){
  //Testando Os leds indicativos
 digitalWrite(LED_POWER, HIGH);
 delay(1000);
 digitalWrite(LED_CONEXAO, HIGH);
 delay(1000);
 digitalWrite(LED_LEITURA, HIGH);
 delay(500);
 
 digitalWrite(LED_POWER, LOW);
 delay(500);
 digitalWrite(LED_CONEXAO, LOW);
 delay(500);
 digitalWrite(LED_LEITURA, LOW);
 delay(500);
 digitalWrite(LED_POWER, HIGH);
 delay(100);
 //Iniciando a comunicação pelo protocolo SPI
 SPI.begin();
 
 //Iniciando o módulo RFID RC522
  rfid.PCD_Init();
}

/********FUNÇÃO CONTADOR DE TEMPO*********/
void temporizador(){
 unsigned long tempoAtualMillis = millis();
 if(tempoAtualMillis - tempoAnteriorMillis > intervaloDeTempo){
    uidDaTag =" ";
    tempoAnteriorMillis = tempoAtualMillis;
 } 
}

void setup() {
  inicializarLeds();
  iniciarSerial();
  inicializarLeitora();
  Serial.print("Seja Bem-Vindo a Leitora WIEDZA\n");
  
}

void loop() {
  //Testa a aproximação do cartão RFID
  if(rfid.PICC_IsNewCardPresent()){
     if(rfid.PICC_ReadCardSerial()){
         String conteudoDaTag;
         for(byte k = 0; k < rfid.uid.size; k++){
           conteudoDaTag.concat(String(rfid.uid.uidByte[k]));
         }
         if(conteudoDaTag == uidDaTag){
            temporizador();
         }
         else{
           digitalWrite(LED_LEITURA,HIGH);
           uidDaTag = conteudoDaTag;
           Serial.print("TAG "+uidDaTag+"\n");
           delay(1000);
           digitalWrite(LED_LEITURA,LOW);
           temporizador();
         }
     } 
  }
  temporizador();
}
