//Written by Manasseh Gikonyo
//Email: manasseh65mwas25@gmail.com

#include <LiquidCrystal.h>
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//Defining the keyMap
char keys[ROWS][COLS] = {
  {'7','8','9','D'},
  
  {'4','5','6','C'},
  
  {'1','2','3','B'},
  
  {'*','0','#','A'},
  
};
byte rowPins[ROWS] = {0, 1, 2, 3};//Connect keyPad ROW 0, ROW 1, ROW 2 and ROW 3 to those arduino pins
byte colPins[COLS] = {4, 5, 6, 7};//Connect keyPad COL 0, COL 1, COL 2 and COL 3 to those arduino pins

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //Create the keypad
const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13; //Pins to which LCD is connected
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

long num1, num2, number;
char key, action;
boolean result = false;
void setup() {
  lcd.begin(16, 2);
  lcd.print("Calculator");
  lcd.setCursor(0, 1);
  lcd.print("By Manasseh");

  delay(5000);
  lcd.clear();
}
void loop() {
  // put your main code here, to run repeatedly:
  key = kpd.getKey();//Storing the pressed key value in a char
  
  if(key != NO_KEY){
    detectPressedButton();
  }
  if(result == true)
  calculateResult();
  
  displayResult();

}
void detectPressedButton(){
  lcd.clear();
  if(key == '*'){
    Serial.println("Button Cancel");
    number = num1 = num2 = 0;
    result = false;
    
  }
  if(key == '1' ){//Button 1 pressed
    Serial.println("Button 1");
    if(number == 0)
    number = 1;
    else 
    number = (number*10) + 1;//Pressed twice
  }
  if(key == '4' ){//Button 4 pressed
    Serial.println("Button 4");
    if(number == 0)
    number = 4;
    else 
    number = (number*10) + 4;//Pressed twice
  }
  if(key == '7' ){//Button 7 pressed
    Serial.println("Button 7");
    if(number == 0)
    number = 7;
    else 
    number = (number*10) + 7;//Pressed twice
  }
  if(key == '0' ){//Button 0 pressed
    Serial.println("Button 0");
    if(number == 0)
    number = 0;
    else 
    number = (number*10) + 0;//Pressed twice
  }
  if(key == '2' ){//Button 2 pressed
    Serial.println("Button 2");
    if(number == 0)
    number = 2;
    else 
    number = (number*10) + 2;//Pressed twice
  }
  if(key == '5' ){//Button 5 pressed
    Serial.println("Button 5");
    if(number == 0)
    number = 5;
    else 
    number = (number*10) + 5;//Pressed twice
  }
  if(key == '8' ){//Button 8 pressed
    Serial.println("Button 8");
    if(number == 0)
    number = 8;
    else 
    number = (number*10) + 8;//Pressed twice
  }
  if(key == '#'){
    Serial.println("Button Equal");
    num2 = number;
    result = true;
  }
  if(key == '3' ){//Button 3 pressed
    Serial.println("Button 3");
    if(number == 0)
    number = 3;
    else 
    number = (number*10) + 3;//Pressed twice
  }
  if(key == '6' ){//Button 6 pressed
    Serial.println("Button 6");
    if(number == 0)
    number = 6;
    else 
    number = (number*10) + 6;//Pressed twice
  }
  if(key == '9' ){//Button 9 pressed
    Serial.println("Button 9");
    if(number == 0)
    number = 9;
    else 
    number = (number*10) + 9;//Pressed twice
  }
  if(key == 'A' || key == 'B' || key == 'C' || key == 'D'){//Detecting column 4 buttons
    num1 = number;
    number = 0;
    if(key == 'A')
    {
      Serial.println("Addition");
      action = '+';
    }
    if(key == 'B')
    {
      Serial.println("Subtraction");
      action = '-';
    }
    if(key == 'C')
    {
      Serial.println("Multiplication");
      action = '*';
    }
    if(key == 'D')
    {
      Serial.println("Division");
      action = '/';
    }
    delay(100);
  }
}
void calculateResult(){
  if(action == '+'){
    number = num1 + num2;
  }
  if(action == '-'){
    number = num1 - num2;
  }
  if(action == '*'){
    number = num1 * num2;
  }
  if(action == '/'){
    number = num1 / num2;
  }
}
void displayResult(){
  lcd.setCursor(0, 0);
  lcd.print(num1);
  lcd.print(action);
  lcd.print(num2);

  if(result == true){
    lcd.print(" = ");
    lcd.print(number);
  }
  lcd.setCursor(0, 1);
  lcd.print(number);//Display the result
}
