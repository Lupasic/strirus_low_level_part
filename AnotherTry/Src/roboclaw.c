#include "roboclaw.h"

unsigned int crc16 (unsigned char *packet, int nBytes) {
	unsigned short crc = 0;
	for (int byte = 0; byte < nBytes; byte++) {
		crc = crc ^ ((unsigned int)packet[byte] << 8);
		for (unsigned char bit = 0; bit < 8; bit++) {
			if (crc & 0x8000) {
					crc = (crc << 1) ^ 0x1021;
			} else {
				crc = crc << 1;
			}
		}
	}
	return crc;
}
unsigned char in_range(unsigned char x, unsigned char a, unsigned char b) {
	if (x < a) return a;
	if (x > b) return b;
	return x;
}

HAL_StatusTypeDef motorForward(unsigned char roboclaw, unsigned char motor, unsigned char speed) {
	unsigned char buffer[5];
	buffer[0] = roboclaw;
	if(motor == 0) buffer[1] = 0;
	else if(motor == 1) buffer[1] = 4;
	buffer[2] = in_range(speed, 0, 127);
	unsigned short crc = crc16(buffer, 3);
	buffer[3] = crc>>8;
	buffer[4] = crc;
	return HAL_UART_Transmit(&huart2, buffer, 5, 100);
}

HAL_StatusTypeDef motorBackward	(unsigned char roboclaw, unsigned char motor, unsigned char speed) {
	unsigned char buffer[5];
	buffer[0] = roboclaw;
	if(motor == 0) buffer[1] = 1;
	else if(motor == 1) buffer[1] = 5;
	buffer[2] = in_range(speed, 0, 127);
	unsigned short crc = crc16(buffer, 3);
	buffer[3] = crc>>8;
	buffer[4] = crc;
	return HAL_UART_Transmit(&huart2, buffer, 5, 100);
}

HAL_StatusTypeDef motorMove	(unsigned char roboclaw, unsigned char motor, signed char speed) {
	if(speed >= 0) {
		return motorForward(roboclaw, motor, in_range(speed, 0, 127));
	}
	else {
		return motorBackward(roboclaw, motor, in_range(-(signed char)speed, 0, 127));
	}
}

HAL_StatusTypeDef allMotorsMove (signed char* speeds) {
	HAL_StatusTypeDef result;
	for (int i = 0, roboclaw = 0; roboclaw < 6; roboclaw++) {
		for (char motor = 0; motor < 2; motor++, i++) {
			result = motorMove(roboclaw0 + roboclaw, motor, speeds[i]);
		}
	}
	return result;
}
