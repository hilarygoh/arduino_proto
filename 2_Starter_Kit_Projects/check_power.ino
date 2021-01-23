
const uint8_t PinLED = 13;

void setup( void )
{
 Serial.begin( 9600 );
 Serial.println( "\r\n\r\n" );

 pinMode( PinLED, OUTPUT );
 digitalWrite( PinLED, LOW );
 delay( 1000 );

 analogReference( INTERNAL );
}

void loop( void )
{
 Serial.println( analogRead( 0 ) );
 digitalWrite( PinLED, HIGH );
 delay( 1000 );
}