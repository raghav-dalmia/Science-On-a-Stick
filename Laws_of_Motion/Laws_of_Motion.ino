// define pins used
#define hallSensor1 8
#define hallSensor2 7
#define hallSensor3 3
#define led_vcc 10
#define led_gnd 12

long int timet[3];   //buffer to store time of interaction
void setup() 
{
Serial.begin(9600);           // set baud rate to 9600
// initialize pins
pinMode(hallSensor1,INPUT);
pinMode(hallSensor2,INPUT);
pinMode(hallSensor3,INPUT);
pinMode(led_vcc,OUTPUT);
pinMode(led_gnd,OUTPUT);
digitalWrite(led_vcc,HIGH);
digitalWrite(led_gnd,LOW);
}

void loop()
{
// read height between the hall sensors
int cnt=0;
int h[2];
bool p=true;
while(cnt!=2)
{
  if(p && cnt<2)
  {
    if(cnt==0)
    {
      Serial.print("Enter distance between first and second point in cm : ");
      p=false;
    }
    else if(cnt==1)
    {
      Serial.print("Enter distance between first and third point in cm : ");
      p=false;
    }
  }
  int a;
  a=Serial.parseInt();
  if(a!=0)
  {
    h[cnt]=a;
    Serial.print(h[cnt]);
    Serial.println("cm");
    cnt++;
    p=true;
  }
}
// read time of interaction
Serial.println();
Serial.println("Now drop the magnet....");
while (true)
{
  if(digitalRead(hallSensor1)==HIGH)  // trigger when magnet interact with first sensor
  {
    //Serial.println(1);
    timet[0]=millis();
    break;
  }
}
while (true)
{
  if(digitalRead(hallSensor2)==HIGH)  // trigger when magnet interact with second sensor
  {
    //Serial.println(2);
    timet[1]=millis();
    break;
  }
}
while (true)
{
  if(digitalRead(hallSensor3)==HIGH)  // trigger when magnet interact with third sensor
  {
    //Serial.println(3);
    timet[2]=millis();
    break;
  }
}
// print time take
Serial.println("Observed Time : ");
Serial.println();
Serial.print("Time taken by object to cross second point is : ");
Serial.print(timet[1]-timet[0]);
Serial.println(" ms");
Serial.print("Time taken by object to cross third point is : ");
Serial.print(timet[2]-timet[0]);
Serial.println(" ms");
Serial.println();
// calculation of acceleration due to gravity
Serial.print("Calculated acceleration due to gravity is : ");
float g[2];
g[0]=0.02*h[0];
float t=timet[1]-timet[0];
t/=1000;
g[0]/=t;
g[0]/=t;
g[1]=0.02*h[1];
t=timet[2]-timet[0];
t/=1000;
g[1]/=t;
g[1]/=t;
float G=g[0]+g[1];
G/=2;
Serial.print(G);
Serial.println(" m/s^2");
}


