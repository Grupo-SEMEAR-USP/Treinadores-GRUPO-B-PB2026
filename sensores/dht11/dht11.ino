#include <DHT11.h>
#define sensor 4

DHT11 dht11(sensor);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  int temp=0;
  int hum=0;

  int valor = dht11.readTemperatureHumidity(temp, hum);
  if(valor==0){
    Serial.print("Temperatura: ");
    Serial.print(temp);
    Serial.println("ºC");

    Serial.print("Umidade: ");
    Serial.print(hum);
    Serial.println("%");
  }
  else{
    Serial.println(DHT11::getErrorString(valor));
  }
}
