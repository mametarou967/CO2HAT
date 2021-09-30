#include <M5StickC.h>
#include <MHZ19.h>                                        
#include <SoftwareSerial.h> 

#define RX_PIN 26
#define TX_PIN 0
#define BAUDRATE 9600
#define DELAY 2000

MHZ19 myMHZ19;
HardwareSerial mySerial(1);

void setup(){
  M5.begin();
  M5.Lcd.setRotation(1);
  M5.Lcd.setTextSize(3);
  
  mySerial.begin(BAUDRATE, SERIAL_8N1, RX_PIN, TX_PIN);
  myMHZ19.begin(mySerial);
  myMHZ19.autoCalibration();
}

// the loop routine runs over and over again forever
void loop() {
    int CO2 = myMHZ19.getCO2();
    M5.Lcd.fillScreen(TFT_BLACK);
    M5.Lcd.setCursor(25, 30);
    M5.Lcd.printf("%4dppm",CO2);
    delay(DELAY);
}
