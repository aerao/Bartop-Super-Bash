////////////////////////////////////////////////////
//                                                //
//    BARTOP SUPER BASH                           //
//    v1.0 (10/03/2019)                           //
//    aerao                                       //
//    https://github.com/aerao/Bartop-Super-Bash  //
//                                                //
///////////                           //////////////
//            - VERSION 3 BOUTONS -               //
////////////////////////////////////////////////////

#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

// ACCESS
const byte btnP1 = 2; // D2 Arduino
const byte btnP2 = 3; // D3 Arduino
const byte Hotkey = 4; // D7 Arduino
unsigned long begin_timer;
unsigned long begin_timer2;
unsigned int vol_BSB = 24; // volume (0-30)
const int time_out = 10000;
bool swap1 = false;
bool swap2 = false;
bool swap3 = false;
bool swap4 = false;
bool swap5 = false;
bool stop_BSB = false;
bool timerT1 = false;
bool timerT2 = false;
bool variable_T = false;
bool menu_Vol = false;
bool param_Vol = false;
bool menu_Bash = false;
bool param_Bash = false;
bool bash_onoff = true;
bool menu_general = true;
bool menu_secondaire = false;
bool play_Music = false;
bool access_BSB = false;

// VARIABLES
byte start;
byte start_init = 1;
byte varBonus;
byte folder01Max;
byte folder02Max;
byte compteur1 = 0;
byte compteur2 = 0;
byte tabDefault[80];
byte tabBonus[20];
byte tab1_swap = 1;
byte tab2_swap = 1;
byte bonusMP3 = 25; // en %

void setup () {
  mySoftwareSerial.begin(9600);
  Serial.begin(9600);

  pinMode(btnP1, INPUT_PULLUP);
  pinMode(btnP2, INPUT_PULLUP);
  pinMode(Hotkey, INPUT_PULLUP);
  myDFPlayer.begin(mySoftwareSerial);
  myDFPlayer.setTimeOut(500);
  myDFPlayer.volume(vol_BSB);
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
  varBonus = ((100 / bonusMP3) + 1);
  folder01Max = myDFPlayer.readFileCountsInFolder(1);
  folder02Max = myDFPlayer.readFileCountsInFolder(2);
  delay(42);

  for (int i = 0; i < folder01Max; i++) {
    tabDefault[i] = i + 1;
  }
  for (int i = 0; i < folder02Max; i++) {
    tabBonus[i] = i + 1;
  }

  Serial.println("READY...");
}
void timer_init() {
  if (digitalRead(btnP1) == HIGH && digitalRead(btnP2) == HIGH) {
    if (variable_T == false) {
      variable_T = true;
      begin_timer = millis();
    }
  } else {
    variable_T = false;
    if (variable_T == false) {
      variable_T = true;
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

  //ACCES MENU GENERAL
  if (menu_general == true) {
    if ((digitalRead(Hotkey) == LOW && digitalRead(btnP1) == HIGH && digitalRead(btnP2) == LOW) && access_BSB == false) {
      if (swap1 == false) {
        begin_timer = millis();
        swap1 = true;
        Serial.println("Activation [BSB] en cours...");
      }
      else if ((millis() - begin_timer) >= time_out) {
        randomInit();
        access_BSB = true;
        menu_secondaire = true;
        Serial.println("BSB => ACTIVÉ");
        myDFPlayer.playLargeFolder(3, 1);
        delay(2000);
      }
    }
    if ((digitalRead(Hotkey) == LOW && digitalRead(btnP1) == HIGH && digitalRead(btnP2) == LOW) && access_BSB == true) {
      stop_BSB = true;
      play_Music = false;
      if (timerT1 == false) {
        timerT1 = true;
        begin_timer = millis();
        Serial.println("Désactivation [BSB] en cours...");
      }
      if ((millis() - begin_timer) < 8000) {
        begin_timer2 = millis();
        if (swap5 == false) {
          swap5 = true;
          Serial.println("[Réinitialisation] begin_timer2");
        }
        //delay(666);
      }
      if ((millis() - begin_timer) > 8000) {
        access_BSB = false;
        menu_secondaire = false;
        if (swap1 == false) {
          swap1 = true;
          Serial.println("[BSB] => DÉSACTIVÉ");
          myDFPlayer.playLargeFolder(3, 2);
          delay(3000);
        }
      }
    }
  }
  if (menu_secondaire == true) { // MENU SECONDAIRE
    if (digitalRead(Hotkey) == HIGH && (digitalRead(btnP1) == HIGH || digitalRead(btnP2) == HIGH) && (stop_BSB == true)) {
      Serial.println("[stop_BSB] = false (Évite la lecture mp3 au relachement des boutons");
      delay(1000);
      stop_BSB = false;
      //menu_general == true;
    }
    if ((digitalRead(Hotkey) == LOW && digitalRead(btnP1) == HIGH && digitalRead(btnP2) == HIGH) && access_BSB == true) {
      play_Music = false;
      if (timerT2 == false) {
        timerT2 = true;
        begin_timer2 = millis();
        Serial.println("Accès aux paramètres en cours...");
      }
      if ((millis() > (begin_timer2 + 3000)) && (millis() < (begin_timer2 + 6000))) {
        if (swap2 == false) {
          swap2 = true;
          menu_Vol = true;
          Serial.println("Paramètrage [Volume] ?");
          myDFPlayer.playLargeFolder(3, 3);
        }
      }
      if ((millis() > (begin_timer2 + 6000)) && (millis() < (begin_timer2 + 9000))) {
        if (swap3 == false) {
          swap3 = true;
          Serial.println("Paramètrage [BASH] ?");
          menu_Vol = false;
          menu_Bash = true;
          myDFPlayer.playLargeFolder(3, 3);
        }
      }
      if ((millis() - begin_timer2) > 9000) {
        if (swap4 == false) {
          swap4 = true;
          menu_Bash = false;
          Serial.println("Retour au BASH");
          myDFPlayer.playLargeFolder(3, 4);
        }
      }

    }
    //ACCESS MENU VOLUME
    if (digitalRead(Hotkey) == HIGH && menu_Vol == true) {
      timer_init();
      menu_general = false;
      access_BSB = false;
      param_Vol = true;


      if (param_Vol == true) { //ACCES PARAMETRE VOLUME
        if ((digitalRead(btnP1) == LOW) && (vol_BSB > 0)) {
          timer_init();
          vol_BSB = vol_BSB - 3;
          myDFPlayer.volume(vol_BSB);
          myDFPlayer.playLargeFolder(3, 5);
          Serial.print(vol_BSB);
          Serial.println("/30 || Volume --");
          delay(666);
        }
        if ((digitalRead(btnP2) == LOW) && (vol_BSB < 30)) {
          timer_init();
          vol_BSB = vol_BSB + 3;
          myDFPlayer.volume(vol_BSB);
          myDFPlayer.playLargeFolder(3, 5);
          Serial.print(vol_BSB);
          Serial.println("/30 || Volume ++");
          delay(666);
        }
        if ((millis() > (begin_timer + 4000)) && param_Vol == true) {
          timer_init();
          menu_Vol = false;
          access_BSB = true;
          menu_general = true;
          myDFPlayer.playLargeFolder(3, 1);
          Serial.println("Sortie du menu [Volume]");
          delay(1500);
        }
      }
    }
    //ACCESS MENU BASH
    if (digitalRead(Hotkey) == HIGH && menu_Bash == true) {
      timer_init();
      menu_general = false;
      access_BSB = false;
      param_Bash = true;

      if (param_Bash == true) { //ACCES PARAMETRE BASH
        if (digitalRead(btnP1) == LOW || digitalRead(btnP2) == LOW) {
          timer_init();
          if (bash_onoff == true) {
            bash_onoff = false;
            start_init = 2;
            Serial.print("BASH [off] = ");
            Serial.println(bash_onoff);
            delay(666);
          }
          else {
            bash_onoff = true;
            start_init = 1;
            Serial.print("BASH [on] = ");
            Serial.println(bash_onoff);
            delay(666);
          }
        }
        if ((millis() > (begin_timer + 4000)) && param_Bash == true) {
          menu_Bash = false;
          access_BSB = true;
          menu_general = true;
          myDFPlayer.playLargeFolder(3, 1);
          Serial.println("Sortie du menu [Bash]");
          delay(1500);
        }
      }
    }

  }



  //SECTION BARTOP SUPER BASH

  if ((digitalRead(btnP1) == LOW || digitalRead(btnP2) == LOW) && digitalRead(Hotkey) == HIGH && access_BSB == true && play_Music == true && stop_BSB == false) {
    delay(42);

    start = random(start_init, varBonus);

    if (start != 1) { //PLAY DEFAULT MP3

      if (compteur1 == 0) {
        melange(tabDefault, folder01Max);
        while (tab1_swap == tabDefault[0] || tab1_swap == tabDefault[1]) {
          melange(tabDefault, folder01Max);
        }
      }
      Serial.print("Lecture MP3 Default du fichier ");
      Serial.print(tabDefault[compteur1]);
      Serial.println(".mp3 du dossier [folder01]");
      myDFPlayer.playLargeFolder(1, tabDefault[compteur1]);
      compteur1++;
      if (compteur1 == folder01Max) {
        compteur1 = 0;
        tab1_swap = tabDefault[folder01Max - 1];
      }
     for (int c=0; c < 12000; c++) {
        delay(1); // délai minimum après Default
        if (digitalRead(Hotkey) == LOW ) {
          break;
        }
      }
    }
    else if (start == 1)  { //PLAY BONUS MP3
      if (compteur2 == 0) {
        melange(tabBonus, folder02Max);
        while (tab2_swap == tabBonus[0] || tab2_swap == tabBonus[1]) {
          melange(tabBonus, folder02Max);
        }
      }
      Serial.print("Lecture MP3 Bonus du fichier ");
      Serial.print(tabBonus[compteur2]);
      Serial.println(".mp3 du dossier [folder02]");
      myDFPlayer.playLargeFolder(2, tabBonus[compteur2]);
      compteur2++;
      if (compteur2 == folder02Max) {
        compteur2 = 0;
        tab2_swap = tabBonus[folder02Max - 1];
      }
      for (int c=0; c < 12000; c++) {
        delay(1);
        if (digitalRead(Hotkey) == LOW ) {
          break;
        }
      }
    }
  }

  if (digitalRead(Hotkey) == HIGH && menu_general == true && menu_Vol == false) {
    swap1 = false;
    swap2 = false;
    swap3 = false;
    swap4 = false;
    swap5 = false;
    variable_T = false;
    timerT1 = false;
    timerT2 = false;
    play_Music = true;
    //access_BSB = true;
  }
}
//}