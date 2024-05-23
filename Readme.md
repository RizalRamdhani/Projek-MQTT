# Praktik IOT KE MQTT 
sensor DHT22 digunakan untuk mengukur suhu dan kelembaban udara. Kemudian, nilai-nilai yang terukur tersebut diambil oleh mikrokontroler, seperti esp32 dan dikirim melalui koneksi Internet ke broker MQTT, dalam hal ini HiveMQ Ke MQTT Box.
#Gambar Sensor DHT22!
th](https://github.com/RizalRamdhani/Projek-MQTT/assets/106525434/c0f0e4ea-b2ff-44d0-b27f-ff5a14fe25aa)
# Alat dan bahan 
1.Sensor DHT22
2.esp32 sebagai mikrokontroler
3.Breadboard 
4.Kabel jumper 
5.Broker mqtt misalnya hivemqtt
6.MQTT BOX sebagai cloud sementara

# Cara kerja Alat
Alat DHT22 berfungsi sebagai sensor untuk mengukur suhu dan kelembaban, yang kemudian terhubung ke mikrokontroler atau papan pengembangan seperti Arduino atau Raspberry Pi. Sensor ini mengumpulkan data yang diolah oleh mikrokontroler menggunakan library yang sesuai, seperti "DHT sensor library" untuk pembacaan data. Data suhu dan kelembaban yang telah diperoleh kemudian dikirim ke broker MQTT dengan menggunakan library MQTT seperti "PubSubClient". Proses ini melibatkan koneksi ke jaringan WiFi, pengaturan koneksi ke broker MQTT, dan publikasi data ke topik tertentu yang ditentukan pada broker. Setiap kali data dikumpulkan, mikrokontroler akan mempublikasikannya ke broker MQTT, memungkinkan perangkat atau aplikasi lain untuk berlangganan dan menerima data tersebut secara real-time.
# Gambar hasil code yang sudah tersambung dengan mqtt box
<img width="949" alt="Screenshot 2024-02-20 164901" src="https://github.com/RizalRamdhani/Projek-MQTT/assets/106525434/86291d0b-26cb-44ac-9997-0a35f3564605">

# Gambar hasil broker MQTT BOX
<img width="960" alt="Screenshot 2024-02-20 164757" src="https://github.com/RizalRamdhani/Projek-MQTT/assets/106525434/c8614bf3-c28c-4043-b219-b133c823194f">






