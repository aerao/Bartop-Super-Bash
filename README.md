
# BARTOP SUPER BASH
Bashing de sons entre joueurs sur Bartop

## K�sako ?
Lance un son al�atoire pour "basher" son adversaire, quand on appuie sur un bouton type arcade.

L'id�e est de lancer manuellement un "Bash", un pique, une casse... � votre adversaire quand vous l'avez battu � un combat, comme Street Fighter par exemple (adversaire qui devrait normalement �tre � cot� de vous, �tant donn� que vous jouez avec lui sur un Bartop).

Certains sons, plus "cassant", peuvent aussi �tre lanc�s (plus rare).

### D�veloppement
* Version 2 boutons arcade
* Cod� pour l'Arduino/DFPlayer Mini, avec la librairie [DFRobotDFPlayerMini](https://github.com/DFRobot/DFRobotDFPlayerMini)

### Pr�requis et Mat�riel
- Avoir un Bartop (ou Borne d'arcade)
- 2 boutons arcade de libre (3 � 4 boutons dans un futur projet)
- Arduino (nano/uno)
- DFPlayer Mini
- R�cup�rer la librairie [DFRobotDFPlayerMini](https://github.com/DFRobot/DFRobotDFPlayerMini) pour la compilation de l'Arduino
- SDCard
- Sons au format MP3 (entre 1s et 10s recommand�)

Dans l'id�al, le couple Arduino/Dfplayer doivent �tre reli� � un ampli/HP (ind�pendant de l'ampli/HP g�n�ral de votre Bartop)

### Montage (Arduino + DFPlayer Mini + Ampli + HP )
Se r�f�rer aux exemples de la page suivante selon votre convenance :
http://www.belajarduino.com/2016/10/arduinop.html

*note : son de meilleur qualit� en **mono** avec la configuration DF Player mini + Module Ampli LM386 (MONO 0.5-25watt)*

### Installation
* Branchez l'Arduino � votre ordinateur, installez le programme [Arduino IDE](https://www.arduino.cc/en/Main/Software), et t�l�versez le [croquis](https://github.com/aerao/Bartop-Super-Bash/blob/master/Bartop_Super_Bash.ino).
* Mettre les sons classiques(default), sur la carte SD, dans le dossier SD:/01/ (mettre au format 0001.mp3 0002.mp3 ...)
* Mettre les sons plus cassant(Bonus), sur la carte SD, dans le dossier SD:/02/ (mettre au format 0001.mp3 0002.mp3 ...)
* R�cuper et mettre le pack de son pour le [BASH], sur la carte SD, dans le dossier SD:/03/ (mettre au format 0001.mp3 0002.mp3 ...)

### Fonctionnement
Maintenir appuyer les 2 boutons pendant 10s pour activer le [BASH] (Maintenir de nouveau les 2 boutons pendant 10s, d�sactive le [BASH])

Appuyer sur bouton 1 ou bouton 2 
* lance un son al�atoire(default) ou (Bonus) des dossiers SD:/01/ || SD:/02/ avec un timer de **13s** (10s + 3s), (configurable)
```
delay(10000); // en ms, d�lai minimum apr�s Default
```
```
delay(10000); // en ms, d�lai minimum apr�s Bonus
```

* Le son al�atoire(Bonus) a une chance de **5%** d'�tre lanc� (configurable)
```
byte bonusMP3 = 5; // en %
```
Par d�faut, le nombre de MP3(default) qui peuvent �tre pris en charge est de **80**, et le nombre de MP3(Bonus) est de **20** (augmenter leur valeur si besoin).
```
byte tabDefault[80]; // valeur max 255
byte tabBonus[20]; // valeur max 255
```

### Acc�s au menu du volume
Permet d'�viter d'ouvrir le Bartop pour modifier le volume du [BASH], sur l'ampli si celui n'est pas tr�s accessible.

Dans le [BASH], maintenir appuyer les 2 boutons simultan�ment.

=> entre 3 et 6s, un son va s'activer[*]

=> Rel�cher les 2 boutons, vous avez activer le menu [volume]
* Appuyer bouton 1 pour **diminuer** le volume
* Appuyer bouton 2 pour **augmenter** le volume

Sorti du [volume] automatique et retour au [BASH], 4s apr�s avoir appuy� sur l'un des boutons (se r�initialise � chaque appui)

[*]*note: au del� des 6s, un nouveau son se lance et retour automatique au [BASH]*

### Pack Sons
C'est pas parfait, mais j'ai essay� au mieux de r�cup�rer et retravailler pas mal de sons pour mon Bartop personnel.

Quelques sons : https://mega.nz/#!JZMnGSJI!q-EaCZOU7YUW0rML0SYtVur5ViIq8yc9RCoseJDsXSg

*mdp: bartop2019*

## Version
v. 1.0 - Projet initial - 2019-03-05 *(version perfectible, tous conseils seront �videmment les bienvenus)*

## Autheur
* **AERAO** - *100% Homemade* - [aerao](https://github.com/aerao)
