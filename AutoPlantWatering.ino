/*
----------------------
GUIDE TO ME IN FUTURE:::::
----------------------

----------------------
How to wire soil moisture sensor:
----------------------
Yellow: A0
Red: cmon you know this
black: you know this too 

------------------------

-----------------
How to wire Relay:
-------------------
connect bottom to pin 7
middle to power
top to ground

For the other side connect the power supplies power to the top
the valves power to the middle
and the power supplies ground to the valve
------------------

----------------
power supply
----------
Over 6 volts
-----------
*/


#define AOUT_PIN A0
#define RELAY_PIN 7

const int moisture_threshold = 400;
bool watering = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(RELAY_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int moisture_value = analogRead(AOUT_PIN);
  
  if ((moisture_value < moisture_threshold) && (watering == false)){
    watering = true;
    Serial.print("Too dry, watering plants.");
    waterPlants(10000);
  }
  else{
    Serial.print("Moisture: ");
    Serial.println(moisture_value);
  }


  delay(1000);
}

void waterPlants(int duration){
  digitalWrite(RELAY_PIN, HIGH);   // turn the RELAY on 
  delay(duration);                     // wait for a second
  digitalWrite(RELAY_PIN, LOW); 
}
