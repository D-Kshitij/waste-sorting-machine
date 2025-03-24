#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Servo Motors
Servo servoMetal;
Servo servoPlastic;

// Sensors
#define INDUCTIVE_SENSOR 2   // Metal detection
#define CAPACITIVE_SENSOR 3  // Plastic detection
#define IR_SENSOR 5          // Shared IR sensor for both

// LCD Display (I2C, 16x2)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    // Initialize Serial Monitor
    Serial.begin(9600);
    
    // Initialize LCD
    lcd.init();
    lcd.backlight();
    lcd.print("Testing Sensors");
    delay(2000);
    lcd.clear();

    // Initialize Sensors
    pinMode(INDUCTIVE_SENSOR, INPUT);
    pinMode(CAPACITIVE_SENSOR, INPUT);
    pinMode(IR_SENSOR, INPUT);

    // Initialize Servo Motors
    servoMetal.attach(10);
    servoPlastic.attach(11);
    servoMetal.write(0); // Start position (Vertical)
    servoPlastic.write(0);
}

void loop() {
    bool isMetal = digitalRead(INDUCTIVE_SENSOR) == LOW; // Adjusted logic
    bool isPlastic = digitalRead(CAPACITIVE_SENSOR) == LOW; // Adjusted logic
    bool irTriggered = digitalRead(IR_SENSOR) == LOW; // IR returns 0 when object detected

    if (isMetal && !isPlastic) { // Ensure metal detection does not interfere with plastic detection
        lcd.clear();
        lcd.print("Metal Detected");
        Serial.println("Metal Detected");
        delay(500);
        
        Serial.println("Moving Metal Servo to 180 degrees (Horizontal)...");
        servoMetal.write(180);
        delay(500);
        
        Serial.println("Waiting for IR Trigger...");
        while (digitalRead(IR_SENSOR) == HIGH) {}

        Serial.println("IR Triggered, Delaying 0.5 sec...");
        delay(500);
        
        Serial.println("Moving Metal Servo Slowly to 0 degrees (Vertical)...");
        for (int pos = 180; pos >= 0; pos -= 5) {
            servoMetal.write(pos);
            delay(100);
        }
        Serial.println("Metal Flap Reset");
        lcd.clear();
        lcd.print("Ready");
    }
    
    if (isPlastic && !isMetal) { // Ensure plastic detection is independent of metal
        lcd.clear();
        lcd.print("Plastic Detected");
        Serial.println("Plastic Detected");
        delay(500);
        
        Serial.println("Moving Plastic Servo to 180 degrees (Horizontal)...");
        servoPlastic.write(180);
        delay(500);
        
        Serial.println("Waiting for IR Trigger...");
        while (digitalRead(IR_SENSOR) == HIGH) {}

        Serial.println("IR Triggered, Delaying 2 sec...");
        delay(2000);
        
        Serial.println("Moving Plastic Servo Slowly to 0 degrees (Vertical)...");
        for (int pos = 180; pos >= 0; pos -= 5) {
            servoPlastic.write(pos);
            delay(100);
        }
        Serial.println("Plastic Flap Reset");
        lcd.clear();
        lcd.print("Ready");
    }
}
