#include <SPI.h>
#include <Ethernet.h>


byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress serverIP(192,168,1,251);
int serverPort=80;

EthernetServer server(serverPort);

int bomba = 8;
int nca = 2;
int ncb = 3;
int ncisa = 4;
int ncisb = 5;

int sinalnca = 0;
int sinalncb = 0;
int sinalncisa = 0;
int sinalncisb = 0;
int stbomba = 0;

void setup() {     

  Ethernet.begin(mac, serverIP);
  server.begin();
  Serial.begin(9600);  

  pinMode(bomba, OUTPUT);
  pinMode(nca, INPUT); 
  pinMode(ncb, INPUT); 
  pinMode(ncisa, INPUT);
  pinMode(ncisb, INPUT);  
   
}

void loop() {
  sinalnca = digitalRead(nca);
  sinalncb = digitalRead(ncb);
  sinalncisa = digitalRead(ncisa);
  sinalncisb = digitalRead(ncisb);
  
if((sinalncisb == 1))
 {
   if(sinalncb == 0)
    {
      digitalWrite(bomba, HIGH);
      stbomba = 1;
    } 
    if(sinalnca == 1)
    {
      digitalWrite(bomba, LOW);
      stbomba = 0;
    } 

 }else 
 {digitalWrite(bomba, LOW);
  stbomba = 0;
 }



  
  EthernetClient client = server.available();
  if (client) {
   
    String recebido = "";
    
    while (client.connected()) {
      if (client.available()) {

        char c = client.read();

        recebido+=c;
             
        if (c == '\n') {
 //-------------------------------------------------------        
         if (recebido.equals("nc\n"))
         {          
           if(sinalnca == 0){
             if(sinalncb == 0){
               client.println("baixo");
             }
             else{
               client.println("medio");
             }
             
           }else{
               client.println("cheio");
             }
            
          Serial.print(c);
          Serial.print(recebido);
          delay(1);
         }
//-------------------------------------------------------

         if (recebido.equals("ncis\n"))
         {          
           if(sinalncisa == 0){
             if(sinalncisb == 0){
               client.println("baixo");
             }
             else{
               client.println("medio");
             }
             
           }else{
               client.println("cheio");
             }
            
          Serial.print(c);
          Serial.print(recebido);
          delay(1);
         }
//-------------------------------------------------------


        if (recebido.equals("bomba\n"))
         {
           
           if(stbomba == 0)
             client.println("desligado"); 
           else
             client.println("ligado"); 
         
          Serial.print(c);
          Serial.print(recebido);
          delay(1);
        }
//-------------------------------------------------------

          recebido="";
        }
      }
    }
    client.stop();
  }
}
 



