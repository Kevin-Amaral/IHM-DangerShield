const byte digit[16] =
{
  B00111111,  // 0
  B00000110,  // 1
  B01011011,  // 2
  B01001111,  // 3
  B01100110,  // 4
  B01101101,  // 5
  B01111101,  // 6
  B00000111,  // 7
  B01111111,  // 8
  B01101111,  // 9
};
const int bit_clock_pin = 8;
const int digit_clock_pin = 7;
const int data_pin = 4;


int slider1 = 0;
int slider2 = 1;
int slider3 = 2;
int bp1 = 10;
int bp2 = 11;
int bp3 = 12;
void Send(); // Fonction pour envoier la trame avec slider et bp
void qt(); // pour recup les info de qt
int led1 = 6;
int led2 = 5;
int buzzer = 3;
int temp = 4;
float lectureTemp();
int lum = 3;
int on = 0x31;
int off = 0x32;

void setup() {
Serial.begin(9600);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(temp,INPUT);
pinMode(slider1,INPUT);
pinMode(slider2,INPUT);
pinMode(slider3,INPUT);
pinMode(bp1,INPUT);
pinMode(bp2,INPUT);
pinMode(bp3,INPUT);
pinMode(data_pin, OUTPUT);
pinMode(bit_clock_pin, OUTPUT);
pinMode(digit_clock_pin, OUTPUT);  
}

void loop() {
  if (Serial.available() > 0) {
                int data = Serial.read();
                if(data == 0x32){
                  digitalWrite(led1,LOW);
                }
                if(data == 0x31){
                  digitalWrite(led1,HIGH);
                }
                if(data == 0x33){
                  digitalWrite(led2,HIGH);
                }
                if(data == 0x34){
                  digitalWrite(led2,LOW);
                }
                if(data == 0x35){
                  byte pattern = digit[0];
                  digitalWrite(digit_clock_pin, LOW);
                  shiftOut(data_pin, bit_clock_pin, MSBFIRST, ~pattern);
                  digitalWrite(digit_clock_pin, HIGH);
                }
                if(data == 0x36){
                  byte pattern = digit[1];
                  digitalWrite(digit_clock_pin, LOW);
                  shiftOut(data_pin, bit_clock_pin, MSBFIRST, ~pattern);
                  digitalWrite(digit_clock_pin, HIGH);
                }
                if(data == 0x37){
                  byte pattern = digit[2];
                  digitalWrite(digit_clock_pin, LOW);
                  shiftOut(data_pin, bit_clock_pin, MSBFIRST, ~pattern);
                  digitalWrite(digit_clock_pin, HIGH);
                }
                if(data == 0x38){
                  byte pattern = digit[3];
                  digitalWrite(digit_clock_pin, LOW);
                  shiftOut(data_pin, bit_clock_pin, MSBFIRST, ~pattern);
                  digitalWrite(digit_clock_pin, HIGH);
                }
                if(data == 0x39){
                  byte pattern = digit[4];
                  digitalWrite(digit_clock_pin, LOW);
                  shiftOut(data_pin, bit_clock_pin, MSBFIRST, ~pattern);
                  digitalWrite(digit_clock_pin, HIGH);
                }
                if(data == 0x40){
                  byte pattern = digit[5];
                  digitalWrite(digit_clock_pin, LOW);
                  shiftOut(data_pin, bit_clock_pin, MSBFIRST, ~pattern);
                  digitalWrite(digit_clock_pin, HIGH);
                }
                if(data == 0x41){
                  byte pattern = digit[6];
                  digitalWrite(digit_clock_pin, LOW);
                  shiftOut(data_pin, bit_clock_pin, MSBFIRST, ~pattern);
                  digitalWrite(digit_clock_pin, HIGH);
                }
                if(data == 0x42){
                  byte pattern = digit[7];
                  digitalWrite(digit_clock_pin, LOW);
                  shiftOut(data_pin, bit_clock_pin, MSBFIRST, ~pattern);
                  digitalWrite(digit_clock_pin, HIGH);
                }
                if(data == 0x43){
                  byte pattern = digit[8];
                  digitalWrite(digit_clock_pin, LOW);
                  shiftOut(data_pin, bit_clock_pin, MSBFIRST, ~pattern);
                  digitalWrite(digit_clock_pin, HIGH);
                }
                if(data == 0x44){
                  byte pattern = digit[9];
                  digitalWrite(digit_clock_pin, LOW);
                  shiftOut(data_pin, bit_clock_pin, MSBFIRST, ~pattern);
                  digitalWrite(digit_clock_pin, HIGH);
                }
        }

  else{Send();}

}


void Send(){
  // lecture de tout input
  int var1 = analogRead(slider1);
  int var2 = analogRead(slider2);
  int var3 = analogRead(slider3);
  int var4 = !digitalRead(bp1);
  int var5 = !digitalRead(bp2);
  int var6 = !digitalRead(bp3);
  int var7 = lectureTemp();
  int var8 = analogRead(lum);
  int etatled1 = digitalRead(6);
  int etatled2 = digitalRead(5);
  //envoie de la trame
  Serial.print(var1);
  Serial.print("/");
  Serial.print(var2);
  Serial.print("/");
  Serial.print(var3);
  Serial.print("/");
  Serial.print(var4);
  Serial.print("/");
  Serial.print(var5);
  Serial.print("/");
  Serial.print(var6);
  Serial.print("/");
  Serial.print(var7);
  Serial.print("/");
  Serial.print(etatled1);
  Serial.print("/");
  Serial.print(etatled2);
  Serial.print("/");
  Serial.print(var8);
  Serial.print("/");
  delay(100);
}

void qt(){
  
}

float lectureTemp(){ // retourne la temp
 // Lecture de la valeur sur l'entrée analogique
 // Retourne une valeur entre 0->1024 pour 0->5v
 int valeur = analogRead(temp);  

 // Converti la lecture en tension
 float tension = valeur * 5.0;
 tension /= 1024.0; 
 
 // Convertir la tension (mv) en temperature
 float temperature = ((tension * 1000) - 500) / 10;
 
 return temperature;
}
