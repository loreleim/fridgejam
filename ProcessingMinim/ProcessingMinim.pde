import processing.serial.*;
import ddf.minim.*;
 
Serial myPort;
int serialValue;
Minim minim;
AudioPlayer doors1, doors2, doors3, chicagoStop, ctaDing, doorsClosing, fullertonNext, pianoC, pianoD, pianoE, pianoF, pianoG, pianoA, pianoB, pianoChi;
byte arbitraryCode = 97;
 
void setup()
{
  myPort = new Serial(this, "COM4", 9600);
  minim = new Minim(this);
  
  //CTA 
  doors1 = minim.loadFile("cta/Doors1.mp3");
  doors2 = minim.loadFile("cta/Doors2.mp3");
  doors3 = minim.loadFile("cta/Doors3.mp3");
  chicagoStop = minim.loadFile("cta/chicagoStop.mp3");
  ctaDing = minim.loadFile("cta/ctaDing.mp3");
  doorsClosing = minim.loadFile("cta/doorsClosing.mp3");
  fullertonNext = minim.loadFile("cta/fullertonNext.mp3");
  
  //Piano
  pianoC = minim.loadFile("piano/1C.mp3");
  pianoD = minim.loadFile("piano/2D.mp3");
  pianoE = minim.loadFile("piano/3E.mp3");
  pianoF = minim.loadFile("piano/4F.mp3");
  pianoG = minim.loadFile("piano/5G.mp3");
  pianoA = minim.loadFile("piano/6A.mp3");
  pianoB = minim.loadFile("piano/7B.mp3");
  pianoChi = minim.loadFile("piano/8Chi.mp3");
}

 
void draw() {
  
  /*while (myPort.available() > 0) {
    if (myPort.read() == 1) {
      doors1.rewind();
      doors1.play();
    } else {
      pianoC.rewind();
      pianoC.play();
    }
  }*/
  
  /*This Kinda Works but not well*/
  if (myPort.available() > 0) {
    serialValue = myPort.read();
  }
  println(serialValue);
  if (serialValue == 0) {
    doors1.play();
  }
  if (serialValue == 1) {
    doors2.play();
  }
  if (serialValue == 2) {
    doors3.play();
  }
  if (serialValue == 3) {
    chicagoStop.play();
  }
  if (serialValue == 4) {
    ctaDing.play();
  }
  if (serialValue == 5) {
    doorsClosing.play();
  }
  if (serialValue == 6) {
    fullertonNext.play();
  }
  if (serialValue == 7) {
    doorsClosing.play();
  }
  if (serialValue == 8) {
    pianoC.play();
  }
  if (serialValue == 9) {
  pianoD.play();
  }
  if (serialValue == 10) {
  pianoE.play();
  }
  if (serialValue == 11) {
  pianoF.play();
  }
  if (serialValue == 12) {
  pianoG.play();
  } 
  if (serialValue == 13) {
  pianoA.play();
  }
  if (serialValue == 14) {
  pianoB.play();
  }
  if (serialValue == 15) {
  pianoChi.play();
  }
  if (serialValue == 200) {
    doors1.pause();
    doors1.rewind();
    doors2.pause();
    doors2.rewind();
    doors3.pause();
    doors3.rewind();
    chicagoStop.pause();
    chicagoStop.rewind();
    ctaDing.pause();
    ctaDing.rewind();
    doorsClosing.pause();
    doorsClosing.rewind();
    fullertonNext.pause();
    fullertonNext.rewind();
    pianoC.pause();
    pianoC.rewind();
    pianoD.pause();
    pianoD.rewind();
    pianoE.pause();
    pianoE.rewind();
    pianoF.pause();
    pianoF.rewind();
    pianoG.pause();
    pianoG.rewind();
    pianoA.pause();
    pianoA.rewind();
    pianoB.pause();
    pianoB.rewind();
    pianoChi.pause();
    pianoChi.rewind();
  }
}

/*void serialEvent(Serial test) {
  println(test.read());
  if (test.read() == 1) {
    doors1.rewind();
    doors1.play();
  }
}*/
