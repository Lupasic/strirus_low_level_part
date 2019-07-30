//See BareMinimum example for a list of library functions

//Includes required to use Roboclaw library
#include <SoftwareSerial.h>
#include "RoboClaw.h"

//See limitations of Arduino SoftwareSerial
SoftwareSerial serial(10,11);	
RoboClaw roboclaw(&serial,10000);

#define address 0x80
#define address0 0x80
#define address1 0x81
#define address2 0x82
#define address3 0x83
#define address4 0x84
#define address5 0x85

void moveUrAss(int speed) {
//    roboclaw.ForwardBackwardM1(address0, speed);
//    roboclaw.ForwardBackwardM2(address0, speed);
//    roboclaw.ForwardBackwardM1(address1, speed);
//    roboclaw.ForwardBackwardM2(address1, speed);
//    roboclaw.ForwardBackwardM1(address2, speed);
//    roboclaw.ForwardBackwardM2(address2, speed);
//    roboclaw.ForwardBackwardM1(address3, speed);
//    roboclaw.ForwardBackwardM2(address3, speed);
//    roboclaw.ForwardBackwardM1(address4, speed);
//    roboclaw.ForwardBackwardM2(address4, speed);
//    roboclaw.ForwardBackwardM1(address5, speed);
//    roboclaw.ForwardBackwardM2(address5, speed);
    roboclaw.ForwardM1(address0, speed);
    roboclaw.ForwardM2(address0, speed);
    roboclaw.ForwardM1(address1, speed);
    roboclaw.ForwardM2(address1, speed);
    roboclaw.ForwardM1(address2, speed);
    roboclaw.ForwardM2(address2, speed);
    roboclaw.ForwardM1(address3, speed);
    roboclaw.ForwardM2(address3, speed);
    roboclaw.ForwardM1(address4, speed);
    roboclaw.ForwardM2(address4, speed);
    roboclaw.ForwardM1(address5, speed);
    roboclaw.ForwardM2(address5, speed);
}

void setup() {
  //Open roboclaw serial ports
  roboclaw.begin(115200);
}

void loop() {

  moveUrAss(20);
  delay(10000000);
}
