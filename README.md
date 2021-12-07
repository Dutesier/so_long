# so_long :dolphin:
## and thanks for all the fishes! :tropical_fish:
The goal is to create a small 2D game where a dolphin escapes earth after eating some fish. Or any hero
collects any valuables before leaving the place.

### Minilibx
You must use the miniLibX. Either the version that is available on the operating
system, or from its sources. If you choose to work with the sources, you will
need to apply the same rules for your libft as those written above in Common
Instructions part.
• The management of your window must remain smooth: changing to another window, minimizing, etc.

### Usage
The program must have one single argument, a .ber file that is a map representing the size of the map and the location of specific elements.
The map must be composed of only 5 possible characters: 0 for an empty space, 1 for a wall, C for a collectible, E for map exit and P for the player’s starting position.
This is a simple valid map:
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```
The map must be closed/surrounded by walls, if not the program must return
an error.
Map must have at least one exit, one collectible, and one starting position.
You don’t need to check if there’s a valid path in the map.
The map must be rectangular
