#include <SPI.h>
#include "CN0391.h"
#include "Communication.h"
#define P4_TYPE TYPE_K
#define P3_TYPE TYPE_K
#define P2_TYPE TYPE_K
#define P1_TYPE TYPE_K
#define DISPLAY_REFRESH     (500)   //ms
#define USE_RTD_CALIBRATION  NO
#define USE_TH_CALIBRATION NO

void setup() {
  Serial.begin(9600);
  SPI.begin();
  SPI.setDataMode(SPI_MODE3); //CPHA = CPOL = 1    MODE = 3
  delay(1000);
  pinMode(CS_PIN, OUTPUT);

  CN0391_init();

//#if(USE_RTD_CALIBRATION == YES)
//   CN0391_calibration(RTD_CHANNEL);
//   Serial.println(F("RTD channel calibration completed!"));
//#else
//   Serial.println(F("Calibration for RTD channel is disabled."));
//#endif
//
//#if(USE_TH_CALIBRATION == YES)
//   CN0391_calibration(TH_CHANNEL);
//   Serial.println(F("TC channel calibration completed!"));
//#else
//   Serial.println(F("Calibration for TC channel is disabled."));
//#endif


   
}

void loop() {
  int channel_selector; 
  char buffer[40];
  if (Serial.available()) { // Check if there's data available on the serial port
    char query = Serial.read(); // Read the incoming query

    if (query == '3') { // If the query is 'A', 
      CN0391_set_data(3);
      CN0391_display_data(3);
    }

    else if (query == '2') { // If the query is 'A', 
      CN0391_set_data(2);
      CN0391_display_data(2);
    }

    else if (query == '1') { // If the query is 'A', 
      CN0391_set_data(1);
      CN0391_display_data(1);
    }

    else if (query == '4') { // If the query is 'P4', 
      CN0391_set_data(4);
      CN0391_display_data(4);
    }
    

       
  

  }
}
