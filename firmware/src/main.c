#include <peripherals.h>
#include <uart.h>
#include <peripherals/intctrl.h>
#include <interrupt.h>
#include <stdio.h>
#include <spi.h>
#include <spi_master.h>
#include <spi_slave.h>
#include <spi_common.h>
#include <display.h>
#include <SPI_FUNKTION.h>
#include <i2c_master.h>
#include <i2c_treiber.h>
#include <stdlib.h>	//itoa

#define _SLEEP_MS(sleep_time) sleep_sleep((SB_SPARTANMC_FREQUENCY/1000-3)/3,sleep_time)

int s = 0;	//interrupt status
int c; //return value from I2C
char sum[100];//Daten sammeln 
int n=0; //counter
char a[]="HELLO,WORLD\n";
char b[]="Der Abstand ist:";

//FILE * stdout = &UART_LIGHT_FILE;


void display(){
	snprintf(a,10,"%d",c);
	//printf("c=%d\n",c);
	//printf("Der Abstand ist: %s\n",a);
	
	//immer 3 bit nummer anzeigen, keine Ziffer übrig bleiben.
	if (c<100){
		a[3] = a[2];
		a[2] = a[1];
		a[1] = a[0];
		a[0] = '0';	
	}
	printf("Der Abstand=%s\n",a);
	Show_String_25664(1, b, 9, 9);
	Show_String_25664(1, a, 45, 9);
}


void filter(){
if(n<100)
{
	printf("n=%d\n",n);
	printf("c=%d",c);
	sum[n] = c;
	n++;
}
else
{
	for(int j=0; j<99; j++){
		for(int i=0; i<99-j; i++){
			int temp;//um array zu wechseln
			if(sum[i]>sum[i+1]){
				temp = sum[i+1];
				sum[i+1] = sum[i];
				sum[i] = temp;
			}
		}
	}
	c = sum[50];
	//printf("c=%d",c);
	display();
	n=0;
}

/*
else if (n == 101)
{
	printf("n=%d\n",n);
	printf("c=%d",c);
	sum[50] = c;	//muss den Mittelwert ändern, sonst wird ein großer Wert immer an Ende liegen, es macht keinen Sinn für die ganze Reihe 
	for(int j=0; j<99; j++){
		for(int i=0; i<99-j; i++){
			int temp;//um array zu wechseln
			if(sum[i]>sum[i+1]){
				temp = sum[i+1];
				sum[i+1] = sum[i];
				sum[i] = temp;
			}
		}
	}
	c = sum[50];
	display();
}*/
}


ISR(0)(){	//interrupt service routine 
	printf("hello world! ISR\n");
	
	switch(s){
		case 0:
			c = i2c_peri_read3(); 
			filter();           //sum;
			i2c_peri_write(); 
			printf("case 0\n");
			break;
		case 1: i2c_peri_read1();printf("case 1\n");break;
		case 2: i2c_peri_read2(); printf("case 2\n");break;	//int value returned from the sensor
		default: printf("error!");
	}
}


void main(){
	interrupt_enable();
	peri_enable();
	peri_select();
	OLED_Init_25664();
	Fill_RAM_25664(0);	//screen clean black
	//Grayscale_25664();	//screen Farbe von dunkel nach hell
	i2c_peri_enable();
	printf("test__");
	i2c_peri_write();
	peri_deselect();
}	

	/*while(1){
		i2c_peri_write();
		_SLEEP_MS(65);
		c = i2c_peri_read(); //int value returned from the sensor
		snprintf(a,10,"%d",c);
		printf("c=%d\n",c);
		printf("string=%s\n",a);
		//immer 3 bit nummer anzeigen, keine Ziffer übrig bleiben.
		if (c<100){
			a[3] = a[2];
			a[2] = a[1];
			a[1] = a[0];
			a[0] = '0';	
		}
		printf("n=%s\n",a);
		Show_String_25664(1, a, 9, 9);
	}*/

	


