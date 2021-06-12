#ifndef __SPI_MASTER_H
#define __SPI_MASTER_H
#ifdef __cplusplus
extern "C" {
#endif
#include <peripherals/spi_common.h>
// CONTROL
#define SPI_MASTER_CTRL_EN               SPI_CTRL_EN
#define SPI_MASTER_CTRL_INT_EN			SPI_CTRL_INT_EN
#define SPI_MASTER_CTRL_CPOL			SPI_CTRL_CPOL
#define SPI_MASTER_CTRL_CPHA			SPI_CTRL_CPHA
#define SPI_MASTER_CTRL_SLAVE			0x000F0 // 00 0000 0000 1111
0000
#define SPI_MASTER_CTRL_BITCNT			0x01F00 // 00 0001 1111 0000
0000
#define SPI_MASTER_CTRL_DIV				0x0E000 // 00 1110 0000 0000
0000
//STATUS
//#define SPI_MASTER_STAT_FILL			0x00007
#define SPI_MASTER_STAT_FILL			0x00004
//#define SPI_MASTER_STAT_EMPTY			0x00000

#define SPI_MASTER_STAT_INT				0x00008
#define SPI_MASTER_STAT_SS_ON			0x00010
#define SPI_MASTER_STAT_SS_SET			0x00020

typedef struct {
spi_t spi;
} spi_master_regs_t;
#ifdef __cplusplus
}
#endif
#endif
