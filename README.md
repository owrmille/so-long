# so_long
**Nap Time**

"Nap Time" is a 2D game written in C where you help a chicken gather all her chicks from the field and bring them home for a nap. Navigate obstacles using `W`, `A`, `S`, and `D` keys, collect all the chicks, and find the shortest path to the house. Can you ensure every chick gets home safely?

1. To clone this repository
   ```bash
   git clone https://github.com/owrmille/so-long.git --recursive
   ```
2. To compile and run the program
   ```bash
   1.    make
   2.   ./so_long maps/valid_maps/{map of your choice}
     or ./so_long maps/invalid_maps/{map of your choice}
   ```
Example:

To compile and run the program
   ```bash
   1.    make
   2.   ./so_long maps/valid_maps/map_1.ber
   ```

You can use the `W`, `A`, `S`, and `D` keys to move the chicken. You can close the window using the `ESC` key or by clicking the close button `[x]`.

**The goal is to collect all the chicks for a nap and take them to the house choosing the shortest possible root**.

You can create a map by yourself, following these rules:

- The map has to be constructed with 3 components: rocks, chicks, and empty space.
- The map can be composed of only these 5 characters:
  - `0` for an empty space
  - `1` for a rock (obstacle)
  - `C` for a chick to collect (collectible)
  - `E` for a house to escape (exit)
  - `P` for the chicken’s starting position (start)
    
- The map must contain 1 house, at least 1 chick to collect, and 1 starting position to be valid.
- The map should not contain duplicate characters for the house/chicken (exit/start).
- The map must be rectangular.
- The map must be closed/surrounded by rocks.
  
If the rules are **not satisfied** or if there is **no valid path** in the map, the program returns an **error**.

Here is a simple valid map:
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```
