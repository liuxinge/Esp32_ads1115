| Object |  Gain Factor |  ADS1015 | ADS1115  |
|-------|-------|------------|--------  |
|ads.setGain(GAIN_TWOTHIRDS);|   2/3x gain +/- 6.144V  |1 bit = 3mv |       0.1875mv (default) |   
|ads.setGain(GAIN_ONE);|      1x gain   +/- 4.096V  | 1 bit = 2mv |       0.125mv |   
|ads.setGain(GAIN_TWO);|          2x gain   +/- 2.048V  | 1 bit = 1mv |       0.0625mv |   
|ads.setGain(GAIN_FOUR);|         4x gain   +/- 1.024V  | 1 bit = 0.5mv |     0.03125mv |   
|ads.setGain(GAIN_EIGHT);|        8x gain   +/- 0.512V  | 1 bit = 0.25mv |    0.015625mv |   
|ads.setGain(GAIN_SIXTEEN);|     16x gain  +/- 0.256V  | 1 bit = 0.125mv |   0.0078125mv | 

End
