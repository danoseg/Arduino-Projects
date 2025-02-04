#include <DHT.h>
#include <LiquidCrystal.h>


#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const int rs = 12, en = 11, d4 = 5, d5 = 6, d6 = 8, d7 = 9;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int buttonState = 0;


void  setup()
{
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);
  lcd.print("Te amo osita! :)");
}

void loop()
{
    delay(2000);
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  int h_variance = h + 5;

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(h_variance);
}
