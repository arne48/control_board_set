#ifndef EMBEDDED_SPI_H
#define EMBEDDED_SPI_H

#include <embedded_gpio.h>

/**
 * Interface class for accessing the SPI bus of an arbitrary platform
 */
class Embedded_SPI {
public:
  /**
   * Constructor providing EmbeddedGPIO for setting CS in software
   */
  Embedded_SPI(Embedded_GPIO *gpio) {};

  /**
   * Destructor
   */
  virtual ~Embedded_SPI() {};

  /**
   * Call to transfer an array of bytes to a given native chip-select
   * @param cs chip-select
   * @param data_len length of data array
   * @param data array containing the data to transfer
   * @return true if transfer was executed successfully
   */
  virtual bool transferSPI(int cs, int data_len, char data[]) = 0;

  /**
   * Call to transfer an array of bytes to a given native chip-select
   * using two buffers for transfer and receiving
   * @param cs chip-select
   * @param data_len length of data array
   * @param data_tx array containing the data to transfer
   * @param data_rx array containing the data to receive
   * @return true if transfer was executed successfully
   */
  virtual bool transferSPI(int cs, int data_len, char data_tx[], char data_rx[]) = 0;

};


#endif //EMBEDDED_SPI_H
