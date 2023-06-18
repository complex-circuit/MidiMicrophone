#include <MIDIUSB.h>
void setup() {
  Serial.begin(115200);
  pinMode(5,INPUT);
}

void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
  MidiUSB.flush();
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
  MidiUSB.flush();
}
byte freqToNote(double frequency){
  return(round(12*log(frequency/8)/log(2)));
}

#define numIterations 10

byte currentNote=-1;
void loop() {
  
  double p=0;
  for(int i=0;i<numIterations;i++){
    p+=pulseIn(5,true,100000)+pulseIn(5,false,100000);
  }
  p/=numIterations;
  
  if(p==0){
    if(currentNote!=-1){
      noteOff(0,currentNote,64);
      currentNote=-1;
    }
    return;
  }
  
  double freq=1000000/p;
  byte note=freqToNote(freq);
  if(note!=currentNote){
    noteOff(0,currentNote,64);
    currentNote=note;
    noteOn(0,note,64);
  }
  

}
