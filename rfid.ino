#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>
#include <SPI.h>
#include <RFID.h>

#define SDA_DIO 22
#define RESET_DIO 23

RFID RC522(SDA_DIO, RESET_DIO); 

void setup()
{ 
  Serial.begin(9600);
  SPI.begin(); 
  RC522.init();
}

void loop()
{
  if (RC522.isCard())
  {
    RC522.readCardSerial();
    Serial.println("Card detected:");
    for(int i=0;i<5;i++)
    {
    Serial.print(RC522.serNum[i],DEC);
    }
    Serial.println();
    Serial.println();
  }
  delay(1000);
}
