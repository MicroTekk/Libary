int switchState = 0;
const int sensorPin = A0;
const float baselineTemp = 16.0;
const int redLEDPin = 9;
const int blueLEDPin = 10;
const int greenLEDPin = 11;

const int redSensorPin = A1;
const int greenSensorPin = A2;
const int blueSensorPin = A3;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;
void setup() 
{
   pinMode(3, OUTPUT);
   pinMode(4, OUTPUT);
   pinMode(5, OUTPUT);
   pinMode(2, INPUT);

   Serial.begin(9600);          //Öffnet eine Serielle Schnittstelle
   for(int pinNumber = 3; pinNumber<6; pinNumber++)
   {
    pinMode(pinNumber,OUTPUT);
    digitalWrite(pinNumber, LOW);
    }
    pinMode(greenLEDPin,OUTPUT);
    pinMode(redLEDPin,OUTPUT);
    pinMode(blueLEDPin,OUTPUT);
}

void loop() 
{
   switchState = digitalRead(2);    // Prüft den Status aus Pin 2 (Schalter)
if (switchState == LOW)              // Schalter wird nicht gedrückt
                        {            
      digitalWrite(3, LOW);      
      digitalWrite(5, LOW);       
      digitalWrite(4, LOW);       
                        }
                        
else {                           // Schalter wird gedrückt
     digitalWrite(3, HIGH);   
     digitalWrite(5, LOW);    
     digitalWrite(4, LOW);  
      delay(2000);            
     digitalWrite(3, LOW);    
     digitalWrite(5, HIGH);    
     digitalWrite(4, LOW);  
      delay(2000);            
     digitalWrite(3, LOW);   
     digitalWrite(5, LOW);   
     digitalWrite(4, HIGH); 
      delay(2000);          
     digitalWrite(4, LOW);   
      delay(1000);                       
     digitalWrite(4, HIGH);    
      delay(1000);
     digitalWrite(4, LOW);   
      delay(1000);
     digitalWrite(4, HIGH);    
      delay(1000);
     digitalWrite(4, LOW);   
      delay(1000);                       
     digitalWrite(4, HIGH);    
      delay(2000);  
     int sensorVal = analogRead(sensorPin);
        Serial.print("Sensor Wert: ");
        Serial.print(sensorVal);
        //adc wert in spannung wandeln
        float voltage = (sensorVal/1024.0)*5.0;
        Serial.print(",Volt: ");
        Serial.print(voltage);
        Serial.print(", Grad Celsius C: ");
        //spannung in volt umrechnen
        float temperature = (voltage - .5) * 100;
        Serial.println(temperature);    
if(temperature < baselineTemp)
  {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
   }
else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4)
   {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
   }
else if(temperature >= baselineTemp+4 && temperature < baselineTemp+6)
   {
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
   }                 
else if(temperature >= baselineTemp+6)
   {
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
   }
delay(3000);
   redSensorValue = analogRead(redSensorPin);
delay(5);
   greenSensorValue = analogRead(greenSensorPin);
delay(5);
   blueSensorValue = analogRead(blueSensorPin);
          Serial.print("Sensor Wert \t Rot: ");
          Serial.print(redSensorValue);
          Serial.print("\t Grün: ");
          Serial.print(greenSensorValue);
          Serial.print("\t Blau: ");
          Serial.println(blueSensorValue);
    redValue = redSensorValue/4;
    greenValue = greenSensorValue/4;
    blueValue = blueSensorValue/4;
          Serial.print("Umgerechneter Sensor Wert \t Rot: ");
          Serial.print(redValue);
          Serial.print("\t Grün: ");
          Serial.print(greenValue);
          Serial.print("\t Blau: ");
          Serial.println(blueValue);
            analogWrite(redLEDPin, redValue);
            analogWrite(greenLEDPin, greenValue);
            analogWrite(blueLEDPin, blueValue);
int sensorVal2 = analogRead(redSensorPin);
Serial.print(sensorVal2);
float voltage2 = (sensorVal2/1024.0)*5.0;
Serial.print(",Volt: ");
Serial.print(voltage2);    
   }       
}                             // Loop Ende, alles beginnt von Loop Anfang wieder
