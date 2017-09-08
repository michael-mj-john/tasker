
#include <ESP8266WiFi.h>
#include <DNSServer.h> //Local DNS Server used for redirecting all requests to the configuration portal
#include <ESP8266WebServer.h> //Local WebServer used to serve the configuration portal
#include <WiFiManager.h> //https://github.com/tzapu/WiFiManager WiFi Configuration Magic

#include <NTPClient.h>
#include <WiFiUdp.h>

#include "FastLED.h"

#include <stdlib.h>
#include <cstring>
#include <string>

const char* host = "thegamemechanic.net";
#define LED_PIN 2
#define NUM_LEDS 1
int LEDV = 100; // brightness value of LEDS

WiFiUDP ntpUDP;
WiFiManager wifiManager; // will obtain wifi credentials locally


// By default 'time.nist.gov' is used with 60 seconds update interval and
// offset (in seconds), frequency (in milliseconds)
NTPClient timeClient(ntpUDP, "time.nist.gov", -(7*60*60), (10*1000) );

CRGB leds[NUM_LEDS];

#define CLEARBUTTON 16

#include "task.h"

task task1( 23, 24, 10, 2 );


/******************************************
 * SETUP
 ******************************************/
void setup() {


  FastLED.addLeds<WS2811, LED_PIN, RGB>(leds, NUM_LEDS);

  Serial.begin( 115200 );

  pinMode( CLEARBUTTON, INPUT );

  wifiManager.autoConnect("joffmanElectric");

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
  timeClient.begin();
  
}

/******************************************
 * LOOP
 ******************************************/
void loop() {

  timeClient.update();  //make sure this doesn't happen too often

  task1.updateTask();

  Serial.println( timeClient.getHours() );
  Serial.println( timeClient.getDay() );
  Serial.println( timeClient.getEpochTime() );
  Serial.println( timeClient.getFormattedTime() );

  FastLED.show();

  delay(2000);
  
} 
