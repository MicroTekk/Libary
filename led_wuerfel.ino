// Festlegen des ersten LED Pin 
// dieser wird als Basis für Setup und den Zufallsgenerator genutzt
int ersteLED=6;
 
// Hier werden die Würfelbilder festgelegt
int wuerfelBild[6][7]={
  {0,0,0,1,0,0,0}, //1
  {0,1,0,0,0,1,0}, //2
  {1,0,0,1,0,0,1}, //3
  {1,1,0,0,0,1,1}, //4
  {1,1,0,1,0,1,1}, //5
  {1,1,1,0,1,1,1}  //6
};
 
void setup() {
  
  // Ausgehend von dem ersten LED Pin werden alle Pins als Output definiert
  for (int i=ersteLED;i<=ersteLED+6;++i)
    pinMode(i,OUTPUT);
 
   // Pin für den Schalter zur Steuerung des Zufallgenerators
    pinMode(2,INPUT);
}
 
// Funktion zum Anzeigen der Ergebnisse
void ShowNumber(int num)
{
  // Für die vom Zufallsgenerator übergebene Nummer wird das passende Pattern 
  // ausgelesen und die passenden LEDs aktiviert
  for (int i=0;i<=6;++i)
    digitalWrite(i+ersteLED,wuerfelBild[num][i]?HIGH:LOW);
}
 
void loop(){
  int i,j;
  unsigned randomnumber;
  
  // Einschalten aller LEDs
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
 
  // Pause von 200 Millisekunden
  delay(200);
  
  // Anzeigen der gewürfelten Nummer
  do {
     // Generieren einer Zufallszahl (millis = Laufzeit)
    i=(millis()/200)%6;
    ShowNumber(i);
  } while (digitalRead(2)==LOW);
  
  // Beginn der While Schleife mit dem Blinkbild beim Würfeln
  while(1){  
    randomnumber=0;
    do {
      ++randomnumber;
      i=(millis()/70)%7;
      for (j=0;j<=6;++j)
        digitalWrite(j+ersteLED,j==i?HIGH:LOW);
    } while (digitalRead(2)==HIGH);
    
    randomnumber=randomnumber%6;
    ShowNumber(randomnumber);
    while (digitalRead(2)==LOW) {};
  }
    
}
