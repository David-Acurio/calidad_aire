#include<DHT.h>
#include<SPI.h>
#include<Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1 // Pin de reset (utiliza -1 si no está conectado)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//sensores
const int a=34;//pin mq135
const int b=35;// pin mq9
const int c=19; // pin de dht11
DHT sensorDHT(c,DHT11);
// VARABLES DEL SENSOR
int mq135;
int mq9;
void setup() {
  Serial.begin(115200);
  delay(10);
  Serial.println("Inicio del Programa");
  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C)){
    Serial.println("No se pudo iniciar la pantalla Oled");
    while(true);
  }
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(3); // Tamaño inicial del texto
    display.display();
  delay(500);
}

void loop() {
  // leer las valores del sensor
  mq135=analogRead(a);
   mq9=analogRead(b);
   int temp=sensorDHT.readTemperature();
   int hum=sensorDHT.readHumidity();
   // calculo del mq-135 en PPM ------------
   //VARIABLES
   float volt_mq135;
   float rs_mq135;
   float ratio_mq135;// relacio rs/ro
   float ro_mq135=57;// la resistencia interna mq135 calculada en el aire limpio 
   
   volt_mq135=(5.0*mq135)/4094;
   rs_mq135=20*(5.0/volt_mq135-1);
   ratio_mq135=rs_mq135/ro_mq135;
   float m_mq135=-0.3679;
   float b_mq135=0.815;
   double ppm_log_mq135=(log(ratio_mq135)-b_mq135)/m_mq135;
   float ppm_co2=pow(10,ppm_log_mq135);
   // MQ-09------------------------------
   float volt_mq9;
   float rs_mq9;
   float ratio_mq9;// relacio rs/ro
   float ro_mq9=19;// la resistencia interna mq09 calculada en el aire limpio 

 volt_mq9=(5.0*mq9)/4094;
   rs_mq9=20*(5.0/volt_mq9-1);
   ratio_mq9=rs_mq9/ro_mq9;
   float m_mq9=-0.4101;
   float b_mq9=1.075;
   double ppm_log_mq9=(log(ratio_mq9)-b_mq135)/m_mq9;
   float ppm_co=pow(10,ppm_log_mq9);
   
   Serial.print("Co2 : ");
   Serial.println(ppm_co2);
      Serial.print("Co : ");
   Serial.println(ppm_co);
         Serial.print("Temperatura : ");
   Serial.println(temp);
            Serial.print("Humedad : ");
   Serial.println(hum);
   display.clearDisplay();
   //titulo
   display.setCursor(0,0);
   display.setTextSize(1);
   display.print("Calidad del Aire");
   //mq135
   display.setCursor(0,12);
   //display.setTextSize(1);
   display.print("CO2 ");
   display.print(ppm_co2,2);
         display.print(" PPM");
  //mq09
      display.setCursor(0,24);
   display.print("CO ");
   display.print(ppm_co,2);
      display.print(" PPM");
   //temperatura
         display.setCursor(0,36);
   display.print("Temp ");
   display.print(temp,1);
      display.print(" C");
   //humedad
         display.setCursor(0,48);
   display.print("Humedad ");
   display.print(hum,1);
   display.print(" %");
    display.display();
   delay(500);
   

}
