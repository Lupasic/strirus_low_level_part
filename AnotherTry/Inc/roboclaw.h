#ifdef __cplusplus
 extern "C" {
#endif

#include "usart.h"

#define roboclaw0 0x80
#define roboclaw1 0x81
#define roboclaw2 0x82
#define roboclaw3 0x83
#define roboclaw4 0x84
#define roboclaw5 0x85


unsigned int crc16 (unsigned char *packet, int nBytes);

HAL_StatusTypeDef motorForward(unsigned char roboclaw, unsigned char motor, unsigned char speed);
HAL_StatusTypeDef motorBackward	(unsigned char roboclaw, unsigned char motor, unsigned char speed);

HAL_StatusTypeDef motorMove	(unsigned char roboclaw, unsigned char motor, signed char speed);
