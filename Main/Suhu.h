#pragma once

#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
Adafruit_MLX90614 mlx2 = Adafruit_MLX90614();

struct Suhu {
  Suhu () {}

  void begin () {
    if (!mlx.begin()) {
      Serial.println("Error connecting to MLX sensor. Check wiring.");
      while (1);
    };

    if (!mlx2.begin(0x5B)) {
      Serial.println("Error connecting to MLX sensor. Check wiring.");
      while (1);
    };
  }

  int readT1() {
    return mlx.readObjectTempC();
  }
  int readT2() {
    return mlx2.readObjectTempC();
  }
};
