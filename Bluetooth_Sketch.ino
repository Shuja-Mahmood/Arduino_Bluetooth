char data = 'F';                      //Variable for storing received data
int brightness = 252;
void setup() 
{
  Serial.begin(9600);               //Sets the data rate in bits per second (baud) for serial data transmission
  pinMode(13, OUTPUT);              //Sets digital pin 13 as output pin
}
void loop()
{
  if(Serial.available() > 0)        // Send data only when you receive data:
  {
    data = Serial.read();           //Read the incoming data and store it into variable data
    Serial.print(data);             //Print Value inside data in Serial monitor
    Serial.print("\n");             //New line 
    if(data == 'T')                 //Checks whether value of data is equal to 1 
      analogWrite(13, brightness);  //If value is 1 then LED turns ON
    else if(data == 'F')            //Checks whether value of data is equal to 0
      analogWrite(13,0);            //If value is 0 then LED turns OFF
    else
      brightness = (data * 28) - 1344;
  }                            
}
