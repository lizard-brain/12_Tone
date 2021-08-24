#define HWSERIAL Serial1
#include <MIDI.h>
int Return = 0;
int type, note, velocity, channel, d1, d2, key;

int remote = 0;

/* = 
 *  0 =  turn all stacks off
 *  1 = turn all stacks white
 *  2 = all stacks red
 *  3 = all stacks green
 *  4 = all stacks blue

*/

void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI);
  Serial.begin(31250);
  
  pinMode(13, OUTPUT);
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  
  Serial.println("MIDI Input Test");
  
  
}

unsigned long t=0;

void loop() {

for(int i = 12; i < 101; i++){
      
        type = 1;
        note = i;
        velocity = 126;
        channel = 0;

        Serial.println(String("~") + type + "," + channel + "," + velocity + "," + note + "~");
        
        Serial1.println(String("~") + type + "," + channel + "," + velocity + "," + note + "~");
        delay(250);
}

delay(1000);

for(int i = 12; i < 101; i++){
      
        type = 0;
        note = i;
        velocity = 0;
        channel = 0;

        Serial.println(String("~") + type + "," + channel + "," + velocity + "," + note + "~");
        
        Serial1.println(String("~") + type + "," + channel + "," + velocity + "," + note + "~");
        delay(50);
}

delay(3000);

       
}
