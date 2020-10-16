#include <OneWire.h>
#include <DallasTemperature.h>

// La connexion pour recevoir les données se fait sur la pin 4.
#define ONE_WIRE_BUS 4
OneWire oneWire(ONE_WIRE_BUS);

// On passe la référence du OneWire à notre senseur de température.
DallasTemperature sensors(&oneWire);

void setup(void)
{
  // Communication en série pour tester l'affichage de la température.
  Serial.begin(9600);
  sensors.begin();
}

void loop(void){ 
  // On appelle sensors.requestTemperatures() pour aller chercher la température et l'afficher en celsius et en fahrenheit.
  sensors.requestTemperatures(); 
  Serial.print("Celsius temperature: ");
  Serial.print(sensors.getTempCByIndex(0)); 
  Serial.print(" - Fahrenheit temperature: ");
  Serial.println(sensors.getTempFByIndex(0));
  delay(1000);
}