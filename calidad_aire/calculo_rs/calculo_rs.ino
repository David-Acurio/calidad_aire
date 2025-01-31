const int c=34;
void setup() {
  Serial.begin(115200);
  Serial.println("Calculo de Rs");
  delay(1000);

}

void loop() {
  float v_r1k;
  float r_sens;
 float sensorvalue;//el valor optenido de la entreda analogica 0 4094
 //tomamos milmuestras del sensor para depues calcular rs
 for(int x=0; x<=1000 ;x++){
  sensorvalue=sensorvalue+analogRead(c);
  
 }
 sensorvalue=sensorvalue/1000.0;
 v_r1k=(sensorvalue/4094)*5;
 Serial.print("voltaje en la r 1k");
 Serial.println(v_r1k);
 r_sens=1000*(5/v_r1k-1);
 Serial.print("resisten Rs");
 Serial.println(r_sens);
 delay(1000);
}
