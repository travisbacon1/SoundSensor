
/**************************************************************************/
/*!
Sound Sensor
*/
/**************************************************************************/

int soundSensor=A2;                         // Set analog pin 2 for receiving analog sound data
int GreenLED = 3;                           // Set digital pin 3 as green LED output
int RedLED = 4;                             // Set digital pin 3 as red LED output
int SoundOffset = 60;                       // Set noise offset to 0 data (offset determined using Serial Plotter)
boolean GreenLEDStatus = true;              // Set green LED to on
boolean RedLEDStatus = false;               // Set red LED to off

void setup() {
 pinMode(soundSensor,INPUT);                // Set temperature sensor as an input
 pinMode(GreenLED,OUTPUT);                  // Set green LED as an output
 pinMode(RedLED,OUTPUT);                    // Set red LED as an output
 Serial.begin(9600);                        //

}

void loop() {

  int SensorData=analogRead(soundSensor);   // Read sound
  int SensorData2 = SensorData-Offset;      // Subtract offset (determined from Serial Plotter)
  int SoundThreshold = 2;                   // Set arbitrary sound threshold to change LED outputs
  
  Serial.println();
  Serial.print(SensorData2);                // Print sound data

  if(SensorData2>SoundThreshold){           // If sound exceeds threshold, switch green LED off and red LED on

    GreenLEDStatus=false;
    RedLEDStatus=true;
    digitalWrite(GreenLED,LOW);
    digitalWrite(RedLED,HIGH);
    }
  else{
    RedLEDStatus=false;                     // If sound drops below threshold, switch rred LED off and green LED on
    GreenLEDStatus=true;
    digitalWrite(GreenLED,HIGH);
    digitalWrite(RedLED,LOW);
    }
  }
