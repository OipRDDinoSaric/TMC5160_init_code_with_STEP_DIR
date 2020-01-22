#include <SPI.h>

int chipCS = 10;
const byte STEPOUT = 2;
int enable = 8;

void setup() {
  pinMode(chipCS,OUTPUT);
  pinMode(STEPOUT,OUTPUT);
  pinMode(enable, OUTPUT);
  digitalWrite(chipCS,HIGH);
  digitalWrite(enable,HIGH);
  digitalWrite(STEPOUT, LOW);

  SPI.setBitOrder(MSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  SPI.setDataMode(SPI_MODE3);
  SPI.begin();
  // init motor
  // ---------------------
  SPISendData(0x80,0x00000080);      // GCONF
  SPISendData(0xED,0x00000000);      // SGT
  SPISendData(0x94,0x00000040);      // TCOOLTHRS
  SPISendData(0x89,0x00010606);      // SHORTCONF
  SPISendData(0x90,0x00080303);      // IHOLD_IRUN
  SPISendData(0xEC,0x15410153);      // CHOPCONF - microstepping 8
  SPISendData(0xF0,0xC40C001E);      // PWMCONF

  // --------------------- 
  digitalWrite(enable,LOW);
}

void loop() {
}

void SPISendData(unsigned long address, unsigned long datagram)
{
  //TMC5130 takes 40 bit data: 8 address and 32 data
  digitalWrite(chipCS,LOW);
  delayMicroseconds(10);

  SPI.transfer(address);
  SPI.transfer((datagram >> 24) & 0xff);
  SPI.transfer((datagram >> 16) & 0xff);
  SPI.transfer((datagram >> 8) & 0xff);
  SPI.transfer((datagram) & 0xff);
  digitalWrite(chipCS,HIGH);
}
