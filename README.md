# Cub3D: A Raycasting Engine in C

**Cub3D** is a 3D graphical engine inspired by the 1992 classic Wolfenstein 3D. It uses the **Raycasting** technique to simulate a 3D environment from a 2D map, built entirely in C using the **MiniLibX** library.

---

### The Logic: How it works

Unlike traditional 3D engines that render polygons, Cub3D uses a 2D grid to calculate the distance to the nearest wall for every vertical slice of the screen.

- **DDA Algorithm**: Digital Differential Analysis is used to find the intersection of rays with the grid lines efficiently.
- **Texture Mapping**: Each vertical stripe of the wall is textured based on the exact coordinate where the ray hit.
- **Performance**: By rendering only what is visible in the player's field of view (FOV), the engine maintains high frame even on modest hardware.

---

### Features

- **Dynamic Movement**: Smooth WASD navigation and 360° rotation using arrow keys.

- **Wall Texturing**: Distinct textures for North, South, East, and West walls.

- **Custom Map** Support: Robust .cub file parser with error handling for misconfigurations.

- **System Integrity**: Zero memory leaks and clean exit handling (ESC or Red Cross).


---

### Preview 

![CUB3D_ ANIM](https://github.com/erwkuvi/cub3d_42/blob/main/assets/cub3d_anim.gif)

---

### Map Configuration

The engine accepts a .cub configuration file. The map must be enclosed by walls (1) and can contain:

- `0`: Empty space
- `1`: Wall
- `N, S, E, W`: Player starting position and orientation

Example `.cub` File:
```
# Plaintext
NO ./path_to_the_north_texture
SO ./path_to_the_north_texture
WE ./path_to_the_north_texture
EA ./path_to_the_north_texture

F 220,100,0
C 225,30,0

111111
100101
101001
111111
```

---

### Technical Implementation

1. Raycasting Math
The engine calculates the ray direction based on the player's FOV:

$$rayDirX = dirX + planeX * cameraX$$
$$rayDirY = dirY + planeY * cameraX$$

2. The DDA Step
We increment the ray until it hits a wall, calculating the perpendicular distance to avoid the **fisheye effect** common in early raycasters.

---

### Getting Started

1. Clone the repository:
```
# Bash
git clone git@github.com:erwkuvi/cub3d_42.git
```

2. Compile:
```
# Bash
make
```

3. Launch:
```
# Bash
./cub3D maps/map.cub
```

---

### Credits & References

- [Lodev's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html)
- [PlayfulJS](https://www.playfuljs.com/a-first-person-engine-in-265-lines/)

---

