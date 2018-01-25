

const int bomba = 13;  

const int n1caixa = 2;
const int n2caixa = 3;
const int ncisterna = 8;


int n1caixa_ = 0;
int n2caixa_ = 0;

int ncisterna_ = 0;



void setup() {
  pinMode(bomba,OUTPUT);
  pinMode(n1caixa,INPUT);
  pinMode(n2caixa,INPUT);
  pinMode(ncisterna,INPUT);

}

void loop() {  

  n1caixa_ = digitalRead(n1caixa);
  n2caixa_ = digitalRead(n2caixa);    
  ncisterna_ = digitalRead(ncisterna);
 
  
  if (n1caixa_ == LOW)
  {
   if (n2caixa_ == LOW)
   {
   if (ncisterna_ == HIGH)
      digitalWrite(bomba,HIGH);
   }
  }     
  else 
     digitalWrite(bomba,LOW);
  
  }   
 
  


