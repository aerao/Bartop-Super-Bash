
# BARTOP SUPER BASH
Bashing de sons entre joueurs sur Bartop

## Késako ?
Lance un son aléatoire pour "basher" son adversaire, quand on appuie sur un bouton type arcade.

L'idée est de lancer manuellement un "Bash", un pique, une casse... à votre adversaire quand vous l'avez battu à un combat, comme Street Fighter par exemple (adversaire qui devrait normalement être à coté de vous, étant donné que vous jouez avec lui sur un Bartop).

Certains sons, plus "cassant", peuvent aussi être lancés (plus rare).

### Principe
Appuyer sur l'un des 2 boutons de votre Bartop déclanche un [BASH] à votre adversaire/ami


### Développement
* Version 3 boutons de type Arcade (relié à l'Arduino) => 2 boutons (à mettre sur chaque coté de votre Borne + 1 bouton type "Hotkey" (voir README_3B.MD)
* Codé pour l'Arduino/Nano/DFPlayer Mini, avec la librairie [DFRobotDFPlayerMini](https://www.arduino.cc/reference/en/libraries/dfrobotdfplayermini/)

### Prérequis et Matériel
- Avoir un Bartop (ou Borne d'arcade)
- 2 ou 3 boutons arcade de libre
- Arduino (nano/uno)
- DFPlayer Mini
- SDCard
- Sons au format MP3 (entre 1s et 10s max recommandé)

Dans l'idéal, le couple Arduino/Dfplayer doivent être relié à un ampli/HP (indépendant de l'ampli/HP général de votre Bartop)

### Installation
- Sur votre carte SD (formaté fat32), coller les 3 dossiers audios (01,02,03) sur votre arduino/Nano (https://mega.nz/file/YdEFVAYZ#aOuQaImao8KbG-bVmNwLLmXrGXEK0z4tTq0wvdmiBzw mdp:**bartop**) - Vous pouvez ajouter/enlever des fichiers des dossiers 01,02 à votre convenance.
- Récupérer la librairie [DFRobotDFPlayerMini] v.1.05 (https://www.arduino.cc/reference/en/libraries/dfrobotdfplayermini/) ou (https://mega.nz/file/0MEHXSCB#Ll_3Q3HHRbwC-IE89Ay4Hl84D3Fg_eX5i_0HHzBq6_Q)
- installer le dossier *librairie* dans votre dossier par defaut. exemple *C:\Program Files (x86)\Arduino\libraries*
- installer (la connection ne fonctionne pas) les drivers (https://mega.nz/folder/EZFxgSqL#_8i05frTEYTZpttdJB3Csw)
- Lancer l'Arduino/Nano, et veiller bien à selectionner (Type de Carte : Arduino Nano) et (Processeur : ATmega / ATemega328P(oldBootloader) et le Port.
- il est possible que **"Récuperer les informations de la carte"** ne fonctionne pas, ce n'est pas grave car le téléversement doit fonctionner.
- Ouvrer le fichier .ino et téléverser


### Montage (Arduino + DFPlayer Mini + Ampli + 1xHP )
Se référer aux exemples de la page suivante selon votre convenance :
- https://mega.nz/file/MI100BZZ#fO6gkXS1gv7UxtjZW72Olm4Yiv1-k_3HTWc0UjcRUt4 (anciennement http://www.belajarduino.com/2016/10/arduinop.html qui ne fonctionne plus. J'ai récupéré le contenu via web archive et j'ai compressé la page html dans le zip (que vous devez décompresser pour lire la page), c'est pas le plus optimisé mais ca reste fonctionnel. (fonctionne sous firefox, chrome, opera)

*note : son de meilleur qualité en **mono** avec la configuration DF Player mini + Module Ampli/Ampli Mono (0.5-25watt)*


## Version
v. 1.1 - Mise à jour du code et optimisation
v. 1.0 - Projet initial - 2019-03-10 *(version perfectible, toutes remarques seront évidemment les bienvenues)*

## Autheur
* **AERAO** - *100% Homemade* - [aerao](https://github.com/aerao)
