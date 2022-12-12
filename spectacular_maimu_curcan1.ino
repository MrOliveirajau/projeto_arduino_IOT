// C++ code
//
const int sensor = A0;
const int pino_ledVerm = 6;
const int pino_buzzer = 7;
const int pino_vent = 5;


float leitura_sensor = 0;
float tensao = 0;
float temperatura = 0;


void setup()
{
  Serial.begin (9600);
  pinMode (pino_ledVerm, OUTPUT);
  pinMode (pino_buzzer, OUTPUT);
  pinMode (pino_vent, OUTPUT);
  
}

void loop()
{
  leitura_sensor = analogRead(sensor);
  tensao = 5*leitura_sensor/1023;
  temperatura = (tensao - 0.5)*100;
  
  Serial.print ("Tensao de saida do sensor: ");
  Serial.print (tensao);
  Serial.println("V");
  
  Serial.print ("Temperatura do ambiente: ");
  Serial.print (temperatura);
  Serial.println("Graus Celsius");
  Serial.println();
  
  if (temperatura>=30){
    digitalWrite(pino_ledVerm,LOW);
    digitalWrite(pino_buzzer,LOW);
    digitalWrite(pino_vent,HIGH);
  }
  
  
  if (temperatura>50){
    digitalWrite(pino_ledVerm,HIGH);
    digitalWrite(pino_buzzer,HIGH);
    
  }
    
   if (temperatura<30){
    digitalWrite(pino_ledVerm,LOW);
    digitalWrite(pino_buzzer,LOW);
    digitalWrite(pino_vent,LOW); 
  }
}