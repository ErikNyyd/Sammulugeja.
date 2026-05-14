/*
 * Projekt: Lihtne sammulugeja
 * Komponendid: 1 nupp, 1 LED
 */

 const int nupuPin = 2;
 const int ledPin = 13;
 
 int sammudeArv = 0;       
 int nupuOlek = 0;         
 int viimaneOlek = HIGH;   
 
 void setup() {
   
   pinMode(nupuPin, INPUT_PULLUP); 
   
   pinMode(ledPin, OUTPUT);
 
   
   Serial.begin(9600);
   Serial.println("Sammulugeja valmis. Vajuta nuppu!");
 }
 
 void loop() {
   
   nupuOlek = digitalRead(nupuPin);
 
   
   if (nupuOlek != viimaneOlek) {
     if (nupuOlek == LOW) {
       sammudeArv++;
 
       
       Serial.print("Sammude arv: ");
       Serial.println(sammudeArv);
 
       
       digitalWrite(ledPin, HIGH);
       delay(150);
       digitalWrite(ledPin, LOW);
     }
     
     delay(50);
   }
   
   
   viimaneOlek = nupuOlek;
 }