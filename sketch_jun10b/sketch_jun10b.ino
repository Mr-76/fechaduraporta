#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 3;

int password = 0;

int tamanho = 0;


char keys[ROWS][COLS] = { 

		{'1','2','3'},
		{'4','5','6'},
		{'7','8','9'},
		{'*','0','#'}
			
			};
byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = {5,4,3};

Keypad keypad = Keypad( makeKeymap(keys),rowPins,colPins,ROWS,COLS);


void setup() {
  pinMode(13, OUTPUT);
  pinMode(12,OUTPUT);

	Serial.begin(9600);


}

void loop() {


char key = keypad.getKey();

if (key == '*'){
while(true){
digitalWrite(13,HIGH);
  
char key = keypad.getKey();

if (key != '#' || key != '*'){
  
  
//Serial.println("key");
//Serial.print(key);
key = (int)key;
password += key;
Serial.println("password"); 
delay(100);
Serial.print(password);
}

if (key == '#'){


Serial.println("NOVO PASS");
Serial.print(password);
password = password - 35;
if (password == 202){
Serial.println("ABERTO");
Serial.print(password);

digitalWrite(13,HIGH);
delay(200);
digitalWrite(13,LOW);
delay(200); 
digitalWrite(13,HIGH);
delay(200);
digitalWrite(13,LOW);
delay(200);
digitalWrite(13,HIGH);
delay(200);
digitalWrite(13,LOW);
delay(200); 

digitalWrite(12,HIGH);
delay(5000);
digitalWrite(12,LOW);
delay(5000);
Serial.print("ABERTO");
  password = 0;
  break;
  
  }
else { 

password = 0;
digitalWrite(13,HIGH);
delay(1000);
digitalWrite(13,LOW);
delay(1000); 
digitalWrite(13,HIGH);
delay(1000);
digitalWrite(13,LOW);
delay(1000);
digitalWrite(13,HIGH);
delay(1000);
digitalWrite(13,LOW);
delay(1000);
  } 
  
  
  }
  
  }
  
  }



  


}
