const int pins[] = {3,4,5,6,7,8,9,10,11,12,A5};
//pin 10 is for blue LED, 11 for green LED, A5, for red LED
const int gripdefValue = 480;
const int gripdestValue = 515;
const int m1offValue = 375;
const int m1defValue = 485;
const int m1destValue = 540;
//const int m1defValue = 360;
const int m2offValue = 250;
const int m2defValue = 300;
const int m2destValue = 113;
//const int m2defValue = 120;
const int basedefValue = 405;
const int basedefValue2 = 400;
//const int basedefvalue = 640;
const int basedestValue2 = 580; 
const int basedestValue3 = 485;  
const int basedestValue4 = 370;
//for colors:
int colors[] = {0,0,0};
int basePOT,gripPOT,m1POT,m2POT;
int decision = 0;
int runs = 0;

//const int[] defValues = {480,450,300,375};
//const int[] destValues = {495,540,80,580,465,330};

void setup(){
  
for(int i = 0; i <= 10 ; i++)
{
pinMode(pins[i],OUTPUT);
}

Serial.begin(9600);

}

void loop(){

for (int j = 0; j <= 10 ; j++)
{
digitalWrite(pins[j], LOW);
}
basePOT = analogRead(0);
m1POT = analogRead(1);
m2POT = analogRead(2);
gripPOT = analogRead(3);

if(runs > 9){
basedefault();
m1off();
gripopen();
m2off();
return;
}
else{
basedefault();
delay(250);
m1default();
delay(250);
gripopen();
delay(250);
m2default();
delay(250);
}

m2dest();
gripdest();
m2default();
//decider
colorDetect();
//descend, open grip
m1dest();
gripopen();

runs = runs + 1;

}

void m2default(){
  
if(m2POT <= m2defValue){
  while(m2POT <= m2defValue){
  digitalWrite(pins[2] , LOW);
  digitalWrite(pins[3] , HIGH);
  //pataas dapat ang m2POT
  m2POT = analogRead(2);
  }
  digitalWrite(pins[2],LOW);
  digitalWrite(pins[3],LOW);

return;
}
else if(m2POT >= m2defValue){
  while(m2POT >= m2defValue){
  digitalWrite(pins[2] , HIGH);
  digitalWrite(pins[3] , LOW);
  //pababa dapat ang m2POT
  m2POT = analogRead(2);
  }
  digitalWrite(pins[2],LOW);
  digitalWrite(pins[3],LOW);

return;
}

}

void m2off(){
  
if(m2POT >= m2offValue){
  while(m2POT >= m2offValue){
  digitalWrite(pins[2] , HIGH);
  digitalWrite(pins[3] , LOW);
  //pataas dapat ang m2POT
  m2POT = analogRead(2);
  }
  digitalWrite(pins[2],LOW);
  digitalWrite(pins[3],LOW);
}
}

void m2dest(){
  
if(m2POT >= m2destValue){
  while(m2POT >= m2destValue){
  digitalWrite(pins[2] , HIGH);
  digitalWrite(pins[3] , LOW);
  //pataas dapat ang m2POT
  m2POT = analogRead(2);
  }
  digitalWrite(pins[2],LOW);
  digitalWrite(pins[3],LOW);
//pakanan
return;
}

}

void gripopen(){
  if(gripPOT > gripdefValue){
  while(gripPOT > gripdefValue){
  digitalWrite(pins[0] , HIGH);
  digitalWrite(pins[1] , LOW);
  //pataas dapat ang basePOT
  gripPOT = analogRead(3);
  }
  digitalWrite(pins[0],LOW);
  digitalWrite(pins[1],LOW);
//pakanan
return;
  }
}
void gripdest(){
  //close
  if(gripPOT < gripdestValue){
  while(gripPOT < gripdestValue){
  digitalWrite(pins[0] , LOW);
  digitalWrite(pins[1] , HIGH);
  //pataas dapat ang basePOT
  gripPOT = analogRead(3);
  }
  digitalWrite(pins[0],LOW);
  digitalWrite(pins[1],LOW);
//pakanan
return;
  }
}

void basedefault(){
  
  if(basePOT < basedefValue2){
  while(basePOT < basedefValue2){
  digitalWrite(pins[4] , HIGH);
  digitalWrite(pins[5] , LOW);
  //pataas dapat ang basePOT
  basePOT = analogRead(0);
  }
  digitalWrite(pins[4],LOW);
  digitalWrite(pins[5],LOW);
  //pakanan
  return;
  }
  else if(basePOT > basedefValue){
  while(basePOT > basedefValue){
  digitalWrite(pins[4] , LOW);
  digitalWrite(pins[5] , HIGH);
  //pababa dapat ang basePOT
  basePOT = analogRead(0);
  }
  digitalWrite(pins[4],LOW);
  digitalWrite(pins[5],LOW);
  //pakaliwa
  return;
  }
}

void basedest(){
  
  if(basePOT < basedestValue2){
  while(basePOT < basedestValue2){
  digitalWrite(pins[4] , HIGH);
  digitalWrite(pins[5] , LOW);
  //pataas dapat ang basePOT
  basePOT = analogRead(0);
  }
  digitalWrite(pins[4],LOW);
  digitalWrite(pins[5],LOW);
  //pakanan
  return;
  }
}
void basedest2(){
  
  if(basePOT < basedestValue3){
  while(basePOT < basedestValue3){
  digitalWrite(pins[4] , HIGH);
  digitalWrite(pins[5] , LOW);
  //pataas dapat ang basePOT
  basePOT = analogRead(0);
  }
  digitalWrite(pins[4],LOW);
  digitalWrite(pins[5],LOW);
  //pakanan
  return;
  }
}
void basedest3(){
  
  if(basePOT > basedestValue4){
  while(basePOT > basedestValue4){
  digitalWrite(pins[4] , LOW);
  digitalWrite(pins[5] , HIGH);
  //pataas dapat ang basePOT
  basePOT = analogRead(0);
  }
  digitalWrite(pins[4],LOW);
  digitalWrite(pins[5],LOW);
  //pakanan
  return;
  }
}

void m1default(){
  if(m1POT < m1defValue){
    while(m1POT < m1defValue){
    digitalWrite(pins[6],HIGH);
    digitalWrite(pins[7],LOW);
    m1POT = analogRead(1);
    }
    digitalWrite(pins[6],LOW);
    digitalWrite(pins[7],LOW);
    return;
  }
  else if(m1POT > m1defValue){
    while(m1POT > m1defValue){
    digitalWrite(pins[6],LOW);
    digitalWrite(pins[7],HIGH);
    m1POT = analogRead(1);
    }
    digitalWrite(pins[6],LOW);
    digitalWrite(pins[7],LOW);
    return;
  }
}
void m1off(){
  if(m1POT > m1offValue){
    while(m1POT > m1offValue){
    digitalWrite(pins[6],LOW);
    digitalWrite(pins[7],HIGH);
    m1POT = analogRead(1);
    }
    digitalWrite(pins[6],LOW);
    digitalWrite(pins[7],LOW);
  }
}
void m1dest(){
  if(m1POT < m1destValue){
    while(m1POT < m1destValue){
    digitalWrite(pins[6], HIGH);
    digitalWrite(pins[7], LOW);
    m1POT = analogRead(1);
    }
    digitalWrite(pins[6],LOW);
    digitalWrite(pins[7],LOW);
    return;
  }
}

void colorDetect(){
digitalWrite(pins[8],LOW);
digitalWrite(pins[9],LOW);
digitalWrite(pins[10],LOW);
delay(1000);

digitalWrite(pins[8],HIGH);
delay(1000);
colors[0] = analogRead(4);
delay(1000);
digitalWrite(pins[8],LOW);

digitalWrite(pins[9],HIGH);
delay(1000);
colors[1] = analogRead(4);
delay(1000);
digitalWrite(pins[9],LOW);

digitalWrite(pins[10],HIGH);
delay(1000);
colors[2] = analogRead(4);
delay(1000);
digitalWrite(pins[10],LOW);

if(((colors[1] - colors[0]) < 7) && ((colors[2] - colors[1]) < 7)){
Serial.println("not ball");
Serial.print(colors[0]);
Serial.print(" ");
Serial.print(colors[1]);
Serial.print(" ");
Serial.print(colors[2]);
Serial.println("");
return;
}

else if((colors[2] > colors[0]) && (colors[2] > colors[1]) && (colors[1] < 350)){
Serial.println("red ball");
Serial.print(colors[0]);
Serial.print(" ");
Serial.print(colors[1]);
Serial.print(" ");
Serial.print(colors[2]);
Serial.println("");
basedest2();//red
return;
}
else if((colors[1] > colors[2]) && (colors[2] < 299)){
Serial.println("blue ball");
Serial.print(colors[0]);
Serial.print(" ");
Serial.print(colors[1]);
Serial.print(" ");
Serial.print(colors[2]);
Serial.println("");

basedest();//blue
return;
}
else if((colors[2] > colors[0]) && (colors[1] > colors[0]) && (colors[2] > 300) && (colors[1] > 280)){
Serial.println("yellow ball");
Serial.print(colors[0]);
Serial.print(" ");
Serial.print(colors[1]);
Serial.print(" ");
Serial.print(colors[2]);
Serial.println("");
basedest3();//yellow
delay(500);
return;
}

else{
Serial.println("no ball");
Serial.print(colors[0]);
Serial.print(" ");
Serial.print(colors[1]);
Serial.print(" ");
Serial.print(colors[2]);
Serial.println("");
return;
}
}
