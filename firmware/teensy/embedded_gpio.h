#ifndef EMBEDDED_GPIO_H
#define EMBEDDED_GPIO_H

#include <stdint.h>

/**
 * Interface class for using the GPIO ports of an arbitrary platform
 * initialization needs to be done in a platform dependent fashion
 */
class Embedded_GPIO {
public:
  enum gpio_state { EMB_OFF = 0, EMB_ON = 1 };
  enum gpio_mode { EMB_INPUT = 0, EMB_OUTPUT = 1 };

  /**
   * Default Constructor
   */
  Embedded_GPIO() {};

  /**
   * Destructor
   */
  virtual ~Embedded_GPIO() {};

  virtual void init(int gpio_address) = 0;

  virtual void deinit(int gpio_address) = 0;

  virtual void set_mode(int gpio_address, gpio_mode mode) = 0;

  virtual void set_output(int gpio_address, gpio_state output_state) = 0;

  virtual gpio_state read_input(int gpio_address) = 0;
};

#endif //EMBEDDED_GPIO_H
