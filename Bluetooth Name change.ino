// Engr Din Muhammad 
//www.projexels.com

#include <SoftwareSerial.h>

SoftwareSerial BTSerial(11, 10);  // RX, Tx

void setup() {
 Serial.begin(9600);
 BTSerial.begin(9600);

 BTSerial.write("AT+DEFAULT\r\n");
 BTSerial.write("AT+RESET\r\n");
 BTSerial.write("AT+NAME mybluetoothname\r\n");    //replace mybluetoothname 
 BTSerial.write("AT+ROLE1\r\n");
 BTSerial.write("AT+TYPE1"); //Simple pairing
}
void loop()
{
 if (BTSerial.available())
 Serial.write(BTSerial.read());
 if (Serial.available()){
 BTSerial.write(Serial.read());
 }
}
