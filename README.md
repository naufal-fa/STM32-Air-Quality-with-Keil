# Air Quality Monitoring And Controlling System Using STM32 and Keil

**Deskripsi Singkat:**
Project Air Quality Monitoring and Controlling System Using STM32 and Keil bertujuan untuk memantau kualitas udara secara real-time menggunakan mikrokontroler STM32. Sistem ini mengukur parameter seperti CO2, CO, dan PM2.5, serta suhu dan kelembapan, dan mengontrol perangkat seperti kipas jika kualitas udara memburuk. Semua pengolahan data dilakukan dengan Keil IDE, memberikan solusi otomatis untuk menjaga kualitas udara yang sehat.

## Deskripsi Project

Project Air Quality Monitoring and Controlling System Using STM32 and Keil bertujuan untuk mengembangkan sistem yang dapat memantau dan mengendalikan kualitas udara di lingkungan sekitar secara otomatis. Dengan meningkatnya polusi udara di banyak wilayah, kualitas udara yang buruk dapat menyebabkan berbagai masalah kesehatan, seperti gangguan pernapasan, alergi, dan penyakit jantung. Oleh karena itu, penting untuk memiliki sistem yang mampu memantau kualitas udara secara real-time dan memberikan respons otomatis jika parameter kualitas udara berada di luar batas aman.
### Tujuan yang Ingin Dicapai:

1. **Pemantauan Kualitas Udara Real-Time:** Sistem ini bertujuan untuk memantau parameter penting kualitas udara, seperti konsentrasi gas berbahaya (CO2, CO), partikel halus (PM2.5), serta suhu dan kelembapan.
   
2. **Pengendalian Otomatis:** Jika kualitas udara terdeteksi buruk, sistem ini akan mengaktifkan perangkat pengendali, seperti kipas atau sistem ventilasi, untuk memperbaiki kondisi udara.

3. **Meningkatkan Kesehatan Penghuni:** Dengan sistem ini, diharapkan kualitas udara dapat dijaga di tingkat yang sehat, mengurangi risiko masalah kesehatan akibat polusi udara.

### Teknologi yang Digunakan:

- **STM32:** Mikrokontroler STM32 digunakan sebagai otak sistem yang bertanggung jawab untuk memproses data dari sensor dan mengontrol perangkat pengendalian. STM32 dipilih karena kemampuannya yang tinggi, efisiensi energi, dan kemampuan untuk menangani berbagai tugas secara simultan.
  
- **Keil IDE:** Keil IDE digunakan untuk pengembangan perangkat lunak yang menghubungkan mikrokontroler STM32 dengan sensor dan perangkat lainnya. Keil menyediakan lingkungan yang efisien untuk menulis, mengompilasi, dan memprogram kode mikrokontroler.

- **Sensor Kualitas Udara:** Sensor seperti MQ-135 digunakan untuk mendeteksi polusi udara. Sensor-sensor ini memberikan data yang relevan untuk mengevaluasi kualitas udara di lingkungan sekitar.

### Masalah yang Diselesaikan:

1. **Polusi Udara dan Dampaknya terhadap Kesehatan:** Sistem ini membantu memantau tingkat polusi udara yang sering kali tidak terlihat, tetapi dapat berdampak signifikan pada kesehatan, terutama di daerah perkotaan atau industri.

2. **Keterbatasan Sistem Pemantauan Manual:** Banyak sistem pemantauan kualitas udara yang tidak dapat memberikan respons otomatis terhadap perubahan kualitas udara. Project ini mengatasi masalah tersebut dengan menawarkan sistem yang dapat mengontrol perangkat pengendalian seperti kipas atau sistem ventilasi secara otomatis.

3. **Keterbatasan dalam Akses Informasi Kualitas Udara:** Banyak orang tidak memiliki alat atau sistem yang dapat dengan mudah memantau kualitas udara di rumah atau tempat kerja. Sistem ini menyediakan solusi yang mudah diakses dan dapat dipasang di berbagai lokasi.

### Fitur Utama:

1. **Pemantauan Real-Time:** Menggunakan sensor kualitas udara untuk memantau konsentrasi gas berbahaya (CO2, CO), partikel halus (PM2.5), suhu, dan kelembapan.

2. **Kontrol Perangkat Pengendalian:** Jika kualitas udara memburuk, sistem ini dapat mengaktifkan perangkat seperti kipas atau ventilasi untuk meningkatkan kualitas udara.

3. **Data Logging dan Tampilan:** Data yang diambil dari sensor disimpan dan ditampilkan pada antarmuka pengguna, memberikan informasi yang jelas tentang kondisi udara secara terus-menerus.

4. **Notifikasi Peringatan:** Sistem dapat memberikan peringatan jika kualitas udara melebihi batas yang ditetapkan, memungkinkan pengguna untuk mengambil tindakan manual jika diperlukan.

5. **Optimasi Penggunaan Energi:** Dengan menggunakan STM32 yang efisien energi, sistem ini dapat beroperasi dalam jangka waktu yang lama dengan konsumsi daya yang minimal.

## Cara Instalasi dan Menjalankan Project

### Prasyarat
- Mikrokontroler STM32 Nucleo-F446RE
- Keil IDE
- STM32CubeMx
- Sensor Kualitas Udara (MQ-135)
- Sensor Temperature dan Kelembapan Udara (DHT22)
- Kabel dan perangkat keras lainnya untuk interkoneksi
### Langkah Instalasi

1. **Clone Repository**
   ```bash
   git clone https://github.com/naufal-fa/STM32-Air-Quality-with-Keil.git
   cd nama-folder-project
lcd_display_image("src/img/[1].png");
