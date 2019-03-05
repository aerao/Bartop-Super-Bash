//////////////////////////////////////////////////////
//                                                  //
//    BARTOP SUPER BASH                             //
//    v1.0 (05/03/2019)                             //
//    @aerao                                        //
//    https://github.com/aerao/Bartop-Super-Bash    //
//                                                  //
//////////////////////////////////////////////////////


#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

// ACCESS
const byte btnP1 = 2;
const byte btnP2 = 3;
unsigned long begin_timer;
unsigned int vol_BSB = 21; // volume (0-30)
const int time_out = 10000;
bool temp1 = false;
bool temp2 = false;
bool temp3 = false;
bool temp4 = false;
bool variable_t = false;
bool menu_Vol = false;
bool access_Vol = false;
bool play_Music = true;
bool menu_general = true;
bool access_BSB = false;

// VARIABLES
byte start;
byte varBonus;
byte folder01Max;
byte folder02Max;
byte compteur1 = 0;
byte compteur2 = 0;
byte tabDefault[80];
byte tabBonus[20];
byte tab1_swap = 1;
byte tab2_swap = 1;
byte bonusMP3 = 5; // en %

void setup () {
  mySoftwareSerial.begin(9600);
  Serial.begin(9600);

  pinMode(btnP1, INPUT_PULLUP);
  pinMode(btnP2, INPUT_PULLUP);
  myDFPlayer.begin(mySoftwareSerial);
  myDFPlayer.setTimeOut(500);
  myDFPlayer.volume(vol_BSB);
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
  varBonus = ((100 / bonusMP3) + 1);
  folder01Max = myDFPlayer.readFileCountsInFolder(1);
  folder02Max = myDFPlayer.readFileCountsInFolder(2);
  delay(42);

  for (int i = 0; i < folder01Max; i++) {  // INITIALISATION DU TABLEAU DEFAULT
    tabDefault[i] = i + 1;
  }
  for (int i = 0; i < folder02Max; i++) {  // INITIALISATION DU TABLEAU BONUS
    tabBonus[i] = i + 1;
  }
}
void timer_init() {
  if (digitalRead(btnP1) == HIGH && digitalRead(btnP2) == HIGH) {
    if (variable_t == false) {
      variable_t = true;
      begin_timer = millis();
    }
  } else {
    variable_t = false;
    if (variable_t == false) {
      variable_t = true;
      begin_timer = millis();
    }
  }
}
void melange(byte tableau[], byte taille) {
  for (int c = 0; c < 3; c++) {
    for (int i = 0; i < taille; i++) {
      int j = random(i, taille);
      int swap = tableau[i];
      tableau[i] = tableau[j];
      tableau[j] = swap;
    }
  }
}
void randomInit() {
  byte rs = 0;
  for (byte i = 0; i < 32; i++) {
    rs = (rs << 1) | (analogRead(0) & 1);
  }
  randomSeed(rs);
}

void loop () {

  if (menu_general == true) { //ACCES MENU GENERAL
    if (digitalRead(btnP1) == LOW && digitalRead(btnP2) == LOW && access_BSB == false) {
      if (temp1 == false) {
        begin_timer = millis();
        temp1 = true;
      } else if ((millis() - begin_timer) >= time_out) {
        randomInit();
        access_BSB = true;
        myDFPlayer.playLargeFolder(3, 1);
        delay(2000);
      }
    }
    if ((digitalRead(btnP1) == LOW && digitalRead(btnP2) == LOW) && access_BSB == true) { //ACCES OPTION
      play_Music = false;
      if (temp1 == false) {
        begin_timer = millis();
        temp1 = true;
      }
      if ((millis() > (begin_timer + 3000)) && (millis() < (begin_timer + 6000))) {
        if (temp2 == false) {
          temp2 = true;
          menu_Vol = true;
          myDFPlayer.playLargeFolder(3, 3);
        }
      }
      if ((millis() > (begin_timer + 6000)) && ((millis() - begin_timer) < time_out)) {
        if (temp3 == false) {
          temp3 = true;
          menu_Vol = false;
          myDFPlayer.playLargeFolder(3, 4);
        }
      }
      if ((millis() - begin_timer) > time_out) {
        access_BSB = false;
        if (temp4 == false) {
          temp4 = true;
          myDFPlayer.playLargeFolder(3, 2);
          delay(3000);
        }
      }
    }
  }

  if ((digitalRead(btnP1) == HIGH && digitalRead(btnP2) == HIGH) && menu_Vol == true) { //ACCESS MENU VOLUME
    timer_init();
    menu_general = false;
    access_BSB = false;
    access_Vol = true;
  } // menu_Vol

  if (access_Vol == true) { //ACCES PARAMETRE VOLUME
    if ((digitalRead(btnP1) == LOW) && (vol_BSB > 0)) {
      timer_init();
      vol_BSB = vol_BSB - 3;
      myDFPlayer.volume(vol_BSB);
      myDFPlayer.playLargeFolder(3, 5);
      delay(666);
    }
    if ((digitalRead(btnP2) == LOW) && (vol_BSB < 30)) {
      timer_init();
      vol_BSB = vol_BSB + 3;
      myDFPlayer.volume(vol_BSB);
      myDFPlayer.playLargeFolder(3, 5);
      delay(666);
    }
    if ((millis() > (begin_timer + 4000)) && access_Vol == true) {
      access_Vol = false;
      menu_Vol = false;
      access_BSB = true;
      menu_general = true;
      myDFPlayer.playLargeFolder(3, 1);
      delay(1500);
    }
  }

  //SECTION BARTOP SUPER BASH

  if ((digitalRead(btnP1) == LOW || digitalRead(btnP2) == LOW) && access_BSB == true && play_Music == true) {
    delay(42);

    start = random(1, varBonus);

    if (start != 1) { //PLAY DEFAULT MP3

      if (compteur1 == 0) {
        melange(tabDefault, folder01Max);
        while (tab1_swap == tabDefault[0] || tab1_swap == tabDefault[1]) {
          melange(tabDefault, folder01Max);
        }
      }
      myDFPlayer.playLargeFolder(1, tabDefault[compteur1]);
      compteur1++;
      if (compteur1 == folder01Max) {
        compteur1 = 0;
        tab1_swap = tabDefault[folder01Max - 1];
      }
      delay(3000);
      if ((digitalRead(btnP1) == LOW || digitalRead(btnP2) == LOW)) {
        play_Music = false;
      }else {
        delay(10000); // délai minimum après Default
      }

    } else if (start == 1)  { //PLAY BONUS MP3
      if (compteur2 == 0) {
        melange(tabBonus, folder02Max);
        while (tab2_swap == tabBonus[0] || tab2_swap == tabBonus[1]) {
          melange(tabBonus, folder02Max);
        }
      }
      myDFPlayer.playLargeFolder(2, tabBonus[compteur2]);
      compteur2++;
      if (compteur2 == folder02Max) {
        compteur2 = 0;
        tab2_swap = tabBonus[folder02Max - 1];
      }
      delay(3000);
      if ((digitalRead(btnP1) == LOW || digitalRead(btnP2) == LOW)) {
        play_Music = false;
      }else {
        delay(10000); // délai minimum après Bonus
      }
    }
  }
  if ((digitalRead(btnP1) == HIGH && digitalRead(btnP2) == HIGH) && menu_general == true && access_Vol == false) {
    temp1 = false;
    temp2 = false;
    temp3 = false;
    temp4 = false;
    variable_t = false;
    play_Music = true;
  }
}