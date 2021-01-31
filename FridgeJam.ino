/*SFX*/
#include <PCM.h>

/*MPR121*/
#include <Wire.h>
#include "Adafruit_MPR121.h"
#ifndef _BV
#define _BV(bit) (1 << (bit)) 
#endif
Adafruit_MPR121 cap = Adafruit_MPR121();
uint16_t lasttouched = 0; // Keeps track of the last pins touched
uint16_t currtouched = 0; // so we know when buttons are 'released'

/*MFRC522*/
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9         
#define SS_PIN          10 

MFRC522 mfrc522(SS_PIN, RST_PIN); 


void setup()
{
  Serial.begin(9600);

  /*MFRC522 Initialization*/
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  
  /*Detects MPR121*/
  if (!cap.begin(0x5A)) {
    Serial.println("MPR121 not found");
    while (1);
  } Serial.println("MPR121 found!");

  Serial.write(200);
}

void loop()
{
  nfcReader();
}

void nfcReader() {
    if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

if (mfrc522.uid.uidByte[0] == 0x04 && 
     mfrc522.uid.uidByte[1] == 0xb3 &&
     mfrc522.uid.uidByte[2] == 0xfc &&
     mfrc522.uid.uidByte[3] == 0x1a &&
     mfrc522.uid.uidByte[4] == 0x4f &&
     mfrc522.uid.uidByte[5] == 0x65 &&
     mfrc522.uid.uidByte[6] == 0x80) {
     ctaSFX();}


if (mfrc522.uid.uidByte[0] == 0x04 && 
     mfrc522.uid.uidByte[1] == 0x4a &&
     mfrc522.uid.uidByte[2] == 0x88 &&
     mfrc522.uid.uidByte[3] == 0xd2 &&
     mfrc522.uid.uidByte[4] == 0xe8 &&
     mfrc522.uid.uidByte[5] == 0x6b &&
     mfrc522.uid.uidByte[6] == 0x80) {
     pianoSFX();}
}

void ctaSFX() {
  currtouched = cap.touched();
  
  for (uint8_t i=0; i<12; i++) {
    //if is touched, send touched number to serial
    if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) ) {
      Serial.write(i);
    }

    //when not touched, send a default to the serial
    if (!(currtouched & _BV(i)) && (lasttouched & _BV(i)) ) {
      Serial.write(200);
    }
  }

  // reset our state
  lasttouched = currtouched;

  // comment out this line for detailed data from the sensor!
  return;
}

void pianoSFX() {
  currtouched = cap.touched();
  
  for (uint8_t i=0; i<12; i++) {
    //if is touched, send touched number to serial
    if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) ) {
      Serial.write(i+8);
    }

    //when not touched, send a default to the serial
    if (!(currtouched & _BV(i)) && (lasttouched & _BV(i)) ) {
      Serial.write(200);
    }
  }

  // reset our state
  lasttouched = currtouched;

  // comment out this line for detailed data from the sensor!
  return;
}

/*#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9         
#define SS_PIN 10      

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

void setup() {
  Serial.begin(9600);   // Initialize serial communications with the PC
  while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  Serial.println("Scan a card to input sound");
}

void loop() {
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

Serial.print("Card UID:");
Serial.println(mfrc522.uid.size);
/*for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
}
Serial.println();

  //Serial.println(mfrc522.uid.uidByte[7]);
  //mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}*/
