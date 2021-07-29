# Shoot Them Up !

Projet de 1 mois réalisé en C avec la librairie SDL2 pour l'UE Programmation et langage C de la licence 2 d'informatique de l'UPJV

## Explications

"Shoot Them Up !" est un jeu de type "Shoot 'em up" spatial dans lequel le joueur doit détruire des vagues de vaisseaux spatiales ennemis de plus en plus fort au fur et à mesure des niveaux.
Le joueur peut deplacer son vaisseau avec les touches Q et D.
Les vaisseaux perdent de la vie lorsqu'ils sont touchés par des balles ou des rockets, mais le vaisseau du joueur perd aussi de la vie lorsque l'ennemi sort de son champ de vision sans avoir été détruit.
Le joueur perd une partie lorsque son vaisseau n'a plus de vie et retournera donc au niveau 1.
Chaque partie lui permet de gagner de l'argent en jeu. Il peut utiliser cet argent afin d'acheter des nouvelles pièces de vaisseaux pour améliorer le sien, et donc réussir plus de niveaux par la suite.

Il existe 7 types de pièces de vaisseaux déclinés eux-mêmes en 5 niveaux d'amélioration. Toutes les pièces sont interchangeables et compatibles entre elles, les possibilités de personnalisation sont donc immenses.
Le corps du vaisseau est la pièce qui influe le plus sur les points de vie totale du vaisseau.
Le réacteur principal et ceux secondaires influent sur la vitesse du vaisseau.
L'arme principale tire en ligne droite, inflige des dégâts moyens et se déclenche en appuyant sur (ou en laissant appuyé) la barre espace.
L'arme secondaire tire deux rockets en ligne droite, inflige de gros dégâts de zone (peut donc toucher plusieurs ennemis à la fois), se déclenche en appuyant sur la touche K, mais nécessite un grand temps de chargement avant d'être de nouveau disponible.
La tourelle tire automatiquement vers l'ennemi le plus proche, en s'orientant vers lui plus ou moins rapidement selon son niveau d'amélioration.
Le bouclier permet d'être invincible pendant un certain temps, ou jusqu'à avoir encaissé un certain nombre de dégâts. Il nécessite un grand temps de chargement avant d'être de nouveau disponible.

Il existe 7 types d'ennemi possédant des caractéristiques et des équipements différents.
L'ennemi classique ne possède pas de particularité.
Le Tank est beaucoup plus lent, mais possède beaucoup plus de points de vie.
Le Sniper tire rarement, mais fait beaucoup de dégâts. Cependant, il n'a pas beaucoup de points de vie. 
L'Artificier tire de nombreuses rockets puissantes.
La Tourelle possède une tourelle de haut niveau qui est donc puissante et rapide.
Le Soldat apparaît en groupe avec d'autres vaisseaux Soldats. Cependant, ils n'ont pas beaucoup de vie, et ne font pas beaucoup de dégâts.
L'Éclaireur va très vite.

## Démonstration

https://user-images.githubusercontent.com/38865028/127541329-2ffa0c53-dd7f-46e9-8a5b-d87b1fe3df18.mov
