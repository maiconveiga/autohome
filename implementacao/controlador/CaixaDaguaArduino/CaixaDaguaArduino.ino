
const int NCisterna = 1;
const int NBaixo = 2;
const int NMedio= 3; 
const int NAlto= 4; 
const int Bomba =  13;     


int NCisternaState = 0;
int NBaixoState = 0;         
int NMedioState = 0; 
int NAltoState = 0; 

void setup() {

  pinMode(Bomba, OUTPUT);      
 
  pinMode(NCisterna, INPUT);
  pinMode(NBaixo, INPUT); 
  pinMode(NMedio, INPUT); 
  pinMode(NAlto, INPUT);   
}

void loop(){

 NCisternaState = digitalRead(NCisterna);
  NBaixoState = digitalRead(NBaixo);
    NMedioState = digitalRead(NMedio);
      NAltoState = digitalRead(NAlto);




  if ((NBaixoState == LOW) && (NMedioState == LOW) && (NAltoState == LOW) && (NCisternaState == HIGH))  {     
     
    digitalWrite(Bomba, HIGH);  
  } 
  else if ((NBaixoState == HIGH) && (NMedioState == LOW) && (NAltoState == LOW) && (NCisternaState == HIGH) ) 
    
    digitalWrite(Bomba, HIGH); 
    
 else if ((NBaixoState == HIGH) && (NMedioState == HIGH) && (NAltoState == LOW) && (NCisternaState == HIGH) )
   
    digitalWrite(Bomba, HIGH);
    
 else if ((NBaixoState == HIGH) && (NMedioState == HIGH) && (NAltoState == HIGH) && (NCisternaState == HIGH) )
   
    digitalWrite(Bomba, LOW); 
   
 else if ((NBaixoState == LOW) && (NMedioState == LOW) && (NAltoState == LOW) && (NCisternaState == LOW))  {     
     
    digitalWrite(Bomba, LOW);  
  } 
  else if ((NBaixoState == HIGH) && (NMedioState == LOW) && (NAltoState == LOW) && (NCisternaState == LOW) ) 
    
    digitalWrite(Bomba, LOW); 
    
 else if ((NBaixoState == HIGH) && (NMedioState == HIGH) && (NAltoState == LOW) && (NCisternaState == LOW) )
   
    digitalWrite(Bomba, LOW);
    
 else if ((NBaixoState == HIGH) && (NMedioState == HIGH) && (NAltoState == HIGH) && (NCisternaState == HIGH) )
   
    digitalWrite(Bomba, LOW);    
   
    
}
