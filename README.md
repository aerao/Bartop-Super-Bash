
# BARTOP SUPER BASH
Bashing de sons entre joueurs sur Bartop

## Késako ?
Lance un son aléatoire pour "basher" son adversaire, quand on appuie sur un bouton type arcade.

L'idée est de lancer manuellement un "Bash", un pique, une casse... à votre adversaire quand vous l'avez battu à un combat, comme Street Fighter par exemple (adversaire qui devrait normalement être à coté de vous, étant donné que vous jouez avec lui sur un Bartop).

Dans mon programme, certains sons, plus "Vulgaire", peuvent aussi être lancés (ce que j'ai appelé *Bonus*).

### Principe
Vous avez un Bartop et vous avez/voulez rajouter 1 bouton de chaque coté + 1 autre (où bon vous semble) qui servira de "Hotkey" (pour démarrer le programme qui sera installer sur votre carte Arduino/Nano), à ne pas confondre avec le hotkey de Recalbox/Batocera.

Appuyer sur l'un des 2 boutons de votre Bartop déclanche un [BASH] à votre adversaire/ami


### Développement
* Version 3 boutons de type Arcade (relié à l'Arduino) => 2 boutons (à mettre sur chaque coté de votre Borne + 1 bouton type "Hotkey"
* Codé pour l'Arduino/Nano/DFPlayer Mini, avec la librairie [DFRobotDFPlayerMini](https://www.arduino.cc/reference/en/libraries/dfrobotdfplayermini/)

### Prérequis et Matériel
- Avoir un Bartop (ou Borne d'arcade)
- 2 ou 3 boutons arcade à rajouter ou utilsé si déjà mis en place mais inutilisé.
- Arduino (nano/uno)
- DFPlayer Mini
- SDCard
- Sons au format MP3 (entre 1s et 10s max recommandé)

Dans l'idéal, le couple Arduino/Dfplayer doivent être relié à un ampli/HP (indépendant de l'ampli/HP général de votre Bartop)

### Installation
* Il faudra avant tout bien s'inspirer du shema de montage (**=> voir plus bas Section Montage (Arduino + DFPlayer Mini + Ampli + 1xHP**)
* Récupérer la librairie [DFRobotDFPlayerMini] v.1.05 (https://www.arduino.cc/reference/en/libraries/dfrobotdfplayermini/) ou (https://mega.nz/file/0MEHXSCB#Ll_3Q3HHRbwC-IE89Ay4Hl84D3Fg_eX5i_0HHzBq6_Q)
* Installer le dossier *DFRobotDFPlayerMini-1.0.5* dans votre dossier par defaut. exemple *C:\Program Files (x86)\Arduino\libraries*
* Installer (si par la suite la connection/le teléversement ne fonctionne pas) les drivers (https://mega.nz/folder/EZFxgSqL#_8i05frTEYTZpttdJB3Csw)
* Branchez l'Arduino à votre ordinateur, installez le programme [Arduino IDE](https://www.arduino.cc/en/Main/Software), et ouvrez le [croquis](https://github.com/aerao/Bartop-Super-Bash/blob/master/Bartop-Super-Bash_3B.ino).
* Lancer l'Arduino/Nano, et veiller bien à selectionner (Type de Carte : **Arduino Nano**) et (Processeur : **ATmega** ou **ATemega328P(oldBootloader)** et le Port. Il est possible que **"Récuperer les informations de la carte"** ne fonctionne pas, ce n'est pas grave car le téléversement doit fonctionner.
- Ouvrer le fichier .ino et téléverser
* Mettre les sons sur votre carte SD (**voir plus bas la section Pack Sons**)

### Fonctionnement
Maintenir appuyer les 2 boutons pendant 4s pour activer le [BASH] (Maintenir de nouveau les 2 boutons pendant 4s, désactive le [BASH])

Appuyer sur bouton 1 ou bouton 2 
* lance un son aléatoire(default) ou (Bonus) des dossiers SD:/01/ || SD:/02/ avec un timer de **6s** (configurable aux lignes 346 et 378)
```
for (int c = 0; c < 6000; c++) { // en ms, délai minimum avant de pouvoir relancer un son (Default)
```
```
for (int c = 0; c < 6000; c++) { // en ms, délai minimum avant de pouvoir relancer un son (Bonus)
```

* Le son aléatoire(Bonus) a une chance de **25%** d'être lancé (configurable à la ligne 60)
```
byte bonusMP3 = 25; // en %
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

*mdp: bartop*

- Sur votre carte SD (formaté fat32), coller les 3 dossiers audios (/01,/02,/03) (https://mega.nz/file/YdEFVAYZ#aOuQaImao8KbG-bVmNwLLmXrGXEK0z4tTq0wvdmiBzw )
- Vous pouvez ajouter/enlever des fichiers des dossiers /01,/02 (max 80 comme expliquer précédemment, mais c'(est modifiable).
- Attention, si vous rajouter des son MP3, il faut les mettre au format 0001.mp3 0002.mp3 ...)


## Divers
Schéma du PCB en pdf (D1, D2, D3, D4...) correspond aux nombres de boutons que voulez connecter.

#**IMPORTANT !**
- Dans le fichier .ino
``` 
const byte btnP1 = 4; // D2 Arduino Nano
const byte btnP2 = 3; // D3 Arduino Nano
const byte Hotkey = 2; // D4 Arduino Nano
```
les valeurs (4,3,2) peuvent etre différent selon là ou vous brancher vos boutons sur l'Arduino (D2,D3,D4...).

Dans mon cas la broche D4 de l'Arduino correspondait à la valeur 2

### Montage (Arduino + DFPlayer Mini + Ampli + 1xHP)
Se référer aux exemples de la page suivante selon votre convenance :
- https://mega.nz/file/MI100BZZ#fO6gkXS1gv7UxtjZW72Olm4Yiv1-k_3HTWc0UjcRUt4 (anciennement http://www.belajarduino.com/2016/10/arduinop.html qui ne fonctionne plus. J'ai récupéré le contenu via web archive et j'ai compressé la page html dans le zip (que vous devez décompresser pour lire la page), c'est pas le plus optimisé mais ca reste fonctionnel. (fonctionne sous firefox, chrome, opera)

*note : son de meilleur qualité en **mono** avec la configuration DF Player mini + Module Ampli/Ampli Mono (0.5-25watt)*


## Version
v. 1.1 - Mise à jour - 2021-11-11 (Maj du code et optimisations)

v. 1.0 - Projet initial - 2019-03-10 *(version perfectible, toutes remarques seront évidemment les bienvenues)*

## Autheur
* **AERAO** - *100% Homemade* - [aerao](https://github.com/aerao)
