//////////////////////////////////////////
//Modul Praktikum 1 Sistem Kendali On Off
//Kelompok 21 Bobo
//Dylan Avilla SA
//6702190089
//Versi Program 1.0
//////////////////////////////////////////
int sensor1 = A0,
	sensor2 = A1,
	sensor3 = A2,
	sensor4 = A3,
	sensor5 = A4,
	sensor6 = A5;
int baca_sensor[6];

int pinEnable1 = 4,
	pinEnable2 = 2;

int motor_kiri1 = 5,
	motor_kiri2 = 6;

int motor_kanan1 = 3,
	motor_kanan2 = 11;

void setup()
{
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);
  pinMode(sensor6, INPUT);
  
  pinMode(pinEnable1, OUTPUT);
  pinMode(pinEnable2, OUTPUT);
  pinMode(motor_kiri1,OUTPUT);
  pinMode(motor_kiri2,OUTPUT);
  pinMode(motor_kanan1,OUTPUT);
  pinMode(motor_kanan2,OUTPUT);
  
  Serial.begin(9600);
}

void readsensor() {
  baca_sensor[0] = analogRead(sensor1);
  baca_sensor[1] = analogRead(sensor2);
  baca_sensor[2] = analogRead(sensor3);
  baca_sensor[3] = analogRead(sensor4);
  baca_sensor[4] = analogRead(sensor5);
  baca_sensor[5] = analogRead(sensor6);
  
  for(int i=0;i<6;i++){
  	Serial.println(baca_sensor[i]);
   }
}

void loop()
{
	readsensor();
  
  if(baca_sensor[0] < 34 && baca_sensor[1] < 34 && 
     baca_sensor[2] > 34 && baca_sensor[3] > 34 &&
     baca_sensor[4] > 34 && baca_sensor[5] > 34) 
  {
  	
    digitalWrite(pinEnable1,HIGH);
    digitalWrite(motor_kiri1,LOW);
    digitalWrite(motor_kiri2,LOW);
    
    digitalWrite(pinEnable2,HIGH);
    digitalWrite(motor_kanan1,HIGH);
    digitalWrite(motor_kanan2,LOW);
    
    
  }
  //Sensor 3 dan 4 mendeteksi gelap kedua motor aktif
  if(baca_sensor[0] > 34 && baca_sensor[1] > 34 && 
     baca_sensor[2] < 34 && baca_sensor[3] < 34 &&
     baca_sensor[4] > 34 && baca_sensor[5] > 34) 
  {
  	
    digitalWrite(pinEnable1,HIGH);
    digitalWrite(motor_kiri1,HIGH);
    digitalWrite(motor_kiri2,LOW);
    
    digitalWrite(pinEnable2,HIGH);
    digitalWrite(motor_kanan1,HIGH);
    digitalWrite(motor_kanan2,LOW);
    
    
  }
  //Sensor 5 dan 6 mendeteksi gelap
    if(baca_sensor[0] > 34 && baca_sensor[1] > 34 && 
     baca_sensor[2] > 34 && baca_sensor[3] > 34 &&
     baca_sensor[4] < 34 && baca_sensor[5] < 34) 
  {
  	
    digitalWrite(pinEnable1,HIGH);
    digitalWrite(motor_kiri1,HIGH);
    digitalWrite(motor_kiri2,LOW);
    
    digitalWrite(pinEnable2,HIGH);
    digitalWrite(motor_kanan1,LOW);
    digitalWrite(motor_kanan2,LOW);
    
    
  }
  //Semua Sensor tidak mendeteksi gelap, kedua motor mati
     if(baca_sensor[0] > 34 && baca_sensor[1] > 34 && 
     baca_sensor[2] > 34 && baca_sensor[3] > 34 &&
     baca_sensor[4] > 34 && baca_sensor[5] > 34) 
  {
  	
    digitalWrite(pinEnable1,HIGH);
    digitalWrite(motor_kiri1,LOW);
    digitalWrite(motor_kiri2,LOW);
    
    digitalWrite(pinEnable2,HIGH);
    digitalWrite(motor_kanan1,LOW);
    digitalWrite(motor_kanan2,LOW);
    
    
  }
}