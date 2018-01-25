#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(10,15,200, 77);
EthernetServer server(80);

int lampada4 = 4;
int lampada3 = 9;
int lampada2 = 8;
int lampada1= 7;


String readString = String(30);
String statuslampada1 = String(3);
String statuslampada2 = String(3);
String statuslampada3 = String(3);
String statuslampada4 = String(3);
void setup()
{

Ethernet.begin(mac, ip);
server.begin();


pinMode(lampada1,OUTPUT);
pinMode(lampada2,OUTPUT);
pinMode(lampada3,OUTPUT);
pinMode(lampada4,OUTPUT);

digitalWrite(lampada1,LOW);
digitalWrite(lampada2,LOW);
digitalWrite(lampada3,LOW);
digitalWrite(lampada4,LOW);

statuslampada1 = "OFF";
statuslampada2 = "OFF";
statuslampada3 = "OFF";
statuslampada4 = "OFF";

}
void loop()
{

EthernetClient client = server.available();

if (client) {

boolean currentLineIsBlank = true;


while (client.connected()) {

if (client.available()) {

char c = client.read();


if (readString.length() < 30) {
readString.concat(c);
}
if (c == '\n' && currentLineIsBlank) {

int LED = readString.indexOf("LED=");

if (readString.substring(LED,LED+5) == "LED=1") {
digitalWrite(lampada1,HIGH);
statuslampada1 = "ON";
}
else if (readString.substring(LED,LED+5) == "LED=2") {
digitalWrite(lampada1,LOW);
statuslampada1 = "OFF";
} 


else if (readString.substring(LED,LED+5) == "LED=3") {
digitalWrite(lampada2,HIGH);
statuslampada2 = "ON";
}
else if (readString.substring(LED,LED+5) == "LED=4") {
digitalWrite(lampada2,LOW);
statuslampada2= "OFF";
} 


else if (readString.substring(LED,LED+5) == "LED=5") {
digitalWrite(lampada3,HIGH);
statuslampada3 = "ON";
}
else if (readString.substring(LED,LED+5) == "LED=6") {
digitalWrite(lampada3,LOW);
statuslampada3 = "OFF";
} 

else if (readString.substring(LED,LED+5) == "LED=7") {
digitalWrite(lampada4,HIGH);
statuslampada4 = "ON";
}
else if (readString.substring(LED,LED+5) == "LED=8") {
digitalWrite(lampada4,LOW);
statuslampada4 = "OFF";
} 

else if (readString.substring(LED,LED+5) == "LED=9") {
digitalWrite(lampada1,HIGH);
digitalWrite(lampada2,HIGH);
digitalWrite(lampada3,HIGH);
digitalWrite(lampada4,HIGH);
statuslampada1 = "ON";
statuslampada2 = "ON";
statuslampada3 = "ON";
statuslampada4 = "ON";
}
else if (readString.substring(LED,LED+5) == "LED=0") {
digitalWrite(lampada1,LOW);
digitalWrite(lampada2,LOW);
digitalWrite(lampada3,LOW);
digitalWrite(lampada4,LOW);
statuslampada1 = "OFF";
statuslampada2 = "OFF";
statuslampada3 = "OFF";
statuslampada4 = "OFF";
} 


client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println();


  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
//------------------------------------------------------------
client.println("<form method='post' action='LED=1'>");
client.println("<input type='submit' value='on' >");
client.println("</form>");


 
client.println("<form method='post' action='LED=2'>");
client.println("<input type='submit' value='off'>");
client.println("</form>");
client.println("<br>");
//client.println("------");


client.println("<form method='post' action='LED=3'>");
client.println("<input type='submit' value='on' >");
client.println("</form>");


 
client.println("<form method='post' action='LED=4'>");
client.println("<input type='submit' value='off'>");
client.println("</form>");
client.println("<br>");
//client.println("------");

client.println("<form method='post' action='LED=5'>");
client.println("<input type='submit' value='on' >");
client.println("</form>");


 
client.println("<form method='post' action='LED=6'>");
client.println("<input type='submit' value='off'>");
client.println("</form>");
client.println("<br>");
//client.println("------");

client.println("<form method='post' action='LED=7'>");
client.println("<input type='submit' value='on' >");
client.println("</form>");


 
client.println("<form method='post' action='LED=8'>");
client.println("<input type='submit' value='off'>");
client.println("</form>");
client.println("<br>");
//client.println("------");


client.println("<form method='post' action='LED=9'>");
client.println("<input type='submit' value='on' >");
client.println("</form>");


 
client.println("<form method='post' action='LED=0'>");
client.println("<input type='submit' value='off'>");
client.println("</form>");
client.println("<br>");
//client.println("------");
//--------------------------------------------------------------
 client.println("</html>");


client.print("<br>");
client.print("Status Lampada 1:");
client.print(statuslampada1);
client.print("<br><br>");

client.print("Status Lampada 2:");
client.print(statuslampada2);
client.print("<br><br>");

client.print("Status Lampada 3:");
client.print(statuslampada3);
client.print("<br><br>");

client.print("Status Lampada 4:");
client.print(statuslampada4);
client.print("<br><br>");


break;
}
if (c == '\n') {

currentLineIsBlank = true;
} 
else if (c != '\r') {

currentLineIsBlank = false;
}
}
}

delay(1);
readString = "";

client.stop();
}
}
