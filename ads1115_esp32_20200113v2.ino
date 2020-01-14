#include <Wire.h>
#include <Adafruit_ADS1015.h>

// This is an funciton for Esp32 to connect 4 ads1115 chips and read each
// chip to get each channel's input.

void setup(void) 
{
  Serial.begin(9600);
}

void loop(void){
  ADS1115();
}

void ADS1115(void) 
{
 
 double AinV[16];
 double gainFactor = 0.0001875;
 int I2C_address = 0x48;
 
 for (int j = 0; j < 4; j++){

  I2C_address = I2C_address + j;
  Adafruit_ADS1115 ads(I2C_address);  /* Use this for the 16-bit version */
  ads.begin();

  int16_t adcChannel;
  
  for(int i = 0; i < 4; i ++){ 
     adcChannel = ads.readADC_SingleEnded(i); 
     if (adcChannel < 0) {adcChannel = 0;}
     AinV[i+j*4] = gainFactor * adcChannel;
     Serial.print("AinV "); Serial.print(i+j*4); Serial.print(": ");Serial.println(AinV[i+j*4], 4);

    } 
  Serial.println("");
 }
  delay(1000);
}
