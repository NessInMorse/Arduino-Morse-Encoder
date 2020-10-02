/*
  Voorbeeld Blink (knipper)
  Schakel een LED een seconde lang aan daarna een seconde lang uit
  en herhaal dat "voor altijd" 

  This example code is in the public domain.
*/
 
// Pin 13 heeft een LED gekoppeld op de meeste Arduino borden.
// geef pin 13 een naam
int wachttijd=1000; // maak een geheel getal genaamd wachttijd en geef deze de waarde 1000 
int LED=13;
int startingLED=11;
String translation="";
int traagheid=2;
int dot=100;
int dash=500;
int space=100;
int slash=200;
int newline=800;





/* De setup routine wordt een maal uitgevoerd na reset 
   of bij het opladen van de sketch op de Arduino
*/
void setup()
{                
  // Initialiseer de digitale pin als uitoer.
  pinMode(LED, OUTPUT);
  pinMode(startingLED,OUTPUT);

  String text="je moeder is dik";
  String Alphabet="abcdefghijklmnopqrstuvwxyz ";
  String Morseconversion[27]={".- ","-... ","-.-. ","-.. ",". ","..-. ","--. ",".... ",".. ",".--- ","-.- ",".-.. ","-- ","-. ","--- ",".--. ","--.- ",".-. ","... ","- ","..- ","...- ","-..- ","-.-- ","--.."," / "};

  for(int i=0;i<text.length();i++)   
  {
    translation+=Morseconversion[Alphabet.indexOf(text[i])];
    Serial.print("je moeder is dik");
  }
}

/* De loop routine wordt iedere keer weer opnieuw uitgevoerd
   nadat deze is afgelopen. Wordt voor het eerst uitgevoerd 
   nadat de setup routine is afgelopen.
*/
void loop() 
{
  int c=0;
  digitalWrite(startingLED, HIGH);   // schakel de LED aan (HIGH is the voltage level)
  delay(traagheid*dot);
  digitalWrite(startingLED, LOW);    // schakel de LED uit door het voltage LOW te maken
  delay(traagheid*space);
  
  while (c<translation.length())
  {
    switch(translation[c]){


        case '.':
        digitalWrite(LED, HIGH);   // schakel de LED aan (HIGH is the voltage level)
        delay(traagheid*dot);
        digitalWrite(LED, LOW);    // schakel de LED uit door het voltage LOW te maken
        delay(traagheid*space);
        break;

        case '-':
        digitalWrite(LED, HIGH);   // schakel de LED aan (HIGH is the voltage level)
        delay(traagheid*dash);
        digitalWrite(LED, LOW);    // schakel de LED uit door het voltage LOW te maken
        delay(traagheid*space);
        break;

        case ' ':
        delay(traagheid*slash);
        break;

        case '/':
        delay(traagheid*newline);

        

      delay(wachttijd);          // wait for a second
    }
    c+=1;
  }
}
