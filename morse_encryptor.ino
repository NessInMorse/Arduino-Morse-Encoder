int LED=13;   //LED used for the conversion of text to morse code
int startingLED=11; //LED used for signaling the start of the Morse code message
String translation="";
int waittime=1000;
int slowness=4; // A variabele to make the Morse go slower, pauses take longer and uptime of LED's is longer
int dot=100;    //length of a dot(.)
int dash=500;   //length of a dash(-)
int empty=100;  //length of the empty between dots and dashes within letters
int space=400;  //length of spaces in between letters
int slash=1200;  //length of spacees in between words


void setup()
{                
  pinMode(LED, OUTPUT); //Pin used for the morse code message
  pinMode(startingLED,OUTPUT); //Pin used for signaling to the user that the sentence is beginning

  String text="hello world"; //Text to be converted into Morse code, is only to converse downcase letters
  String Alphabet="abcdefghijklmnopqrstuvwxyz ";
  //Current version of morse code conversion is unable to convert capital letters, numbers or reading signs
  String Morseconversion[27]={".- ","-... ","-.-. ","-.. ",". ","..-. ","--. ",".... ",".. ",".--- ","-.- ",".-.. ","-- ","-. ","--- ",".--. ","--.- ",".-. ","... ","- ","..- ","...- ","-..- ","-.-- ","--.."," / "};

  for(int i=0;i<text.length();i++)   
  {
    translation+=Morseconversion[Alphabet.indexOf(text[i])];
  }
}


void loop() 
{
  int c=0;
  //Signaling LED to show the message is starting, to make it easier to differentiate the message their start and rest
  digitalWrite(startingLED, HIGH);   // LED on
  delay(slowness*dot);
  digitalWrite(startingLED, LOW);    // LED off
  delay(slowness*empty);
  
  while (c<translation.length())
  {
    switch(translation[c]){


        case '.':
        digitalWrite(LED, HIGH);   
        delay(slowness*dot);
        digitalWrite(LED, LOW);    
        delay(slowness*empty);
        break;

        case '-':
        digitalWrite(LED, HIGH);   
        delay(slowness*dash);
        digitalWrite(LED, LOW);    
        delay(slowness*empty);
        break;

        case ' ':
        delay(slowness*space);
        break;

        case '/':
        delay(slowness*slash);
        break;

       
      delay(waittime);          // wait for a second
    }
    c+=1;
  }
}
