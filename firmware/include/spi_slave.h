#ifndef __SPI_SLAVE_H
#define __SPI_SLAVE_H
#ifdef __cplusplus
extern "C" {
#endif
#include <peripherals/spi_common.h>
#define SPI_SLAVE_CTRL_EN	SPI_CTRL_EN
#define	SPI_SLAVE_CTRL_INT_EN	SPI_CTRL_INT_EN
#define	SPI_SLAVE_CTRL_CPOL	SPI_CTRL_CPOL
#define	SPI_SLAVE_CTRL_CPHA	SPI_CTRL_CPHA
#define	SPI_SLAVE_CTRL_DONE	0x00100 // 00 0000 0001 0000
0000
#define SPI_SLAVE_CTRL_INT	0x00200 // 00 0000 0010 0000
0000
#define SPI_SLAVE_CTRL_BITCNT  0x01C00 // 00 0001 1100 0000
0000

typedef struct {
spi_t spi;
} spi_slave_regs_t;
#ifdef __cplusplus
}
#endif
#endif
