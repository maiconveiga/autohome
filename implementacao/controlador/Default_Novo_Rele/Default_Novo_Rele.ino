p#include <SPI.h>
#include <Ethernet.h>


byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress serverIP(192,168,1,250);
int serverPort=80;


EthernetServer server(serverPort);

  int output1 = 2;
  int output2 = 3;
  int output3 = 4;
  int output4 = 5;
  int output5 = 6;
  int output6 = 7;
  int output7 = 8;
  int output8 = 9;
  


void setup()
{

  Ethernet.begin(mac, serverIP);
  server.begin();
  Serial.begin(9600);

  pinMode(output1,OUTPUT);
  digitalWrite(output1, HIGH);

  pinMode(output2,OUTPUT);
  digitalWrite(output2, HIGH);
  
  pinMode(output3,OUTPUT);
  digitalWrite(output3, HIGH);

  pinMode(output4,OUTPUT);
  digitalWrite(output4, HIGH);

  pinMode(output5,OUTPUT);
  digitalWrite(output5, HIGH);
  
  pinMode(output6,OUTPUT);
  digitalWrite(output6, HIGH);

  pinMode(output7,OUTPUT);
  digitalWrite(output7, HIGH);

  pinMode(output8,OUTPUT);
  digitalWrite(output8, HIGH);
  
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
         
         client.println("Comando recebido: "+recebido); 
          Serial.print(c);
          Serial.print(recebido);
      
        //----------------------------------------
          if (recebido.equals("ligar1\n"))
         {
          client.println("Status: ligado 1");
          digitalWrite(output1, LOW);
         }     
          else if (recebido.equals("desligar1\n"))
         {
          client.println("Status:desligado 1");
          digitalWrite(output1, HIGH);
         }
         else if (recebido.equals("ligar2\n"))
         {
          client.println("Status: ligado 2");
          digitalWrite(output2, LOW);
         }     
          else if (recebido.equals("desligar2\n"))
         {
          client.println("Status:desligado 2");
          digitalWrite(output2, HIGH);
         }
         else if (recebido.equals("ligar3\n"))
         {
          client.println("Status: ligado 3");
          digitalWrite(output3, LOW);
         }     
          else if (recebido.equals("desligar3\n"))
         {
          client.println("Status:desligado 3");
          digitalWrite(output3, HIGH);
         }
         else if (recebido.equals("ligar4\n"))
         {
          client.println("Status: ligado 4");
          digitalWrite(output4, LOW);
         }     
          else if (recebido.equals("desligar4\n"))
         {
          client.println("Status:desligado 4");
          digitalWrite(output4, HIGH);
         }
         else if (recebido.equals("ligar5\n"))
         {
          client.println("Status: ligado 5");
          digitalWrite(output5, LOW);
         }     
          else if (recebido.equals("desligar5\n"))
         {
          client.println("Status:desligado 5");
          digitalWrite(output5, HIGH);
         }
         else if (recebido.equals("ligar6\n"))
         {
          client.println("Status: ligado 6");
          digitalWrite(output6, LOW);
         }     
          else if (recebido.equals("desligar6\n"))
         {
          client.println("Status:desligado 6");
          digitalWrite(output6, HIGH);
         }
         else if (recebido.equals("ligar7\n"))
         {
          client.println("Status: ligado 7");
          digitalWrite(output7, LOW);
         }     
          else if (recebido.equals("desligar2\n"))
         {
          client.println("Status:desligado 7");
          digitalWrite(output7, HIGH);
         }
         else if (recebido.equals("ligar8\n"))
         {
          client.println("Status: ligado 8");
          digitalWrite(output8, LOW);
         }     
          else if (recebido.equals("desligar8\n"))
         {
          client.println("Status:desligado 8");
          digitalWrite(output8, HIGH);
         }
         else if (recebido.equals("ligarTudo\n"))
         {
          client.println("Status:Tudo ligado");
          digitalWrite(output1, LOW);
          digitalWrite(output2, LOW);
          digitalWrite(output3, LOW);
          digitalWrite(output4, LOW);
          digitalWrite(output5, LOW);
          digitalWrite(output6, LOW);
          digitalWrite(output7, LOW);
          digitalWrite(output8, LOW);
         }
         else if (recebido.equals("desligarTudo\n"))
         {
          client.println("Status:Tudo desligado");
          digitalWrite(output1, HIGH);
          digitalWrite(output2, HIGH);
          digitalWrite(output3, HIGH);
          digitalWrite(output4, HIGH);
          digitalWrite(output5, HIGH);
          digitalWrite(output6, HIGH);
          digitalWrite(output7, HIGH);
          digitalWrite(output8, HIGH);
         }
         
         
        //----------------------------------------           
          recebido="";
        }
      }
    }

    delay(1);
    client.stop();
  }
}
