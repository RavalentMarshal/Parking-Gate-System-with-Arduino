#include <Servo.h> // Memasukkan pustaka Servo untuk mengontrol servo motor.

Servo myservo; // Membuat objek servo bernama 'myservo'.

int pos = 0; // Variabel untuk menyimpan posisi sudut servo motor.
int cm = 0; // Variabel untuk menyimpan jarak yang diukur oleh sensor ultrasonik.

long readUltrasonicDistance(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT); // Mengatur pin trigger sebagai output.
  digitalWrite(triggerPin, LOW); // Menyetel pin trigger ke LOW untuk memastikan tidak ada sinyal.
  delayMicroseconds(2); // Menunggu selama 2 mikrodetik.
  digitalWrite(triggerPin, HIGH); // Menyetel pin trigger ke HIGH untuk mengirim sinyal.
  delayMicroseconds(10); // Menunggu selama 10 mikrodetik.
  digitalWrite(triggerPin, LOW); // Menyetel pin trigger kembali ke LOW setelah sinyal dikirim.
  pinMode(echoPin, INPUT); // Mengatur pin echo sebagai input untuk menerima sinyal.
  return pulseIn(echoPin, HIGH); // Mengukur durasi pulsa HIGH pada pin echo.
}

void setup() {
  digitalWrite(12, LOW); // Menyetel pin 12 ke LOW (tidak digunakan dalam kode ini).
  myservo.attach(9); // Menghubungkan servo motor ke pin 9.
  Serial.begin(9600); // Memulai komunikasi serial dengan baud rate 9600.
}

void loop() {
  // Menghitung jarak dalam cm menggunakan sensor ultrasonik.
  cm = 0.01723 * readUltrasonicDistance(6, 7); 

  // Mengecek apakah jarak yang terdeteksi kurang dari 30 cm.
  if (cm < 30) {
    Serial.print(cm); // Menampilkan jarak pada serial monitor.
    Serial.println("cm"); // Menambahkan "cm" setelah nilai jarak.

    // Menggerakkan servo motor dari 0 hingga 120 derajat.
    for (pos = 0; pos <= 120; pos += 1) {
      myservo.write(pos); // Menggerakkan servo ke posisi tertentu.
      delay(15); // Menunggu 15 milidetik sebelum melanjutkan ke posisi berikutnya.
    }
    delay(500); // Menunggu 500 milidetik setelah gerakan selesai.

    // Menggerakkan servo motor dari 120 kembali ke 0 derajat.
    for (pos = 120; pos >= 0; pos -= 1) {
      myservo.write(pos); // Menggerakkan servo ke posisi tertentu.
      delay(15); // Menunggu 15 milidetik sebelum melanjutkan ke posisi berikutnya.
    }
    delay(5000); // Menunggu 5 detik sebelum melakukan loop kembali.
  }
}
