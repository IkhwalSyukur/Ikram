#include "MyWifi.h"
#include "Suhu.h"

MyWifi mw;
Suhu Fl;

void setup() {
  // put your setup code here, to run once:
mw.begin();
Fl.begin();

xTaskCreate(MyWifi_task, "wifi task", 2048, NULL, 1, NULL);
xTaskCreate(Suhu_task, "Suhu task", 2048, NULL, 1, NULL);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(T1);
  Serial.println(T2);
}

void MyWifi_task(void *parameter){
  for (;;) {
    mw.begin();
  }
}

void Suhu_task (void *parameter){
  for (;;) {
    T1 = F1.readT1();
    T2 = F2.readT2();
  }
}
