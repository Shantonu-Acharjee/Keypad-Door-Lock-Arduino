#include <Keypad.h>
int buttonpinA = A0;
int buttonStateA = 0; 
char*passwordA = "123";  // change thepasswordA here, just pick any 3 numbers
int position = 0;
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};

byte rowPins[ROWS] = { 9, 8, 7, 6 };
byte colPins[COLS] = { 5, 4, 3, 2 };
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int Lock = 13;
 
char* t;



void setup()
{
pinMode(buttonpinA,INPUT);
pinMode(Lock,OUTPUT);
LockedPosition(true);
}
void loop()
{
buttonStateA = analogRead(buttonpinA);
if(buttonStateA > 600){
digitalWrite(Lock, HIGH);
delay(3000);
digitalWrite(Lock, LOW);
}

char key = keypad.getKey();
if (key == '*' || key == '#')
{
position = 0;
LockedPosition(true);
}
if (key ==passwordA[position])
{
position ++;
}
if (position == 3)
{
LockedPosition(false);
}
delay(100);
}
void LockedPosition(int locked)
{
if (locked)
{
digitalWrite(Lock, LOW);

}
else
{
digitalWrite(Lock, HIGH);
delay(3000);
digitalWrite(Lock, LOW);
}
}
