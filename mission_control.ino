#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int Sensor = A1;
int Lumi = A0;
int Vibra = 6;
void setup()
{

  Serial.begin(9600);
  pinMode(Sensor, INPUT);
  pinMode(Vibra, INPUT_PULLUP);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("MISSION CONTROL");
  lcd.setCursor(0, 1);
  lcd.print("SYSTEM ONLINE");
  
 
}

void loop(){
  int valor;
  int valorT;
  int vibraValor;
  
  valor = analogRead(Sensor);
  float tensao = valor * (5.0 / 1023.0);
  float temperatura = (tensao - 0.5) * 100;
  Serial.println(valor);
  Serial.println(tensao);
  Serial.println(temperatura);
  valorT = analogRead(Lumi);
  Serial.println(valorT);
  vibraValor = digitalRead(Vibra);
  Serial.println(vibraValor);
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TEMP = ");
  lcd.print(temperatura, 1);
  lcd.print(" C");
  if (temperatura < 35){
   lcd.setCursor(0,1);
  lcd.print("SAFE");
  digitalWrite(7, HIGH);
  delay(500);
  digitalWrite(7, LOW);

    
    }
  if (temperatura > 35 && temperatura < 51){
   lcd.setCursor(0,1);
   lcd.print("WARNING");
   digitalWrite(8, HIGH);
   delay(500);
   digitalWrite(8, LOW);
    }
   if (temperatura > 50){
  lcd.setCursor(0,1);
  lcd.print("CRITICAL");
  digitalWrite(9, HIGH);
  delay(500);
  digitalWrite(9, LOW);
    }
  
  delay(3000);
  lcd.clear();
  
  
  if (valorT < 200){
  lcd.setCursor(0,0);
  lcd.print("LUMI = ");
  lcd.print(valorT, 1);
   lcd.setCursor(0,1);
  lcd.print("LOW LIGHT");

    }
  if (valorT > 200 && valorT < 950){
  lcd.setCursor(0,0);
  lcd.print("LUMI = ");
  lcd.print(valorT, 1);
   lcd.setCursor(0,1);
   lcd.print("LIGHT OK");
    }
   if (valorT > 950){
  lcd.setCursor(0,0);
  lcd.print("LUMI = ");
  lcd.print(valorT, 1);
  lcd.setCursor(0,1);
  lcd.print("SOLAR ALERT");

    }
  
  delay(2000);
  lcd.clear();

    if (vibraValor == 1){
   lcd.setCursor(0,0);
   lcd.print("SYSTEM STABLE");
    }
   if (vibraValor == 0){
  lcd.setCursor(0,0);
  lcd.print("TURBULENCE");

    }
  delay(2000);
  
}




