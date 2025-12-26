# 🛒 Mall Indoor Navigation System (ESP32-S3)

> A high-fidelity UWB/BLE simulation monitoring 5 mall zones in real-time.

![Wokwi Simulation Animation](https://via.placeholder.com/600x400.png?text=Add+Your+Wokwi+GIF+Here)

## 🚀 Features
* **Dynamic Visualization**: Real-time distance mapping with color-coded bars.
* **UWB/BLE Logic**: Simulates wireless node signals using 12-bit ADC precision.
* **ESP32-S3 Powered**: Optimized for dual-core processing and SPI communication.

## 🛠️ Technical Details
| Component | Pin Configuration |
| :--- | :--- |
| **TFT SCK** | GPIO 14 |
| **TFT MOSI** | GPIO 13 |
| **Sensors (1-5)** | GPIO 1, 2, 3, 4, 5 |

## 📂 Project Structure
- `mall_nav.ino`: Core logic for signal processing and display.
- `diagram.json`: Full wiring blueprint for Wokwi.
