// Copyright 2018 Joseph Smith
#include <stdio.h>
#include <stdint.h>
int DecodeCan(unsigned char message[]) {
message[0] = message[0] & 0x3f;
uint16_t longMessage = message[0];
longMessage = longMessage << 8;
longMessage += message[1];
longMessage = longMessage >> 5;
return static_cast<int>(longMessage);
}

int main() {
unsigned char abc[4][5] ={{0x01, 0x40, 0x00, 0x00, 0x00},
                          {0x06, 0x40, 0x00, 0x00, 0x00},
                          {0x09, 0x60, 0x00, 0x00, 0x00},
                          {0x0C, 0x80, 0x00, 0x00, 0x00}};
printf("Message 1: %d \n", DecodeCan(abc[0]));
printf("Message 2: %d \n", DecodeCan(abc[1]));
printf("Message 3: %d \n", DecodeCan(abc[2]));
printf("Message 4: %d \n", DecodeCan(abc[3]));
return(0);
}


