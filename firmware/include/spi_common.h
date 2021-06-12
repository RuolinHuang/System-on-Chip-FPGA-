#ifndef __SPI_COMMON_H
#define __SPI_COMMON_H
#ifdef __cplusplus
extern "C" {
#endif
// CONTROL
#define SPI_CTRL_EN			0x00001 // 00 0000 0000 0000 0001
#define SPI_CTRL_INT_EN		0x00002 // 00 0000 0000 0000 0010
#define SPI_CTRL_CPOL		0x00004 // 00 0000 0000 0000 0100
#define SPI_CTRL_CPHA		0x00008 // 00 0000 0000 0000 1000

typedef volatile struct {
volatile unsigned int spi_control;
volatile unsigned int spi_data_out;
volatile unsigned int spi_data_in;
volatile unsigned int spi_status;
} spi_t;
#ifdef __cplusplus
}
#endif
#endif
