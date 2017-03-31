#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

char* I2C_ASCII(char name, uint16_t temp, uint16_t humidity, uint16_t UV);

int main()
{
    char* final_string;
    final_string = I2C_ASCII('1', 0x27, 0x32, 0x3);
    printf("The string is: %s\n", final_string);
    printf("The string is: %s\n", I2C_ASCII('5', 0x7FFF, 0x7FFF, 0x7FFF));
}



//This functions main properties is to take the I2C hex values and convert
//it to ASCII values for the Pi. The function will return the char array bufferf
//as the final string which includes all the element in the parameter


char* I2C_ASCII(char name, uint16_t temp, uint16_t humidity, uint16_t UV)
{

    char new_name = name;
    int int_name = new_name - '0';
    static char bufferf[14];
    itoa(int_name, bufferf, 16);
    printf("Hexadecimal value = %s\n", bufferf);


    uint16_t new_temp = temp;
    char buffer0[13];
    itoa(temp, buffer0, 16);
    printf("Hexadecimal value = %s\n", buffer0);

    uint16_t new_humidity = humidity;
    char buffer1[9];
    itoa(new_humidity, buffer1, 16);
    printf("Hexadecimal value = %s\n", buffer1);

    uint16_t new_UV = UV;
    char buffer2[5];
    itoa(new_UV, buffer2, 16);
    printf("Hexadecimal value = %s\n", buffer2);

    strcat(buffer1,buffer2);
    strcat(buffer0,buffer1);
    strcat(bufferf,buffer0);
    printf("Final string is %s\n", bufferf);


    return bufferf;

    free(buffer0);
    free(buffer1);
    free(buffer2);
    free(bufferf);


}


