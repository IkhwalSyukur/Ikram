#pragma once

#include <WiFiManager.h>

struct MyWifi {
  MyWifi() {}

  void begin () {
    WiFiManager wm;
    bool res;
    res = wm.autoConnect("AutoConnectAP", "password");
    if (!res) {
      Serial.println("Failed to connect");
      // ESP.restart();
    }
    else {
      //if you get here you have connected to the WiFi
      Serial.println("connected...yeey :)");
    }
  }
};
