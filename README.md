# Cub3D
### The goal of this project:
To create a “realistic” 3D graphical representation of the inside of a maze from a first-person perspective using the Ray-Casting principles.
### Ray-Casting
Raycasting is a rendering technique to create a 3D perspective in a 2D map. Back when computers were slower it wasn't possible to run real 3D engines in realtime, and raycasting was the first solution. Raycasting can go very fast, because only a calculation has to be done for every vertical line of the screen. The most well known game that used this technique, is of course Wolfenstein 3D.
### Wolfenstein 3D
This project is inspired by the world-famous [Wolfenstein 3D](http://users.atw.hu/wolf3d/) game, which
was the first FPS ever.
![image](https://user-images.githubusercontent.com/90090114/163553576-58948d1c-941c-42ff-8f98-3f3fe4a3deed.png)
### MiniLibX
MiniLibX is a tiny graphics library which allows you to do the most basic things for rendering something in screens without any knowledge of X-Window and Cocoa. It provides so-called simple window creation, a questionable drawing tool, half-ass image functions and a weird event management system.
### Example a minimalist .cub scene:
```
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0
1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```
### Run:
```
%> make
%> ./cub3D maps/map1.cub
```
<img width="2032" alt="Screen Shot 2022-04-15 at 12 18 25 PM" src="https://user-images.githubusercontent.com/90090114/163552789-b22460ed-1786-4bad-9348-b03e3f4efb23.png">
