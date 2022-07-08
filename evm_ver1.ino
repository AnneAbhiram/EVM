int person_a = 0;
int person_b = 0;
int person_c = 0;
int person_d = 0;
int button1;
int button2;
int button3;
int button4;
int calculate;

#include <LiquidCrystal_I2C.h> /*To use the lcd with i2c protocol*/
LiquidCrystal_I2C lcd(0x27, 16, 2); /*learn@ https://arduinogetstarted.com/tutorials/arduino-lcd-i2c*/

#include <BoltIoT-Arduino-Helper.h> /*helps bolt and arduino to work together learn@ https://github.com/Inventrom/boltiot-arduino-helper*/
/* #ifndef API_KEY
#define API_KEY   "xxxxxxx-xxxx-xxxx-xxxx-xxxxxxxx"
#endif
#ifndef DEVICE_ID
#define DEVICE_ID "BOLTxxxxxxxx"
#endif
*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void setup()
{
  Serial.begin(9600);
  boltiot.Begin(10,9); /*define TX and RX respectively learn interfacing at https://docs.boltiot.com/docs/arduino-library */
  lcd.init();
  lcd.backlight();
  pinMode(7, INPUT_PULLUP);/*using the internal resitance of the arduino - elimiate the use of external resistor*/
  pinMode(5, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void loop()
{
  int button1 = digitalRead(7);
  int button2 = digitalRead(5);
  int button3 = digitalRead(4);
  int button4 = digitalRead(3);
  int calculate = digitalRead(12);
  boltiot.processPushDataCommand(person_a, person_b, person_c, person_d);/*this is the command which enables the bolt module to check the data of the variables*/
  if (button1 == 0) INCREASEa();
  if (button2 == 0) INCREASEb();
  if (button3 == 0) INCREASEc();
  if (button4 == 0) INCREASEd();
  if (calculate == 0) result();
  delay(280);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~FUNCTIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void INCREASEa()
{
  lcd.clear();
  lcd.print("Person A");
  Serial.print("voted for person A");
  person_a++;
  Serial.print("\n");
}


void INCREASEb()
{
  lcd.clear();
  lcd.print("Person B");
  Serial.print("voted for person B");
  person_b++;
  Serial.print("\n");
}


void INCREASEc()
{
  lcd.clear();
  lcd.print("Person C");
  Serial.print("voted for person C");
  person_c++;
  Serial.print("\n");
}


void INCREASEd()
{
  lcd.clear();
  lcd.print("Person D");
  Serial.print("voted for person D");
  person_d++;
  Serial.print("\n");
}

/*this fucntion is used for calculating the result*/

void result()
{
  Serial.print("\n"); Serial.print("\n");
  if (person_a > person_b && person_a > person_c && person_a > person_d)
  {
    Serial.print("Person A won with ");
    Serial.print(person_a);
    Serial.print(" votes");
    lcd.clear();
    lcd.print("Person A won");
    lcd.setCursor(0, 1);
    lcd.print("with "); lcd.print(person_a); lcd.print(" votes");
  }

  else if (person_b > person_a && person_b > person_c && person_b > person_d)
  {
    Serial.print("Person B won with ");
    Serial.print(person_b);
    Serial.print(" votes");
    lcd.clear();
    lcd.print("Person B won");
    lcd.setCursor(0, 1);
    lcd.print("with "); lcd.print(person_b); lcd.print(" votes");
  }

  else if (person_c > person_a && person_c > person_b && person_c > person_d)
  {
    Serial.print("Person C won with ");
    Serial.print(person_c);
    Serial.print(" votes");
    lcd.clear();
    lcd.print("Person C won");
    lcd.setCursor(0, 1);
    lcd.print("with "); lcd.print(person_c); lcd.print(" votes");
  }

  else if (person_d > person_a && person_d > person_b && person_d > person_c)
  {
    Serial.print("Person D won with ");
    Serial.print(person_d);
    Serial.print(" votes");
    lcd.clear();
    lcd.print("Person D won");
    lcd.setCursor(0, 1);
    lcd.print("with "); lcd.print(person_d); lcd.print(" votes");
  }
}
