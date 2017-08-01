#include <GSM.h>

#define PINNUMBER ""

GSM gsmAccess;
GSM_SMS sms;

char remoteNumber[20]= "9654639095";  
char txtMsg[200];


int a=13;
int b=12;
int d=11;
int e=10;
int f=9;
int g=8;
int y;
int z;

char senderNumber[20];

void setup()
{
 
  Serial.begin(9600);
  while (!Serial) {
  }
pinMode(a,OUTPUT);
pinMode(b,OUTPUT);
pinMode(d,OUTPUT);
pinMode(e,OUTPUT);
pinMode(f,OUTPUT);
pinMode(g,OUTPUT);

  boolean notConnected = true;

  while (notConnected)
  {
    if (gsmAccess.begin(PINNUMBER) == GSM_READY)
      notConnected = false;
    else
    {
      Serial.println("Not connected");
      delay(1000);
    }
  }

  Serial.println("GSM initialized");
  Serial.println("Waiting for messages");
}

void loop()
{ 
  int c;
  int x;
  if (sms.available())
  {
  c = sms.read();
  x=sms.read();
if ((c==49) & (x==49))
{
  digitalWrite(a,HIGH);
}
else if ((c==49) & (x==48))
{
  digitalWrite(a,LOW);
}
else if ((c==50) & (x==49)) 
{
  digitalWrite(b,HIGH);
  
}
else if ((c==50) & (x==48))
{
  digitalWrite(b,LOW);
}
else if ((c==51) & (x==49)) 
{
  digitalWrite(d,HIGH);
  
}
else if ((c==51) & (x==48))
{
  digitalWrite(d,LOW);
}
else if ((c==52) & (x==49)) 
{
  digitalWrite(e,HIGH);
  
}
else if ((c==52) & (x==48))
{
  digitalWrite(e,LOW);
}
else if ((c==53) & (x==49)) 
{
  digitalWrite(f,HIGH);
  
}
if ((c==53) & (x==48))
{
  digitalWrite(f,LOW);
}
else if ((c==54) & (x==49)) 
{
  digitalWrite(g,HIGH);
  
}
else if ((c==54) & (x==48))
{
  digitalWrite(g,LOW);
}


else if ((c==55) & (x==49)) 
{
sendSMS();
  
}





else
{
  sms.flush();
}
    sms.flush();
  }
  
  if(Serial.available()>0)  
  {
     
    y= Serial.read();
   z=Serial.read(); 
    { 
    if((y=='1') &(z=='1'))  
    {  
      Serial.println("ON");  
      digitalWrite(a, HIGH);  
      delay(200);  
    }  
    else if((y=='1') & (z=='0'))  
    {  
      Serial.println("OFF");  
      digitalWrite(a, LOW);  
      delay(200);  
    }  

     else if((y=='2') & (z=='1'))  
    {  
      Serial.println("pin 2 high");  
      digitalWrite(b,HIGH );  
      delay(200);  
    } 
     else if((y=='2') & (z=='0'))  
    {  
      Serial.println("pin 2 low");  
      digitalWrite(b, LOW);  
      delay(200);
    }
    else if((y=='3') & (z=='1')) 
    {  
      Serial.println("pin 3 high");  
      digitalWrite(d, HIGH);  
      delay(200);  
    }
     else if((y=='3') & (z=='0'))   
    {  
      Serial.println("pin 3 low ");  
      digitalWrite(d, LOW);  
      delay(200);  
    }   
     else if((y=='4') & (z=='1'))  
    {  
      Serial.println("pin 4 high");  
      digitalWrite(e, HIGH);  
      delay(200);  
    }        
    
     else if((y=='4') & (z=='0'))   
    {  
      Serial.println("pin 4 LOW");  
      digitalWrite(e, LOW);  
      delay(200); 
    } 
   else if((y=='5') & (z=='1'))   
    {  
      Serial.println("pin 5 high");  
      digitalWrite(f, HIGH);  
      delay(200);  
    }        
    
   else if((y=='5') & (z=='0'))   
    {  
      Serial.println("pin 5 low");  
      digitalWrite(f, LOW);  
      delay(200); 
    }
 else if((y=='6') & (z=='1'))   
    {  
      Serial.println("pin 6 high");  
      digitalWrite(g, HIGH);  
      delay(200);  
    }        
    
else if((y=='6') & (z=='0')) 
{  
      Serial.println("pin 6 low");  
      digitalWrite(g, LOW);  
      delay(200); 
      
    }  
    else  
    {  
      Serial.println("NO INPUT");  
      Serial.println(y); 
     Serial.println(z); 
    } 
    }
  }}
  
  
  void sendSMS(){

  Serial.print("Message to mobile number: ");
  Serial.println(remoteNumber);
  // sms text
  Serial.println("SENDING");
  Serial.println();
  Serial.println("Message:");
  Serial.println(txtMsg);

  // send the message
  sms.beginSMS(remoteNumber);
  sms.print(b);
  sms.print("Relay 2 is");
  sms.print(d);
  sms.print("Relay 3 is");
  sms.print(e);
  sms.print("Relay 4 is");
  sms.print("f");
  sms.print("Relay 5 is");
  sms.print("g");


  sms.endSMS(); 
  Serial.println("\nCOMPLETE!\n");  
}








