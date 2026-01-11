# WiFi-Based LED Dashboard Control using ESP8266

A **smart, real-time LED control system** using **ESP8266**, **HTML**, and **WiFi**.  
This project allows you to **toggle 3 LEDs individually or all together** using a **mobile browser**, with a **bright, professional web dashboard**.

---

## 🔹 Features

- Toggle **LED 1, LED 2, LED 3** individually  
- Toggle **ALL LEDs ON/OFF** with one button  
- **Mobile-friendly web interface** with bright, modern colors  
- **No additional apps required** — control via any browser  
- Simple, clean, and professional **dashboard UI**  

---

## 🔹 Hardware Required

- ESP8266 Board (NodeMCU / ESP-12)  
- 3 LEDs  
- 3 x 220Ω resistors  
- Jumper wires & breadboard  
- Mobile device connected to **same WiFi network**  

**LED Pin Mapping**

| LED  | ESP8266 Pin |
|------|------------|
| LED1 | D1         |
| LED2 | D2         |
| LED3 | D3         |

---

## 🔹 Software Required

- Arduino IDE  
- ESP8266 Board support installed in Arduino IDE  
- Web browser on mobile (Chrome, Firefox, Safari, etc.)  

---

## 🔹 Setup Instructions

1. Connect LEDs to ESP8266 pins D1, D2, D3 with 220Ω resistors.  
2. Open `wifi_led_control.ino` in Arduino IDE.  
3. Update your WiFi credentials in the code:
   ```cpp
   const char* ssid = "YourWiFiSSID";
   const char* password = "YourWiFiPassword";
````

4. Select **Board → NodeMCU 1.0 (ESP-12E)** and correct **COM port**.
5. Upload code to ESP8266.
6. Open **Serial Monitor** at **9600 baud**.
7. Note the IP address displayed (e.g., `192.168.31.xxx`).
8. Open the IP address in your mobile browser.
9. Tap the buttons to toggle LEDs individually or all together.

---

## 🔹 How It Works

* ESP8266 connects to WiFi and starts a **web server**.
* HTML page contains **toggle buttons** for each LED.
* Clicking a button sends a request to ESP8266, which **switches the LED ON/OFF**.
* Single **ALL LED** button toggles all LEDs at once.

---

## 🔹 Future Improvements

* Add **LED status indicators** on the web page (ON/OFF text)
* Add **button animations / ripple effect** for better UX
* Password-protected dashboard for security
* Expandable for more LEDs or sensors

---

## 🔹 Skills Demonstrated

* Embedded Systems (ESP8266)
* IoT / WiFi control
* Web UI Design (HTML + CSS)
* Hardware-Software Integration
* Mobile-friendly interface development

```
