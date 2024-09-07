# Semi-Virtual Bowling Game

## Team Members
- Berwyn Berwyn
- Sazzad Islam
- Jermaine Zhao

## Project Description

The Semi-Virtual Bowling Game is an innovative project that combines physical interaction with virtual gameplay, creating an immersive bowling experience. Our project utilizes a custom graphics library implemented in C to render and animate falling bowling pins on a monitor. The unique aspect of our game is the integration of real-world ball throws with virtual pin reactions.

### Key Features
- **Custom Graphics Engine**: Specialized graphics library in C for smooth and realistic animations of falling bowling pins.
- **Real-time Physics Simulation**: Dynamic calculation of virtual pin behavior based on the physical ball's impact point.
- **Sensor Integration**: Use of DWEII VL53L1X sensor to accurately detect where the physical bowling ball hits the monitor/screen.
- **Interactive Gameplay**: Players throw a real bowling ball, and the virtual pins react accordingly.
- **Real-time Feedback**: Immediate processing of sensor data for accurate representation of the ball's impact on virtual pins.

## Technical Stack
- **Programming Language**: C
- **Graphics**: Custom-built C graphics library
- **Hardware**: DWEII VL53L1X sensor for impact detection

## How It Works
1. The player rolls a physical bowling ball towards the screen/monitor.
2. The DWEII VL53L1X sensor detects the exact point of impact of the ball on the screen.
3. This data is fed into our C program, which calculates how the virtual pins should fall based on the impact point.
4. Our custom graphics library then animates the falling pins on the screen, simulating a realistic bowling effect.
