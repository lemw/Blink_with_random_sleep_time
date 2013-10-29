/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);   
  Serial.begin(9600);  
}

// the loop routine runs over and over again forever:
void loop() {
  int iMin = 1;
  int iMax = 1024;
  do {
    int iRandom = random(iMin, iMax);
    int iSpan = iMax - iMin;
    Serial.print( "Span value: " );
    Serial.print( iSpan, DEC );
    Serial.print( "Min value: " );
    Serial.print( iMin, DEC );
    Serial.print( " Max value: " );
    Serial.print( iMax );
    Serial.print( " Sleep value: " );
    Serial.print( iRandom );
    if ( iMax - iMin < 10 ) //If the span is to small
    {
      iMin = 0;
      iMax = 999;
    }
    else if ( iRandom < ((iMax + iMin) / 2))//If iRandom is in the lower part of the span, adjust lower limit
    {
      iMin = iMin;
    }
    else //This means the iRandon is in the upper part of the span
    {
      iMax = iRandom;
    }
    Serial.print( " adjusting limits " );
    Serial.print( "Min value: " );
    Serial.print( iMin, DEC );
    Serial.print( " Max value: " );
    Serial.print( iMax );
    Serial.print( " Sleep value: " );
    Serial.println( iRandom );
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(iRandom);               // wait for a second
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    delay(iRandom);   // wait for a second
  } while ( true );
}
