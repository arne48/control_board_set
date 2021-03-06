#include <raspberry_pi_spi.h>
#include <bcm2835.h>
#include <cstdio>

RaspberryPi_SPI::RaspberryPi_SPI(RaspberryPi_GPIO *gpio) : Embedded_SPI(gpio)
{
  gpio_ = gpio;

  if (bcm2835_spi_begin() != 1) {
    printf("bcm2835_spi_begin failed.");
  }
  bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);
  bcm2835_spi_setDataMode(BCM2835_SPI_MODE1);
  bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_32);
  bcm2835_spi_chipSelect(BCM2835_SPI_CS_NONE);
  bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS_NONE, LOW);

};

RaspberryPi_SPI::~RaspberryPi_SPI()
{
  bcm2835_spi_end();
};

bool RaspberryPi_SPI::transferSPI(int cs, int data_len, char data[])
{
  gpio_->set_output(cs, Embedded_GPIO::gpio_state::OFF);
  bcm2835_spi_transfern(data, data_len);
  gpio_->set_output(cs, Embedded_GPIO::gpio_state::ON);
  return true;
}

bool RaspberryPi_SPI::transferSPI(int cs, int data_len, char data_tx[], char data_rx[])
{
  gpio_->set_output(cs, Embedded_GPIO::gpio_state::OFF);
  bcm2835_spi_transfernb(data_tx, data_rx, data_len);
  gpio_->set_output(cs, Embedded_GPIO::gpio_state::ON);
  return true;
}
