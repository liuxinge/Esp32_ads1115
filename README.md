# This is the function for ads1115 working with ESP32 
# Chips: 
Expressif ESP32  
TI ADS1115  
4 channel I2C 16 bits ADC Chip   

The ADC input range (or gain) for ADS1115 can be changed via the following functions, but be careful never to exceed VDD +0.3V max, or to 
exceed the upper and lower limits if you adjust the input range!  
Setting these values incorrectly may destroy your ADC!  
                                                          &nbsp; |    ADS1015 | ADS1115  
              ----------------------------------                                                 
ads.setGain(GAIN_TWOTHIRDS);  | 2/3x gain +/- 6.144V  |1 bit = 3mV     | 0.1875mV (default)  
ads.setGain(GAIN_ONE);  |     1x gain   +/- 4.096V  1 bit = 2mV      0.125mV  
ads.setGain(GAIN_TWO);          2x gain   +/- 2.048V  1 bit = 1mV      0.0625mV  
ads.setGain(GAIN_FOUR);         4x gain   +/- 1.024V  1 bit = 0.5mV    0.03125mV  
ads.setGain(GAIN_EIGHT);        8x gain   +/- 0.512V  1 bit = 0.25mV   0.015625mV  
ads.setGain(GAIN_SIXTEEN);     16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV  

The I2C address of ADS1115 depend on how it ADDR pin was connected:   

   &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;    &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;S

GND    &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;                 1001000                 0x48  
VDD                     1001001                 0x49  
SDA                     1001010                 0x50  
SCL                     1001011                 0x51  

| ADDR PIN CONNECTION  | SLAVE ADDRESS in Bin |LAVE ADDRESS in Hex  |
| ------------- | ------------- |----------|
| GND |  1001000| 0x48|
|  VDD| 1001001| 0x49|
| SDA |  1001010| 0x50|
| SCL |  1001011|  0x51|
