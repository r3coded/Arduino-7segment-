/* this code is for a 7 segment common anode display;
  ©r3coded
  (for the pin layout of the display check the img in this repository)
  Arduino Pin 2 to Pin 7.
  Arduino Pin 3 to Pin 6.
  Arduino Pin 4 to Pin 4.
  Arduino Pin 5 to Pin 2.
  Arduino Pin 6 to Pin 1.
  Arduino Pin 8 to Pin 9.
  Arduino Pin 9 to Pin 10.
 VCC to Pin 3 and Pin 8 each connected with 220 ohm resistors.
 
 Note: if you have a common cathode display connect pin 3 and 8 of your display trough two 220 ohm resistors to GND,
 and exchange "HIGH' & "LOW"
 in the code
 */


int a = 2;  //For displaying segment "a"
int b = 3;  //For displaying segment "b"
int c = 4;  //For displaying segment "c"
int d = 5;  //For displaying segment "d"
int e = 6;  //For displaying segment "e"
int f = 8;  //For displaying segment "f"
int g = 9;  //For displaying segment "g"
void setup() {
  pinMode(a, OUTPUT);  //A
  pinMode(b, OUTPUT);  //B
  pinMode(c, OUTPUT);  //C
  pinMode(d, OUTPUT);  //D
  pinMode(e, OUTPUT);  //E
  pinMode(f, OUTPUT);  //F
  pinMode(g, OUTPUT);  //G
}
void displayDigit(int digit)
{
  //Conditions for displaying segment a
  if (digit != 1 && digit != 4)
    digitalWrite(a, LOW);

  //Conditions for displaying segment b
  if (digit != 5 && digit != 6)
    digitalWrite(b, LOW);

  //Conditions for displaying segment c
  if (digit != 2)
    digitalWrite(c, LOW);

  //Conditions for displaying segment d
  if (digit != 1 && digit != 4 && digit != 7)
    digitalWrite(d, LOW);

  //Conditions for displaying segment e
  if (digit == 2 || digit == 6 || digit == 8 || digit == 0)
    digitalWrite(e, LOW);

  //Conditions for displaying segment f
  if (digit != 1 && digit != 2 && digit != 3 && digit != 7)
    digitalWrite(f, LOW);
  if (digit != 0 && digit != 1 && digit != 7)
    digitalWrite(g, LOW);

}
void turnOff()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}


void loop() {
  for (int i = 0; i < 10; i++)
  {
    displayDigit(i);
    delay(1000);
    turnOff();
  }
}
