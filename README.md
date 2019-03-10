
# BARTOP SUPER BASH
Bashing de sons entre joueurs sur Bartop

## K�sako ?
Lance un son al�atoire pour "basher" son adversaire, quand on appuie sur un bouton type arcade.

L'id�e est de lancer manuellement un "Bash", un pique, une casse... � votre adversaire quand vous l'avez battu � un combat, comme Street Fighter par exemple (adversaire qui devrait normalement �tre � cot� de vous, �tant donn� que vous jouez avec lui sur un Bartop).

Certains sons, plus "cassant", peuvent aussi �tre lanc�s (plus rare).

### Principe
Appuyer sur l'un des 2 boutons de votre Bartop d�clanche un [BASH] � votre adversaire/ami


### D�veloppement
* Version 2 boutons arcade (voir README_2B.MD)
* Version 3 boutons arcade (recommand�) =>  2 boutons arcade + 1 bouton "Hotkey" (voir README_3B.MD)
* Cod� pour l'Arduino/DFPlayer Mini, avec la librairie [DFRobotDFPlayerMini](https://github.com/DFRobot/DFRobotDFPlayerMini)

### Pr�requis et Mat�riel
- Avoir un Bartop (ou Borne d'arcade)
- 2 ou 3 boutons arcade de libre
- Arduino (nano/uno)
- DFPlayer Mini
- R�cup�rer la librairie [DFRobotDFPlayerMini](https://github.com/DFRobot/DFRobotDFPlayerMini) pour la phase de compilation de l'Arduino
- SDCard
- Sons au format MP3 (entre 1s et 10s max recommand�)

Dans l'id�al, le couple Arduino/Dfplayer doivent �tre reli� � un ampli/HP (ind�pendant de l'ampli/HP g�n�ral de votre Bartop)

### Montage (Arduino + DFPlayer Mini + Ampli + 1xHP )
Se r�f�rer aux exemples de la page suivante selon votre convenance :
http://www.belajarduino.com/2016/10/arduinop.html

*note : son de meilleur qualit� en **mono** avec la configuration DF Player mini + Module Ampli/Ampli Mono (0.5-25watt)*


## Version
v. 1.0 - Projet initial - 2019-03-10 *(version perfectible, toutes remarques seront �videmment les bienvenues)*

## Autheur
* **AERAO** - *100% Homemade* - [aerao](https://github.com/aerao)
