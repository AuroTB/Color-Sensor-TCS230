#define S0 3
#define S1 4
#define S2 5
#define S3 6
#define sensorOut 8

int frequencyR=0, frequencyG=0, frequencyB =0;

void setup(){
  //configuran la frecuencia
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  
  //seleccionan el color
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  
  //salida
  pinMode(sensorOut, INPUT);
  
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
  
}

void loop() {
  getFreq();
  showColor();
}

void getFreq(){
    // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  frequencyR = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequencyR = map(frequencyR, 20,44,0,255);
  // Printing the value on the serial monitor
//  Serial.print("R= ");//printing name
//  Serial.print(frequencyR);//printing RED color frequency
//  Serial.print("  ");
  delay(100);
  
  
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequencyG = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequencyG = map(frequencyG,24,44,0,255);
  // Printing the value on the serial monitor
//  Serial.print("G= ");//printing name
//  Serial.print(frequencyG);//printing RED color frequency
//  Serial.print("  ");
  delay(100);
  
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequencyB = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequencyB = map(frequencyB, 17,46,0,255);
  // Printing the value on the serial monitor
//  Serial.print("B= ");//printing name
//  Serial.print(frequencyB);//printing RED color frequency
//  Serial.println("  ");
  delay(100);
}

void showColor()
{
  if(frequencyR<frequencyB&&frequencyB<frequencyG){
    //rosa, ROJO Y NEGRO
    if(frequencyR>200){
      Serial.println("Negro");
    }
    else if(frequencyB-frequencyR>210){
      Serial.println("Rojo");
    }else{
      Serial.println("Rosa");
    }
  }else if(frequencyG<frequencyR&&frequencyR<frequencyB){
    //VERDE Y BLANCO
    if(frequencyB-frequencyR>100){
      Serial.println("Verde");
    }else{
      Serial.println("Blanco");
    }
  }else if(frequencyB<frequencyG&&frequencyG<frequencyR){
    //AZÚL
    Serial.println("Azul");
  }else if(frequencyB<frequencyR&&frequencyR<frequencyG){
    //NEGRO
    Serial.println("Negro");
  }else if(frequencyR<frequencyG&&frequencyG<frequencyB){
    //AMARILLO
    Serial.println("Amarillo");
  }else{
    Serial.println("UNDF");
  }
  
}

