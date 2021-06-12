#include <i2c_master.h>
#include <peripherals.h>
#include <stdio.h>
#include <string.h>
#include <uart.h>


FILE * stdout = &UART_LIGHT_FILE;
extern int s;

void i2c_peri_enable(){
	I2C_MASTER.ctrl = 0; //clear
	I2C_MASTER.ctrl |= 299;
	I2C_MASTER.ctrl |= I2C_CTRL_EN;
	I2C_MASTER.ctrl |= I2C_CTRL_INTR_EN;		//interrupt
}

void i2c_peri_read1(){
	//while(I2C_MASTER.stat & I2C_STA_TIP);
	I2C_MASTER.cmd = 0; //clear

	I2C_MASTER.data[0] = 0xE0;	//Slave Adresse
	I2C_MASTER.data[1] = 0x2;	//Register Nummer
	I2C_MASTER.cmd = I2C_CMD_STA | (2<<3);
	s = 2;
	}

void i2c_peri_read2(){
	//while(I2C_MASTER.stat & I2C_STA_TIP);
	//I2C_MASTER.cmd = 0; //clear;
	if (I2C_MASTER.stat & I2C_STA_NO_ACK) i2c_peri_read1(); //Wenn no ack, noch einmal machen
	else 
	{s = 0;
	I2C_MASTER.data[0] = 0xE0+1;
	I2C_MASTER.cmd = I2C_CMD_RD | I2C_CMD_STA | (3<<3) | I2C_CMD_STO;
	}
	//I2C_MASTER.cmd = I2C_CMD_RD | I2C_CMD_STA | (3<<3);
	//if (I2C_MASTER.stat & I2C_STA_NO_ACK) s = 2; //Wenn no ack, noch einmal machen
	//else s = 0;
	//s = 0;
	}


int i2c_peri_read3(){
	//while(I2C_MASTER.stat & I2C_STA_TIP);


	//berechnen
	int a = I2C_MASTER.data[1], b = I2C_MASTER.data[2]; //Register2, Register3
	int c = (a * 256) + b;
	//printf("c=%d\n",c);
	//I2C_MASTER.cmd |= I2C_CMD_STO;
	
	printf("%x, %x\n",I2C_MASTER.data[1],I2C_MASTER.data[2]);//einfach drucken
	return c;
}

void i2c_peri_write(){
	// Messvorgang Command
	//while(I2C_MASTER.stat & I2C_STA_TIP);
	
	I2C_MASTER.cmd = 0; //clear

	I2C_MASTER.data[0] = 0xE0;	//Slave Adresse
	I2C_MASTER.data[1] = 0x00;	//Register Nummer
	I2C_MASTER.data[2] = 0x51;	//startet Messvorgang (cm)

	I2C_MASTER.cmd = I2C_CMD_STA | (3<<3) | I2C_CMD_STO;

	s=1;
	

	
}
