/******************************************
 * SISTEMA DE GERENCIAMENTO DE BIBLIOTECA *
 * COM O AUXILIO DA TECNOLOGIA DE RFID    *
 *             (WIEDZA)                   *
 * ************************************** *
 * AUTOR: Gabriel Sousa Kraszczuk         *
 * DATA: 25/03/2016                       *
 * LICENÇA: OpenSource                    *
 * ************************************** */

 /**
  * INCLUDE DAS BIBLIOTECAS DO SHIELD
  *             RFID - RC522
  * -> SPI.h - Biblioteca do Protocolo SPI
  * (Serial Peripheral Interface).
  * 
  * -> MFRC522 - Biblioteca do Shield RFID -
  *  RC522
  */
  #include <SPI.h>
  #include <MFRC522.h>

  /**
   * DEFINIÇÃO DAS PORTAS DE COMUNICAÇÃO
   */
   #define LED_VERMELHO 5  // (POWER) Led que indica que a leitora está ligada.
   #define LED_BRANCO   6  // (STATUS) Led que indica algum estado da leitora, checar manual.
   #define LED_VERDE    7  // (READ) Led que indica que uma TAG RFID foi lida com sucesso.
   #define RESET        9  // (RESET) Define o pino de RESET do SHIELD (RC522).
   #define SDA          10 // (SDA - SPI) Define o pino de SDA do SHIELD (RC522).

   /**
    * CRIAÇÃO DO OBJETO GLOBAL (INSTÂNCIA)
    *   QUE GERENCIA O SHIELD RC522.
    * 
    * Objeto Instânciado a partir da biblioteca MFRC522.h
    */
    MFRC522 rfid(SDA,RESET);

/**
 * Função de instalação e configuração dos componentes de hardware (LED, SHIELD)
 */
void setup() {
  /**
   * Difinição do modo de funcionamento das portas.
   * TIPO -> SAIDA
   */
    pinMode(LED_VERMELHO,OUTPUT);
    pinMode(LED_BRANCO,OUTPUT);
    pinMode(LED_VERDE,OUTPUT);

  /**
   * Inicializado a Comunicação via Protocolo SPI
   */
    SPI.begin();

   /**
    * Inicializando a Comunicação via Porta Serial (USB)
    */
    Serial.begin(9600);

   /**
    * Inicializando o SHIELD RC522
    */
    rfid.PCD_Init();

    inicializacaoLeitora();

}

void loop() {
  // Look for new cards
    if ( ! rfid.PICC_IsNewCardPresent())
        return;

    // Select one of the cards
    if ( ! rfid.PICC_ReadCardSerial())
        return;
    imprimirUid(rfid.uid.uidByte, rfid.uid.size);
    //imprimirTipo();
    digitalWrite(LED_VERDE, HIGH);
    delay(1000);
    digitalWrite(LED_VERDE, LOW);

}

/**
 * Função de inicialização e testes da leitora
 */
void inicializacaoLeitora() {
  // Testando LEDS
  digitalWrite(LED_VERMELHO, HIGH);
  delay(1500);
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(LED_BRANCO, HIGH);
  delay(1500);
  digitalWrite(LED_BRANCO, LOW);
  digitalWrite(LED_VERDE, HIGH);
  delay(1500);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_VERMELHO, HIGH);
}

/**
 * Função para imprimir o uid do cartao RFID
 */
 void imprimirUid(byte *arrayByte, byte tamanhoArray) {
  for (byte b = 0; b < tamanhoArray; b++) {
    Serial.print(arrayByte[b]);
  }
  Serial.println();
 }

 void imprimirTipo(){
  Serial.println(rfid.PICC_GetTypeName(rfid.uid.sak));
 }

