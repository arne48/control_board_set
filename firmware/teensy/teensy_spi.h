#ifndef TEENSY_SPI_H
#define TEENSY_SPI_H

#include <SPI.h>
#include "embedded_spi.h"
#include "teensy_gpio.h"

/**
 * Implementation of the embedded SPI interface
 */
class Teensy_SPI : public Embedded_SPI {
public:
  Teensy_SPI(Teensy_GPIO *gpio);

  /**
   * Destructor
   */
  ~Teensy_SPI();

  /**
   * Call to transfer an array of bytes to a given chip-select "id"
   * The mapping of those "ids" starting by 0 has to be performed by
   * the implementing class.
   * @param cs chip-select
   * @param data_len length of data array
   * @param data array containing the data to transfer
   * @return true if transfer was executed successfully
   */
  virtual bool transferSPI(int cs, int data_len, char data[]);

  /**
   * Call to transfer an array of bytes to a given native chip-select
   * using two buffers for transfer and receiving
   * @param cs chip-select
   * @param data_len length of data array
   * @param data_tx array containing the data to transfer
   * @param data_rx array containing the data to receive
   * @return true if transfer was executed successfully
   */
  virtual bool transferSPI(int cs, int data_len, char data_tx[], char data_rx[]);

private:
  Teensy_GPIO *_gpio;
  SPISettings *_spi_settings;

  void micro_wait();

};


#endif //TEENSY_SPI_H
