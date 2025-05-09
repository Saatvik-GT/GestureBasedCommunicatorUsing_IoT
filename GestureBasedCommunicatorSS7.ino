#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <MPU6050.h>

MPU6050 mpu;
LiquidCrystal_I2C lcd(0x27, 16, 2);

int16_t ax, ay, az, gx, gy, gz;

void setup() {
  Wire.begin();
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Initializing...");
  delay(1000);

  mpu.initialize();
  if (!mpu.testConnection()) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("MPU NOT Found");
    while (1); // Halt
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("MPU Connected");
  delay(1000);
  lcd.clear();
}

void loop() {
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  String message = "";

  // Main gesture mappings
  if (ax > 12000) {
    message = "hello"; // Forward
  } else if (ax < -12000) {
    message = "bye"; // Backward
  } else if (ay < -12000) {
    message = "how are you?"; // Left
  } else if (ay > 12000) {
    message = "have a great day!"; // Right
  }

  // Optional gestures (uncomment if needed):

  // if (az > 16000) {
  //   message = "yes"; // Device facing upward
  // }

  // if (az < 1000) {
  //   message = "no"; // Device facing downward
  // }

  // if (gx > 15000) {
  //   message = "stop"; // Quick roll right (rotation)
  // }

  // if (gy > 15000) {
  //   message = "wait"; // Quick pitch up
  // }

  // if (gz > 15000) {
  //   message = "ok"; // Quick yaw right
  // }

  // if (ax > 8000 && ay > 8000) {
  //   message = "thank you"; // Diagonal forward-right
  // }

  if (message != "") {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(message);
    delay(1200); // Prevent spamming
  }

  delay(100);
}
