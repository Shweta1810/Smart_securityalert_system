Smart Safety Monitoring System

The Smart Safety Monitoring System is an embedded systems project designed to enhance safety by continuously observing environmental and security conditions. It is built using an Arduino microcontroller and integrates multiple sensors to detect potential risks in real time.

The system uses a DHT11 sensor to measure temperature and humidity, an MQ-135 sensor to detect smoke and harmful gases, and a PIR sensor to identify motion. These sensors work together to provide a comprehensive monitoring solution. The collected data is processed by the Arduino and displayed on an I2C-based LCD, allowing the user to easily view current environmental conditions.

To ensure accurate gas detection, the system performs an initial calibration of the gas sensor, establishing a baseline value for normal air quality. Any significant deviation from this baseline is treated as a potential hazard. Similarly, temperature thresholds are used to identify high temperature conditions, and motion detection helps in identifying unauthorized or unexpected movement.

When any abnormal condition such as smoke detection, high temperature, or motion is detected, the system immediately activates a buzzer to alert the user. This real-time alert mechanism makes the system effective for preventive safety.

Overall, this project demonstrates the integration of multiple sensors with a microcontroller to create a reliable, cost-effective, and efficient safety monitoring solution suitable for homes, laboratories, and small-scale environments.
