#include <peripherals.h>
#include <uart.h>
#include <stdio.h>
#include <spi.h>
#include <spi_master.h>
#include <spi_slave.h>
#include <spi_common.h>
#include<display.h>


void peri_enable()
{
	SPI_MASTER.spi.spi_control = 0;
	SPI_MASTER.spi.spi_control |= (1<<13);
	SPI_MASTER.spi.spi_control &= ~SPI_MASTER_CTRL_BITCNT;
	SPI_MASTER.spi.spi_control |= (9<<8); //(bitcnt)
	SPI_MASTER.spi.spi_control |= SPI_MASTER_CTRL_EN; //(en)	
	
}

void peri_select()
{
	SPI_MASTER.spi.spi_control |= (1 << 4);
	
}

void peri_deselect()
{
	while (SPI_MASTER.spi.spi_status | 0x00000);
	SPI_MASTER.spi.spi_control &= ~SPI_MASTER_CTRL_SLAVE;
}
void peri_write(unsigned char v)
{
	//gucken ob (manual P155) das Status Register voll ist
	while (SPI_MASTER.spi.spi_status & SPI_MASTER_STAT_FILL);
	SPI_MASTER.spi.spi_data_out = v;
}
