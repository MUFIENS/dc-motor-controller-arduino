  // ==========================================
// PROGRAM KONTROL KECEPATAN MOTOR DC
// ==========================================

// 1. Mendefinisikan pin sesuai dengan rakitan Tinkercad
const int potPin = A0;    // Pin input analog untuk Potensiometer
const int enPin  = 5;     // Pin PWM untuk mengontrol kecepatan (ke Pin 1 / EN1 L293D)
const int in1Pin = 8;     // Pin kontrol arah 1 (ke Pin 2 / IN1 L293D)
const int in2Pin = 9;     // Pin kontrol arah 2 (ke Pin 7 / IN2 L293D)

void setup() {
  // Mengaktifkan Serial Monitor untuk debugging (opsional tapi sangat berguna)
  Serial.begin(9600);

  // Mengatur pin yang terhubung ke IC L293D sebagai Output
  pinMode(enPin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);

  // Menentukan arah putaran motor awal (misal: Searah jarum jam)
  // Konsepnya: Jika IN1 diberi HIGH dan IN2 diberi LOW, motor berputar ke satu arah
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, HIGH);
}

void loop() {
  // Langkah 1: Membaca tegangan dari potensiometer 
  // Hasilnya berupa angka dari 0 (paling kiri) hingga 1023 (paling kanan)
  int potValue = analogRead(potPin);

  // Langkah 2: Mengonversi (mapping) nilai sensor ke skala PWM
  // Nilai analog (0-1023) diubah menjadi nilai PWM (0-255) yang bisa dibaca pin Enable
  int motorSpeed = map(potValue, 0, 1023, 0, 255);

  // Langkah 3: Mengirimkan perintah kecepatan ke IC H-Bridge
  analogWrite(enPin, motorSpeed);

  // Langkah 4: Menampilkan data ke Serial Monitor agar kita tahu apa yang terjadi
  Serial.print("Data Potensiometer: ");
  Serial.print(potValue);
  Serial.print("  |  Kecepatan PWM: ");
  Serial.println(motorSpeed);

  // Jeda sangat singkat agar sistem stabil
  delay(50);
}