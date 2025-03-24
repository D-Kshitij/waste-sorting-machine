

### **Automatic Waste Sorting Machine**
#### **Project Overview**
This project is an **Automatic Waste Sorting Machine** that detects and sorts metallic and plastic waste using an **Inductive Proximity Sensor**, a **Capacitive Sensor**, and an **IR Sensor**. The system is controlled by an **Arduino** and utilizes servo motors for sorting.

#### **How It Works**
1. **Detection Phase:**
   - **Inductive Proximity Sensor** detects metal objects.
   - **Capacitive Sensor** detects plastic objects.
   - **IR Sensor** detects the presence of objects before sorting.

2. **Sorting Mechanism:**
   - If **metal** is detected, the **metal flap** moves **horizontally** and then pushes the object away after **0.5 seconds**.
   - If **plastic** is detected, the **plastic flap** moves **horizontally** and then pushes the object away after **2 seconds**.
   - Both flaps return to their **vertical position** after sorting.

3. **LCD Display:**
   - Displays **"Metal Detected"**, **"Plastic Detected"**, or **"Ready"**.

#### **Hardware Components**
- **Arduino Uno** (or compatible board)
- **Inductive Proximity Sensor** (for metal detection)
- **Capacitive Proximity Sensor** (for plastic detection)
- **IR Sensor** (for detecting object presence)
- **Servo Motors** (for sorting mechanism)
- **16x2 LCD (I2C)** (for displaying detection status)
- **Power Supply**
- **Connecting Wires**

#### **Installation & Setup**
1. **Connect Components:** Refer to the wiring diagram.
2. **Upload the Code:**
   - Open `main.ino` in the Arduino IDE.
   - Install required libraries (`Servo.h`, `Wire.h`, `LiquidCrystal_I2C.h`).
   - Upload the code to the Arduino board.
3. **Test the System:**
   - Place a **metal** or **plastic** object on the conveyor.
   - Observe detection on the **LCD**.
   - Watch the servo motor move the flap accordingly.

#### **Code Files**
- `main.ino` → Arduino code for detection and sorting.
- `wiring_diagram.png` → Circuit diagram.
- `libraries/` → Required external libraries (if any).

#### **Future Improvements**
- Implement **AI-based image classification** for more accurate sorting.
- Add a **wet waste** detection mechanism.
- Optimize **servo movement** for better efficiency.

