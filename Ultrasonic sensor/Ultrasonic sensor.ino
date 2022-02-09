#include "ThingSpeak.h"
#include "WiFi.h"
//-------Enter your WiFi Details------//
char ssid[] = "Mahima";  //SSID
char pass[] = "mahima@98";  //Password
//-----------------------------------//
WiFiClient client;
//-------------ThingSpeak Details-----------------//
unsigned long myChannelField =  1646497; //Channel ID
const int ChannelField1 = 1;
//const int ChannelField2 = 2;
const char * myWriteAPIKey = "GA7US2J3TX14URNS"; //Your Write API Key
//-----------------------------------------------//

const int trigger = 5;
const int echo = 18;
long T;
float distanceCM;
WiFiClient client;


void setup() 
{
 pinMode(trigger, OUTPUT); // declare trigger as output
 pinMode(echo, INPUT); // echo as input
 Serial.begin(115200);
 
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}

void loop(){
  //-----------------WiFi Setup-------------------//
  if(WiFi.status()!= WL_CONNECTED)
  {
    Serial.print("Attempting to Connect to SSID: ");
    Serial.println(ssid);
    while(WiFi.status()!= WL_CONNECTED)
   {
     WiFi.begin(ssid,pass);
     Serial.print(".");
     delay(5000);
   }
    Serial.println("\nConnected.");
  }
  //--------------------------------------------//

  digitalWrite(trigger, LOW);
  delay(1);
  digitalWrite(trigger, HIGH);
  delayMicr oseconds(10);
  digitalWrite(trigger, LOW);
  T = pulseIn(echo, HIGH);
  distanceCM = (T * 0.034)/2;
  Serial.print("Distance in cm: ");
  serial.println(distanceCM);

  ThingSpeak.writefield(myChannelField,ChannelFeild1, distanceCM, myWriteAPIKey);
  delay(1000);
}