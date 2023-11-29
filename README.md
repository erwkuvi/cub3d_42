# cub3d_42

This project is inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever.

References:
lodev.org
playfuljs.com

Display of an image and respects the following rules:
- Left and right arrow to rotate
- WASD keys to move
- Esc key should close the window clearly, same as clicking on the red cross
- Use of images of the mlx is strongly recommended
- The program should run being its first argument a file ending in ".cub". ex: "cub3d map.cub"
- Only 6 possible characters may conform the map:
	- 0 for empty space
	- 1 for wall
	- N,S,E,W for player´s starting position and orientation.
- Maps must be closed
- On the map file, except for the map´s content, each type of element can be separated by one or more empty lines
- Except for the map content which always has to be the last, each type of element can be set in any order in the file
- Except for the map, each type of information from an element can be separated by one or more spaces.
- Each element first information is the type identifier (one or two characters), followed by informations for each object
	Example:
		*North Texture:
		NO ./path_to_the_north_texture
- If any misconfiguration of any kind is encountered in the file, the program must exit properly and return "Error\n" followed by an explicit error message of your choice.
