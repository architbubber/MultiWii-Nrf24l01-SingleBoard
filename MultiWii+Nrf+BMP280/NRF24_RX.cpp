#include "Arduino.h"
#include "config.h"
#include "def.h"
#include "types.h"
#include "MultiWii.h"
#include <RF24.h>
#include "NRF24_RX.h"

#if defined(NRF24_RX)

int16_t nrf24_rcData[RC_CHANS];

// Single radio pipe address for the 2 nodes to communicate.

const byte thisSlaveAddress[5] = {'R','x','A','A','A'}; //Remember, SAME AS TRANSMITTER CODE

RF24 radio(7,10); // CE, CSN

RF24Data MyData;
void radio_setup(){
    radio.begin();
    radio.setDataRate( RF24_250KBPS );
    radio.setPALevel(RF24_PA_MAX);
    radio.setChannel(69);
    radio.openReadingPipe(1, thisSlaveAddress);
    radio.startListening();
}
void resetRF24Data() 
{
  MyData.throttle = 0;
  MyData.yaw = 1502;
  MyData.pitch = 1502;
  MyData.roll = 1502;

  //Same as the transmitter code
  MyData.AUX1 = 0;
  MyData.AUX2 = 0;
  MyData.AUX3 = 0;
  MyData.AUX4 = 0;
}

void NRF24_Init() {
  resetRF24Data();
  radio_setup();             
  digitalWrite(8,LOW); 
}

void NRF24_Read_RC() {
  
  static unsigned long lastRecvTime = 0;
  unsigned long now = millis();
  while( radio.available() ) {
    digitalWrite(8,HIGH);
    radio.read(&MyData, sizeof(RF24Data));
    lastRecvTime = now;
    nrf24_rcData[AUX4] = 2000;
  }
 if ( now - lastRecvTime > 1000 ) {
  
      // signal lost?
    digitalWrite(8,LOW);
    nrf24_rcData[AUX4] =     1000;
    resetRF24Data();
  }
  nrf24_rcData[THROTTLE] =  MyData.throttle;
  nrf24_rcData[ROLL] =      MyData.roll;
  nrf24_rcData[PITCH] =     MyData.pitch  ;
  nrf24_rcData[YAW] =       MyData.yaw;

  nrf24_rcData[AUX1] =     MyData.AUX1;
  nrf24_rcData[AUX2] =     MyData.AUX2;
  nrf24_rcData[AUX3] =     MyData.AUX3;
   //If your channels are inverted, reverse the map value. Example. From 1000 to 2000 ---> 2000 to 1000
  
}

#endif
