/*
Technische Daten:
Gehäusefarbe: milchig, diffus
Durchmesser: 5mm
Intensität: rot 93,5mcd, grün 220mcd, blau 137,5mcd
Öffnungswinkel: diffus
Betriebsspannung: rot 1,8V - blau und grün  3,2 V
Betriebsstrom: 20mA pro Kanal
Betriebsstrom max.: 50mA pro Kanal max. gepulst
Pulsbetrieb: Pulsweite = 0,1ms, Pulswiederholrate = 1/10
Lichtfarbe: rot 620nm, grün 520nm, blau 470nm
Die 3 Grundfarben werden über die drei Kathoden angesteuert.

Gemeinsamer PLUSPOL (gem. Anode).
*/



/*
     RGB LED CUBE
    */
     
    int redPin = 11;
    int greenPin = 10;
    int bluePin = 9;
     
    //uncomment this line if using a Common Anode LED
    //#define COMMON_ANODE
     
    void setup()
    {
      pinMode(redPin, OUTPUT);
      pinMode(greenPin, OUTPUT);
      pinMode(bluePin, OUTPUT);  
    }
     
    void loop()
    {
      setColor(255, 0, 0);  // red
      delay(1000);
      setColor(0, 255, 0);  // green
      delay(1000);
      setColor(0, 0, 255);  // blue
      delay(1000);
      setColor(255, 255, 0);  // yellow
      delay(1000);  
      setColor(80, 0, 80);  // purple
      delay(1000);
      setColor(0, 255, 255);  // aqua
      delay(1000);
    }
     
    void setColor(int red, int green, int blue)
    {
      #ifdef COMMON_ANODE
        red = 255 - red;
        green = 255 - green;
        blue = 255 - blue;
      #endif
      analogWrite(redPin, red);
      analogWrite(greenPin, green);
      analogWrite(bluePin, blue);  
    }
