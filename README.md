
# BARTOP SUPER BASH
Bashing de sons entre joueurs sur Bartop

## Késako ?
Lance un son aléatoire pour "basher" son adversaire, quand on appuie sur un bouton type arcade.

L'idée est de lancer manuellement un "Bash", un pique, une casse... à votre adversaire quand vous l'avez battu à un combat, comme Street Fighter par exemple (adversaire qui devrait normalement être à coté de vous, étant donné que vous jouez avec lui sur un Bartop).

Certains sons, plus "cassant", peuvent aussi être lancés (plus rare).

### Principe
Appuyer sur l'un des 2 boutons de votre Bartop déclanche un [BASH] à votre adversaire/ami


### Développement
* Version 2 boutons arcade (voir README_2B.MD)
* Version 3 boutons arcade (recommandé) =>  2 boutons arcade + 1 bouton "Hotkey" (voir README_3B.MD)
* Codé pour l'Arduino/DFPlayer Mini, avec la librairie [DFRobotDFPlayerMini](https://github.com/DFRobot/DFRobotDFPlayerMini)

### Prérequis et Matériel
- Avoir un Bartop (ou Borne d'arcade)
- 2 ou 3 boutons arcade de libre
- Arduino (nano/uno)
- DFPlayer Mini
- Récupérer la librairie [DFRobotDFPlayerMini](https://github.com/DFRobot/DFRobotDFPlayerMini) pour la phase de compilation de l'Arduino
- SDCard
- Sons au format MP3 (entre 1s et 10s max recommandé)

Dans l'idéal, le couple Arduino/Dfplayer doivent être relié à un ampli/HP (indépendant de l'ampli/HP général de votre Bartop)

### Montage (Arduino + DFPlayer Mini + Ampli + 1xHP )
Se référer aux exemples de la page suivante selon votre convenance :
https://mega.nz/file/MI100BZZ#fO6gkXS1gv7UxtjZW72Olm4Yiv1-k_3HTWc0UjcRUt4 (anciennement http://www.belajarduino.com/2016/10/arduinop.html qui ne fonctionne plus), j'ai récupéré le contenu via web archive et j'ai compressé la page html dans le zip (que vous devez décompresser pour lire la page), c'est pas le plus optimisé mais ca reste fonctionnel.

*note : son de meilleur qualité en **mono** avec la configuration DF Player mini + Module Ampli/Ampli Mono (0.5-25watt)*


## Version
v. 1.0 - Projet initial - 2019-03-10 *(version perfectible, toutes remarques seront évidemment les bienvenues)*

## Autheur
* **AERAO** - *100% Homemade* - [aerao](https://github.com/aerao)
