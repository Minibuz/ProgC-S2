# Table des matières
1. [Présentation du Portfolio](#Présentation-du-portfolio)
2. [Préambule](#Préambule)
3. [Mes productions](#Mes-productions)
		1.  [TP9](#tp9)
		2.  [TP10](#tp10)
		3.  [TP12](#tp12)
		4.  [TP15](#tp15)
4. [Conclusion](#Conclusion)

# Présentation du portfolio
Bienvenue sur le portfolio de Buzelin Léo !
Ce portfolio est ici pour montrer ce qui a été réalisé au cours de ce semestre en programmation C.
Tous les travaux réalisés vont être présenté, les points ayant présenté des difficultés seront abordées et quelque exemple du code seront aussi présent afin d'agrémenter le tout.
Pour le portfolio du premier semestre, c'est sur ce [lien](https://github.com/Minibuz/ProgC/blob/master/Portefolio.pdf) !

# Préambule
Ce semestre aura été un semestre assez dur vis-à-vis de plusieurs choses.  
Commençons tout d’abord par indiqué que j’ai très travaillé le C en dehors des heures de cours, ce qui est dû au fait que dans notre formation, nous avons la chance d’avoir une autre matière principalement orientée autour du C qui est l’Algorithmie. De plus, j’ai préféré me concentrer sur faire peu de TP, mais comprendre jusqu’au bout de quoi il était question afin que même si ce ne sont que des TPS pour les cours, je puisse en tirer un enseignement, point sur lequel je reviendrai un peu plus tard. Je n’ai aussi pas eu le temps pour demander de review de mes projets à part certaines petites parties que ce soit en cours, ou lors des questions sur discord.

# Mes productions

Dans cette partie, le lecteur va pouvoir comprendre, voir et observer ce qui as été effectué ainsi que voir le fils de ma pensée lors des TPS et la façon qui m’as permis de résoudre les différents obstacles que j’ai pu rencontrer.

## [TP9](https://github.com/Minibuz/ProgC-S2/tree/main/TP9)

	Ce TP est le premier TP ou je me suis vraiment penché sur Malloc(sizeof(T)).

Au cours de ce TP, j’ai pu vraiment comprendre ce qu’était malloc en plus des différentes approches que j’ai pu avoir auparavant. De plus, l’utilisation de Valgrind m’as permis de comprendre les histoires de libération de mémoire.  
Valgrind m’a aussi été utile dans d’autres TPS afin d’un côté de vérifier la mémoire, mais aussi pour savoir d’où venez les problèmes avec *- -leak-check=full* et *- -track-origins=yes* .

Dans ce TP, j’ai décidé de faire les trois premiers exercices afin de bien comprendre malloc via l’allocation des char* pour créer les plus petites allocations possibles.
| Projet | Pts | I/0 | Type | Progr | Module | Compil | Récursion | Tableaux | Pointeurs | Structures | Allocation | Fichier | Bit à bit | Fct Pointer | Biblio |
| ------ | --- | --- | ---- | ----- | ------ | ------ | --------- | -------- | --------- | ---------- | ---------- | ------- | --------- | ----------- | ------ |
| TP9 | 10 | 1 | 1 | 1 | | 1 | | 2 | 1 | 1 | 2 | | | |
## [TP10](https://github.com/Minibuz/ProgC-S2/tree/main/TP10)

	Le TP 10 a été un TP assez compliqué.

D’un côté, le swap a été assez simple étant donné qu’il s’agissait simplement de bouger des éléments par éléments jusqu’à ce qu’il n’y est plus d’éléments.

De l’autre côté, cela a été plus compliqué. Tout d’abord, il a fallu allouer de la mémoire à chacune des cellules correspondantes à un mot et les remplir. Cette partie n’a pas été la plus dure grâce à Valgrind qui m’as permis de vérifier les fuites de mémoires. Ensuite, le vrai problème est arrivé, la fonction passée en argument. Au début, j’ai juste copié assez bêtement le code donné dans le TP sans comprendre et juste fait les fonctions de tri basique, par age et par nom, mais j’ai vite compris que cela ne fonctionnait pas. J’ai dû gérer les cas particuliers avec d’un côté une cellule vide ou un arbre vide. En rajoutant ces clauses, j’ai vu que plus rien ne fonctionnais comme voulu, c’est-à-dire, que la première version de ma fonction ordered_insertion() était une fonction récursive, mais cela ne marchais pas. J’ai pris la décision de recommencer la fonction de zéro en la passant en non récursive, simplement en ajoutant une boucle for et en faisant à chaque itération le test, et si jamais on devait ajouter l’élément à la fin de la liste, rajouter un cas toute à la fin pour traiter ce cas.
| Projet | Pts | I/0 | Type | Progr | Module | Compil | Récursion | Tableaux | Pointeurs | Structures | Allocation | Fichier | Bit à bit | Fct Pointer | Biblio |
| ------ | --- | --- | ---- | ----- | ------ | ------ | --------- | -------- | --------- | ---------- | ---------- | ------- | --------- | ----------- | ------ |
| TP10 | 11 | 1 | 1 | 1 | | 1 | 1 | | 2 | 1 | 1 | 1 | | |  |
## [TP12](https://github.com/Minibuz/ProgC-S2/tree/main/TP12)
Ce TP est le premier ou j'ai du m'y reprendre à plusieurs fois.
Tout d'abord, la première partie, un comptage naïf ou l'on rajoute simple le mot à la suite à chaque fois. Avec Valgrind, cela m'a permis de réussir à faire cet exercice sans trop de complexité.
Néanmoins, pour ce qui est de la deuxième partie, cela m'a posé beaucoup plus de problèmes.
> Il m'aura fallu trois essais avant de réussir à faire un résultat potable avec Valgrind 

Le premier soucis était plutôt simple à résoudre. La façon dont j'avais fait la première partie de ce TP ne fonctionnais pas de la façon voulue pour cette deuxième partie. C’est-à-dire que l'insertion de node ne fonctionnais pas de la manière voulue et cela causais des fuites de mémoires visibles avec Valgrind.
Le deuxième soucis, la libération de mémoire aura été le plus gros soucis que j'ai eus tout ce semestre, j'ai pris beaucoup de temps à voir et comprendre comment allouer proprement la mémoire et la libérée dans ce TP. Au début, je n'allouais que *h->list* avec *sizeof(node)* ce qui faisais que le programme ne fonctionnais pas du tout. J'ai ensuite compris qu'il s'agissait d'un tableau et que je devais allouer l'ensemble du tableau en une seule fois et initialiser chacun des éléments à *NULL*.

| Projet | Pts | I/0 | Type | Progr | Module | Compil | Récursion | Tableaux | Pointeurs | Structures | Allocation | Fichier | Bit à bit | Fct Pointer | Biblio |
| ------ | --- | --- | ---- | ----- | ------ | ------ | --------- | -------- | --------- | ---------- | ---------- | ------- | --------- | ----------- | ------ |
| TP12 | 11 | 2 | 1 | 1 | | 1 | | 1 | 1 | 2 | 1 | 1 | | | |
## [TP15](https://github.com/Minibuz/ProgC-S2/tree/main/TP15)
Le TP 15 aura été pour moi le plus simple.
Il a d'abord fallu implémenter une pile avec les fonctions qui suivent et qui était demandé, ce qui as été le plus simple.
Ensuite, il a fallu traiter les entrés de l'utilisateur. Pour réaliser cette tâche, j'ai dû utiliser une librairie externe nommée readLine ce qui a demandé du temps, mais qui n'a pas posé nécessairement de problème. Le code suivant est l'exemple duquel je me suis inspiré afin de lire les entrés de l'utilisateur.
```c
 while ((line = readline("> "))) /* Recupère l'entrée et la met dans line */
 {
   add_history(line); /* Ajoute line à l'historique */
   ...
   free(line) /* Free line car readLine alloue avec Malloc la taille qu'il faut */
 }

 clear_history(); /* Vide l'historique */
```
Après la lecture de l'entrée, il a suffi de traiter l'élément entré en séparant chacun des éléments par un espace et en transformant l'entrée en *int* s'il s'agissait d'un nombre, faire l'action correspondante à la lettre ou au mot entré ou jeté l'entré dans le reste des cas.
```c
value = (int)strtol(word, &end, 10);
if(word != end) {
	push(head, value);
}
if(*end != '\0') {
	printf("Those characters are not treated : %s\n", end);
}
```

| Projet | Pts | I/0 | Type | Progr | Module | Compil | Récursion | Tableaux | Pointeurs | Structures | Allocation | Fichier | Bit à bit | Fct Pointer | Biblio |
| ------ | --- | --- | ---- | ----- | ------ | ------ | --------- | -------- | --------- | ---------- | ---------- | ------- | --------- | ----------- | ------ |
| TP15 | 16 | 2 | 1 | 1 | | 1 | 2 | | 1 | 1 | 2 | | |1 |2 |

# Conclusion
En conclusion, cette année de C m'as permis d'apprendre le langage de zéro ce qui est extrêmement bénéfique à la fois en programmation, mais aussi dans d'autres matières telles que l'algorithmique.
Je suis assez satisfait de ce que j'ai fait au cours de ce semestre même si je pense qu'avec l'ensemble des cours en présentiel, j'aurais pu aller plus loin. Malgré cela, j'ai acquis des compétences et une compréhension du langage bien meilleur qu'au début surtout vis-à-vis de l'allocation dynamique et de l'usage de Valgrind au cours de ce semestre.
