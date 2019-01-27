// define pin numbers
#define analogPin A6
#define hallSensor1 8
#define hallSensor2 3
#define led_vcc 12
#define led_gnd 10

long int t;

void setup() {
  Serial.begin(115200);       // set baud rate to 115200
  // initialize pins and their mode of operation
  pinMode(analogPin,INPUT);   
  pinMode(hallSensor1,INPUT);
  pinMode(hallSensor2,INPUT);
  pinMode(led_vcc,OUTPUT);
  pinMode(led_gnd,OUTPUT);
  digitalWrite(led_vcc,HIGH);
  digitalWrite(led_gnd,LOW);
}
 
void loop() {
  while(true){
  if(digitalRead(hallSensor1)==HIGH){  // trigger when magnet reaches to first sensor
    t=millis();                        // save time of interaction
    break;
  }}
  while(true){
    if(digitalRead(hallSensor2)==HIGH) // trigger when magnet reaches to second sensor
      {
        for(int i=0;i<30;i++)
          Serial.println(analogRead(analogPin));
        Serial.println("3000");       // send code(3000) to indicate "stop reading analog values"  
        Serial.println(t);            // send time of first interaction
        Serial.println(millis());     // send time of second interaction
        break;    
      }
      else
      {
        Serial.println(analogRead(analogPin)); // send analog values
      }
}
}
