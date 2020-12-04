/* Tested with 16MHz ATmega328p-AP, QuadX and https://github.com/gcopeland/RF24
Motors use pins 9,6,5,3 instead of 9,10,11,3
nRF24 connections (left is nRF24, right is arduino):q
  CE      7
  CSN    10
  MOSI   11
  MISO   12
  SCK    13
You can change CE and CSN in NRF24_RX.cpp
*/

#ifndef NRF24_RX_H_
#define NRF24_RX_H_

#include "config.h"

#if defined(NRF24_RX)

// The sizeof this struct should not exceed 32 ints
struct RF24Data {
  int throttle;
  int yaw;
  int pitch;
  int roll;
  int AUX1;
  int AUX2;
  int AUX3;
  int AUX4;
//  int switches;
};

/*struct RF24AckPayload {
  float lat;
  float lon;
  int16_t heading;
  int16_t pitch;
  int16_t roll;  
  int32_t alt;
  int flags;
};*/

//extern RF24Data nrf24Data;
//extern RF24AckPayload nrf24AckPayload;
extern int16_t nrf24_rcData[RC_CHANS];

void NRF24_Init();
void NRF24_Read_RC();

#endif

#endif /* NRF24_RX_H_ */
