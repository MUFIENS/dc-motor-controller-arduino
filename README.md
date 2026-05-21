# Arduino DC Motor Speed Controller 🚗

Repository ini berisi kode dan skema simulasi untuk mengontrol kecepatan Motor DC menggunakan Arduino Uno dan IC L293D (H-Bridge).

## 🛠️ Komponen yang Digunakan
* Arduino Uno R3
* IC H-Bridge L293D
* Motor DC
* Potensiometer 10k ohm
* Baterai 9V
* Breadboard & Jumper Wires

## 📷 Skema Sirkuit (Tinkercad)
<img width="1180" height="638" alt="image" src="https://github.com/user-attachments/assets/4e44fc88-90b9-40de-afc9-4685bccaefcd" />
<img width="1911" height="462" alt="image" src="https://github.com/user-attachments/assets/87937fbc-cb82-49e9-8776-4a82b9276819" />
<img width="874" height="707" alt="image" src="https://github.com/user-attachments/assets/baa13baf-9b13-4fb8-a68d-5562afaa2288" />




## 🚀 Cara Kerja
1. Potensiometer membaca input analog (0-1023).
2. Arduino mengonversi nilai tersebut menjadi sinyal PWM (0-255).
3. IC L293D menerima sinyal PWM untuk mengatur kecepatan putaran Motor DC secara real-time.
