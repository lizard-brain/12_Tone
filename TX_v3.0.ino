#define HWSERIAL Serial1
#include <MIDI.h>
int Return = 0;
int type, note, velocity, channel, d1, d2;

void setup() {
  MIDI.begin(MIDI_CHANNEL_OMNI);
  Serial.begin(9600);
  HWSERIAL.begin(31250);
  
  pinMode(13, OUTPUT);
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  
  Serial.println("MIDI Input Test");
  
  
}

unsigned long t=0;

void loop() {
  
  if (MIDI.read()) {                    // Is there a MIDI message incoming ?

        type = MIDI.getType();
        note = MIDI.getData1();
        velocity = MIDI.getData2();
        channel = MIDI.getChannel();

        Serial.println(String("~") + type + "," + channel + "," + velocity + "," + note + "~");
        
        HWSERIAL.println(String("~") + type + "," + channel + "," + velocity + "," + note + "~");
                  
       }
}
