5t #include <SPI.h>
#include <Ethernet.h>
//Declara bibliotecas
 

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress serverIP(172,16,0,250);
int serverPort=80;
//Declara caracterpisticas do controlador, MAC, IP e por

EthernetServer server(serverPort);

int lampada4 = 8;
int lampada3 = 7;
int lampada2 = 6;
int lampada1 = 5;

void setup()
{

  
  Ethernet.begin(mac, serverIP);
  server.begin();
  Serial.begin(9600);

  pinMode(lampada1,OUTPUT);
  digitalWrite(lampada1, HIGH);
  
  pinMode(lampada2,OUTPUT);
  digitalWrite(lampada2, HIGH);
  
  pinMode(lampada3,OUTPUT);
  digitalWrite(lampada3, HIGH);
  
  pinMode(lampada4,OUTPUT);
  digitalWrite(lampada4, HIGH);

}
 
void loop()
{

  
  EthernetClient client = server.available();
  if (client) {
   
    String recebido = "";
    
    while (client.connected()) {
      if (client.available()) {

        char c = client.read();

        recebido+=c;
        
        
        if (c == '\n') {
         
         // client.println("Comando recebido: "+recebido); 
          Serial.print(c);
          Serial.print(recebido);
      
         
          if (recebido.equals("ligar1\n")) 
          {
          client.println("Status: Ligado 1");
          digitalWrite(lampada1,LOW);
          }
          
          else if (recebido.equals("desligar1\n"))
         {
          client.println("Status: Desligado 1");
          digitalWrite(lampada1, HIGH);
         } 
         
         
          else if (recebido.equals("ligar2\n"))
         {
          client.println("Status: Ligado 2");
          digitalWrite(lampada2, LOW);
         } 
          else if (recebido.equals("desligar2\n"))
         {
          client.println("Status: Desligado 2");
          digitalWrite(lampada2, HIGH);
         }
         
                  
          else if (recebido.equals("ligar3\n"))
         {
          client.println("Status: Ligado 3");
          digitalWrite(lampada3, LOW);
         } 
          else if (recebido.equals("desligar3\n"))
         {
          client.println("Status: Desligado 3");
          digitalWrite(lampada3, HIGH);
         }
         
         
          else if (recebido.equals("ligar4\n"))
         {
          client.println("Status: Ligado 4");
          digitalWrite(lampada4, LOW);
         } 
          else if (recebido.equals("desligar2\n"))
         {
          client.println("Status: Desligado 4");
          digitalWrite(lampada4, HIGH);
         }
         
          recebido="";
        }
      }
    }

    delay(1);

    client.stop();
  }
}
