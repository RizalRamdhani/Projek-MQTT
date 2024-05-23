#include <Arduino.h>
#include <WiFi.h>
#include <Wire.h>
#include <PubSubClient.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN 4      // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22 // DHT 11
DHT dht(DHTPIN, DHT22);
WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);
const char *ssid = "MAKERINDO2";
const char *password = "makerindo2019";

char *mqttServer = "broker.hivemq.com";
//char *mqttServer = "test.mosquitto.org";
int mqttPort = 1883;
int period = 6000;
unsigned long time_now = 0;
void setupMQTT()
{
  mqttClient.setServer(mqttServer, mqttPort);
  mqttClient.setCallback(callback);
}

void reconnect()
{
  Serial.println("Connecting to MQTT Broker...");
  while (!mqttClient.connected())
  {
    Serial.println("Reconnecting to MQTT Broker..");
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);

    if (mqttClient.connect(clientId.c_str()))
    {
      Serial.println("Connected.");
      // subscribe to topic
      mqttClient.subscribe("esp32/message");
    }
  }
}

void setup()
{
  Serial.begin(115200);
  pinMode(15, OUTPUT);
  dht.begin();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Connected to Wi-Fi");

  setupMQTT();
}

void loop()
{
  if (!mqttClient.connected())
    reconnect();
  mqttClient.loop();

  if (millis() >= time_now + period)
  {
    time_now += period;
    float temperature = dht.readTemperature();
    char tempString[8];
    dtostrf(temperature, 1, 2, tempString);
    Serial.print("Temperature: ");
    Serial.println(tempString);
    mqttClient.publish("esp32/temperature", tempString);

    float humidity = dht.readHumidity();
    char humString[8];
    dtostrf(humidity, 1, 2, humString);
    Serial.print("Humidity: ");
    Serial.println(humString);
    mqttClient.publish("esp32/humidity", humString);
  }
}
void callback(char *topic, byte *message, unsigned int length)
{
  Serial.print("Message arrived ");
  Serial.print("Message:");
  Serial.print("] ");
  String data = "";
  for (int i = 0; i < length; i++)
  {
    Serial.print((char)message[i]);
    data += (char)message[i];
  }
  // Switch on the LED if an 1 was received as first character
  if (data.startsWith("ON"))
  {
    digitalWrite(15, HIGH); // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is active low on the ESP-01)
  }
  else if (data.startsWith("OFF"))
  {
    digitalWrite(15, LOW); // Turn the LED off by making the voltage HIGH
  }

}
