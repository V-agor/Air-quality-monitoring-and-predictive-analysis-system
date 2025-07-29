#include "DHT.h" //This line includes the DHT sensor library, which contains all the functions you need to communicate with the DHT11 sensor.

#define DHTPIN 2       // Digital pin connected to the DHT sensor,This line tells the Arduino which pin the DHT11 data wire is connected to.
#define DHTTYPE DHT11  // This specifies the sensor type — in this case, DHT11. (Other types include DHT22 or DHT21.)

DHT dht(DHTPIN, DHTTYPE);//his line creates a dht object that knows:Where to read the sensor (DHTPIN),What kind of sensor it is (DHT11),Now you can use:dht.begin() to initialize the sensor,dht.readTemperature() to read the temperature,dht.readHumidity() to read the humidity

void setup() {//This function runs once when the Arduino powers up or resets.
  Serial.begin(9600);
  dht.begin();//initialises DHT sensor
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();  // Celsius

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");//if temperature and humidity are not numbers(nan)
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" °C");

  delay(2000);  // Wait 2 seconds
}
