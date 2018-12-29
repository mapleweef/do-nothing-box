//todo 

//int range is -32,768 to 32,767
//byte range is 0 to 255

int randNum; 
int threshold = 0;

byte buzzer = 10;
byte red = 8;
byte yellow = 6;
byte green = 4;
byte button = 2;

bool leave = false;
int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  randomSeed(analogRead(1)); //needed for random
  
  pinMode(buzzer,OUTPUT);//buzzer 
  pinMode(red, OUTPUT);//red
  pinMode(yellow, OUTPUT);//yellow/blue
  pinMode(green, OUTPUT);//green

  pinMode(button, INPUT);//button

}

void loop() {
  // put your main code here, to run repeatedly:

  randNum = random(1001);//generates a random number from 0 to 1000 cuz this this is based on c++ 
  leave = false;
  
  if (randNum <= threshold){ //button has been replaced with light orange cable becasue button is garbage. Code works tho. 
    threshold = 0;
    while(1){
      digitalWrite(buzzer,HIGH);
      for (int c=0; c<=5; c++){
        digitalWrite(red,HIGH);
        delay(100);
        digitalWrite(red,LOW);
        buttonState = digitalRead(button);
        if (buttonState == HIGH){
          leave = true;
          break;
        }
        delay(100);
      }
      digitalWrite(buzzer,LOW);
      
      for (int c=0; c<=5; c++){
        digitalWrite(red,HIGH);
        delay(100);
        digitalWrite(red,LOW);
        buttonState = digitalRead(button);
        if (buttonState == HIGH){
          leave = true;
          break;
        }
        delay(100);
      }

      if (leave) break;
           
    }    
  }

  else if (randNum > threshold && randNum < threshold + 100){ //about 10% of the time
    for (int c = 0; c<=1800; c++){
      digitalWrite(yellow,HIGH);
      delay(1000);
      digitalWrite(yellow,LOW);
      delay(1000);
    }
    threshold++;
  }

  else {
    for (int c = 0; c<=1800; c++){
      digitalWrite(green,HIGH);  
      delay(1000);//delay of 1 second 
      digitalWrite(green,LOW);
      delay(1000);
    }
    threshold++;
  }//end of if statments  
  
  //delay(1000);//this is so everything stays off for a second
}//end of main loop
