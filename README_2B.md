
# BARTOP SUPER BASH
Bashing de sons entre joueurs sur Bartop

## Késako ?
Lance un son aléatoire pour "basher" son adversaire, quand on appuie sur un bouton type arcade.

L'idée est de lancer manuellement un "Bash", un pique, une casse... à votre adversaire quand vous l'avez battu à un combat, comme Street Fighter par exemple (adversaire qui devrait normalement être à coté de vous, étant donné que vous jouez avec lui sur un Bartop).

Certains sons, plus "cassant", peuvent aussi être lancés (plus rare).

### Développement
* Version 2 boutons arcade
* Codé pour l'Arduino/DFPlayer Mini, avec la librairie [DFRobotDFPlayerMini](https://github.com/DFRobot/DFRobotDFPlayerMini)

### Prérequis et Matériel
- Avoir un Bartop (ou Borne d'arcade)
- 2 boutons arcade de libre
- Arduino (nano/uno)
- DFPlayer Mini
- Récupérer la librairie [DFRobotDFPlayerMini](https://github.com/DFRobot/DFRobotDFPlayerMini) pour la phase de compilation de l'Arduino
- SDCard
- Sons au format MP3 (entre 1s et 10s max recommandé)

Dans l'idéal, le couple Arduino/Dfplayer doivent être relié à un ampli/HP (indépendant de l'ampli/HP général de votre Bartop)

### Montage (Arduino + DFPlayer Mini + Ampli + 1xHP )
Se référer aux exemples de la page suivante selon votre convenance :
http://www.belajarduino.com/2016/10/arduinop.html

*note : son de meilleur qualité en **mono** avec la configuration DF Player mini + Module Ampli/Ampli Mono (0.5-25watt)*

### Installation
* Branchez l'Arduino à votre ordinateur, installez le programme [Arduino IDE](https://www.arduino.cc/en/Main/Software), et téléversez le [croquis](https://github.com/aerao/Bartop-Super-Bash/blob/master/Bartop_Super_Bash.ino).
* Mettre les sons classiques(default), sur la carte SD, dans le dossier SD:/01/ (mettre au format 0001.mp3 0002.mp3 ...)
* Mettre les sons plus cassant(Bonus), sur la carte SD, dans le dossier SD:/02/ (mettre au format 0001.mp3 0002.mp3 ...)
* Récuper et mettre le pack de son pour le [BASH], sur la carte SD, dans le dossier SD:/03/ (mettre au format 0001.mp3 0002.mp3 ...)

### Fonctionnement
Maintenir appuyer les 2 boutons pendant 10s pour activer le [BASH] (Maintenir de nouveau les 2 boutons pendant 10s, désactive le [BASH])

Appuyer sur bouton 1 ou bouton 2 
* lance un son aléatoire(default) ou (Bonus) des dossiers SD:/01/ || SD:/02/ avec un timer de **13s** (10s + 3s), (configurable)
```
delay(10000); // en ms, délai minimum après Default
```
```
delay(10000); // en ms, délai minimum après Bonus
```

* Le son aléatoire(Bonus) a une chance de **5%** d'être lancé (configurable)
```
byte bonusMP3 = 5; // en %
```
Par défaut, pour des raisons d'optimisation de mémoire de l'arduino (nano dans mon cas), le nombre maximum de MP3(default) qui peuvent être pris en charge est de **80**, et le nombre de MP3(Bonus) est de **20** (augmenter leur valeur si besoin).
```
byte tabDefault[80]; // valeur max 255
byte tabBonus[20]; // valeur max 255
```

### Accès au menu du volume
Permet d'éviter d'ouvrir le Bartop pour modifier le volume du [BASH], sur l'ampli si celui n'est pas très accessible.

Dans le [BASH], maintenir appuyer les 2 boutons simultanément.

=> un nouveau son va s'activer[*]

=> Relâcher les 2 boutons, vous avez activer le menu [volume], et désactivé le [bash] temporairement.
* Appuyer bouton 1 pour **diminuer** le volume
* Appuyer bouton 2 pour **augmenter** le volume

Sorti du [volume] automatique et retour au [BASH], 4s après avoir appuyé sur l'un des boutons (se réinitialise à chaque appui)

[*]*note: si vous continuez à maintenir simultanément les 2 boutons (3s de plus), un nouveau son se lance et retour automatique au [BASH]*

### Pack Sons
C'est pas parfait, mais j'ai essayé au mieux de récupérer et retravailler pas mal de sons pour mon Bartop personnel.

Quelques sons : https://mega.nz/#!JZMnGSJI!q-EaCZOU7YUW0rML0SYtVur5ViIq8yc9RCoseJDsXSg

*mdp: bartop2019*

## Divers
Schéma du PCB en pdf (D1, D2, D3, D4...) correspond aux nombres de boutons que voulez connecter.

https://mega.nz/file/8EUkRQIQ#D7R4zqDv-dSiYQu1PIAbhOB9P6yXC0C9slNWDV7i9yo
PCB fait sur le site Easy EDA, qui permet ensuite de faire l'impression et l'envoi de celui ci, directement via leur site.

## Version
v. 1.0 - Projet initial - 2019-03-05 *(version perfectible, tous conseils seront évidemment les bienvenus)*

## Autheur
* **AERAO** - *100% Homemade* - [aerao](https://github.com/aerao)
