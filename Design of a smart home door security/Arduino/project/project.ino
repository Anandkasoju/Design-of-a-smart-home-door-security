#include <SoftwareSerial.h>
SoftwareSerial mySerial(A4,A5);

#include <LiquidCrystal.h>
LiquidCrystal lcd(6, 7, 5, 4, 3, 2);


void serialFlush()
{
  while(Serial.available() > 0) 
  {
    char t = Serial.read();
  }
} 
void myserialFlush()
{
  while(mySerial.available() > 0) 
  {
    char t = mySerial.read();
  }
} 

void okcheck1()
{
  unsigned char rcr;
  do{
      rcr = mySerial.read();
    }while(rcr != 'K');
}


int identi_sw = 9;
int relay     = 8;
int buzzer    = 13;


int idk = 0,eid=0;


char rcv;
char face_string[10];
char face_status;

int sti=0; 
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete


void beep()
{
  digitalWrite(buzzer, LOW);delay(3000);digitalWrite(buzzer, HIGH);
}
void setup() 
{   
  pinMode(identi_sw, INPUT); 
  pinMode(buzzer, OUTPUT); 
  pinMode(relay, OUTPUT);
 
  digitalWrite(identi_sw, HIGH);
  digitalWrite(buzzer, HIGH);
  digitalWrite(relay, LOW);
 
  Serial.begin(9600);     //ESP32 CAM
  mySerial.begin(9600);   //WIFI Telnet

  lcd.begin(16,2);
  lcd.clear();lcd.print("Design Smart Home");
  lcd.setCursor(0,1);lcd.print("Door Security");
    delay(2000);  //delay(000);  
} 

void loop()
{ mn:
 //lcd.clear();lr  
  lcd.clear();lcd.print("Welcome .....");
  
if(digitalRead(identi_sw) == LOW)
{
  lcd.clear();lcd.setCursor(0, 0);lcd.print("Identifing Face..");
  
  serialFlush();
  int rtz=0;
  
  face_loop:
  memset(face_string,'\0',strlen(face_string));
  do{
      rcv = Serial.read();  
    }while(rcv != '*');
      readSerial(face_string);
      face_status  = face_string[0];
      if(face_status == 'N')
        {
          rtz++;
          lcd.setCursor(0,1);convertl(rtz);
          delay(1000);  
          if(rtz >= 7)
            {
             goto fp_loop; 
            }
          goto face_loop;
        }
      if(face_status >= '0' && face_status <= '9')
        {
           face_status='Y';         
        }

    fp_loop:   
    if(face_status == 'N')
      {
        delay(1000);lcd.clear();lcd.print("No-Face Detected");
        digitalWrite(buzzer, LOW);delay(2000);delay(2000);digitalWrite(buzzer, HIGH);
        
       //goto mn;
      }
    if(face_status == 'Y')
      {
        delay(1000);lcd.clear();lcd.print("Face Detected");
        
        digitalWrite(relay, HIGH);
        delay(2000);
        digitalWrite(relay, LOW);
             
      }   
}//identify

while(mySerial.available() > 0) 
     {      
         char inChar = (char)mySerial.read();
         if(inChar == '*')
            {
              sti=1;
            }
          if(sti == 1)
            {
              inputString += inChar;
            }
          if(inChar == '#')
            {sti=0;
              stringComplete = true;

              inputString="";
            }
     }

}




int readSerial(char result[]) 
{
  int i = 0;
  while (1) 
  {
    while (Serial.available() > 0) 
    {
      char inChar = Serial.read();
      if (inChar == '\n') 
         {
          result[i] = '\0';
          Serial.flush();
          return 0;
         }
      if (inChar != '\r') 
         {
          result[i] = inChar;
          i++;
         }
    }
  }
}


void converts(unsigned int value)
{
  unsigned int a,b,c,d,e,f,g,h;

      a=value/10000;
      b=value%10000;
      c=b/1000;
      d=b%1000;
      e=d/100;
      f=d%100;
      g=f/10;
      h=f%10;


      a=a|0x30;               
      c=c|0x30;
      e=e|0x30; 
      g=g|0x30;              
      h=h|0x30;
    
     
   Serial.write(a);
   Serial.write(c);
   Serial.write(e); 
   Serial.write(g);
   Serial.write(h);
}

void convertl(unsigned int value)
{
  unsigned int a,b,c,d,e,f,g,h;

      a=value/10000;
      b=value%10000;
      c=b/1000;
      d=b%1000;
      e=d/100;
      f=d%100;
      g=f/10;
      h=f%10;


      a=a|0x30;               
      c=c|0x30;
      e=e|0x30; 
      g=g|0x30;              
      h=h|0x30;
    
     
   lcd.write(a);
   lcd.write(c);
   lcd.write(e); 
   lcd.write(g);
   lcd.write(h);
}
