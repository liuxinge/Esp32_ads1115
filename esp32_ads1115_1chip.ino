#include <Wire.h>
#include <Adafruit_ADS1015.h>
// Forked form Adafruit, please buy open source hardware from 
// Adafruit to support them.

Adafruit_ADS1115 ads(0x49);  /* Use this for the 16-bit version */
//Adafruit_ADS1015 ads;     /* Use this for the 12-bit version */

double gainFactor = 0.0001875;

void setup(void) 
{
  Serial.begin(9600);
  Serial.println("Hello!");
  
  Serial.println("Getting single-ended readings from AIN0..3");
  Serial.println("ADC Range: +/- 6.144V (1 bit = 3mV/ADS1015, 0.1875mV/ADS1115)");

  // The ADC input range (or gain) can be changed via the following
  // functions, but be careful never to exceed VDD +0.3V max, or to
  // exceed the upper and lower limits if you adjust the input range!
  // Setting these values incorrectly may destroy your ADC!
  //                                                                ADS1015  ADS1115
  //                                                                -------  -------
  // ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
  // ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV
  // ads.setGain(GAIN_TWO);        // 2x gain   +/- 2.048V  1 bit = 1mV      0.0625mV
  // ads.setGain(GAIN_FOUR);       // 4x gain   +/- 1.024V  1 bit = 0.5mV    0.03125mV
  // ads.setGain(GAIN_EIGHT);      // 8x gain   +/- 0.512V  1 bit = 0.25mV   0.015625mV
  // ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV
  
  ads.begin();
}

void loop(void) 
{
  int16_t adc0, adc1, adc2, adc3;
  double AIN0, AIN1, AIN2, AIN3;
 
  adc0 = ads.readADC_SingleEnded(0);
  adc1 = ads.readADC_SingleEnded(1);
  adc2 = ads.readADC_SingleEnded(2);
  adc3 = ads.readADC_SingleEnded(3);

  Serial.print("adc0: "); Serial.println(adc0);
  Serial.print("adc1: "); Serial.println(adc1);
  Serial.print("adc2: "); Serial.println(adc2);
  Serial.print("adc3: "); Serial.println(adc3);
  Serial.println(" ");
  
  AIN0 = gainFactor * ads.readADC_SingleEnded(0);
  AIN1 = gainFactor * ads.readADC_SingleEnded(1);
  AIN2 = gainFactor * ads.readADC_SingleEnded(2);
  AIN3 = gainFactor * ads.readADC_SingleEnded(3);

  Serial.print("AIN0: "); Serial.println(AIN0, 4);
  Serial.print("AIN1: "); Serial.println(AIN1, 4);
  Serial.print("AIN2: "); Serial.println(AIN2, 4);
  Serial.print("AIN3: "); Serial.println(AIN3, 4);
  Serial.println(" ");
  
  delay(1000);
}
