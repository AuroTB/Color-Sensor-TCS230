//Sensor pin otputs
#define S0 3
#define S1 4
#define S2 5
#define S3 6
//Input
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

void getFreq(){     //Gets the frequencies of the red, green and blue filters
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

void showColor()      //Comparison code of frequencies
{
  if(frequencyR<frequencyB&&frequencyB<frequencyG){
    //Pink, red, Black
    if(frequencyR>200){
      Serial.println("Black");
    }
    else if(frequencyB-frequencyR>210){
      Serial.println("Red");
    }else{
      Serial.println("Pink");
    }
  }else if(frequencyG<frequencyR&&frequencyR<frequencyB){
    //White, green
    if(frequencyB-frequencyR>100){
      Serial.println("Green");
    }else{
      Serial.println("White");
    }
  }else if(frequencyB<frequencyG&&frequencyG<frequencyR){
    //Blue
    Serial.println("Blue");
  }else if(frequencyB<frequencyR&&frequencyR<frequencyG){
    //Black
    Serial.println("Black");
  }else if(frequencyR<frequencyG&&frequencyG<frequencyB){
    //Yellow
    Serial.println("Yellow");
  }else{
    Serial.println("UNDF");
  }
  
}

