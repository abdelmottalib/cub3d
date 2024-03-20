# Cub3D Project README

## Introduction:
Cub3D is a project designed to introduce you to the fundamentals of raycasting and basic 3D rendering. This project is part of the curriculum at 42, aimed at helping you understand the core concepts behind creating a simple 3D game engine from scratch.

## Project Overview:
Cub3D is inspired by the classic game Wolfenstein 3D, where you navigate through a maze-like environment from a first-person perspective. In this project, you'll be tasked with creating a simplified version of such a game. You'll implement raycasting techniques to render a 3D environment, handle player input for movement, and interact with the game world.

## Objective:
Your objective is to create a basic 3D game engine capable of rendering a maze-like environment, where the player can move around, collide with walls, and view the world from a first-person perspective. The rendered output will be displayed using the MiniLibX, a simple X-Window graphics library.

## Key Features:
- **Raycasting**: Implement the raycasting algorithm to render a 3D environment.
- **Map Parsing**: Read and interpret map files to generate the game world.
- **Player Movement**: Handle player input for movement (forward, backward, strafe).
- **Collision Detection**: Prevent the player from moving through walls or obstacles.
- **Texture Mapping**: Apply textures to walls to give the environment depth and detail.
- **Sprites**: Implement basic sprite rendering for objects like enemies or items.
- **HUD (Heads-Up Display)**: Display relevant information such as player health, score, etc.
- **Bonus Features**: Implement additional features to enhance the gameplay or visual experience.

## Installation:
To run Cub3D, follow these steps:
1. Clone this repository to your local machine.
2. Navigate to the project directory.
3. Run `make` command to compile the project.
4. Execute the program by running `./cub3D path_to_map_file.cub`.
5. The maps are available in the maps folder

## Controls:
- **W**: Move player forward.
- **S**: Move player backward.
- **A**: Strafe player left.
- **D**: Strafe player right.
- **Left Arrow**: Rotate player left.
- **Right Arrow**: Rotate player right.
- **ESC**: Exit the game.

## Resources:
- MiniLibX Documentation: [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- Raycasting Tutorial: [Lode's Computer Graphics Tutorial - Raycasting](https://lodev.org/cgtutor/raycasting.html)
- Wolfenstein 3D Development Blog: [Fabien Sanglard's Wolfenstein 3D Development Blog](http://fabiensanglard.net/)
- Additional resources and references provided by your instructors.

## Conclusion:
Cub3D is an exciting project that will challenge your understanding of 3D graphics rendering and game development fundamentals. Have fun exploring the world of raycasting and creating your own immersive game environment! If you encounter any issues or have questions, don't hesitate to reach out to your peers or instructors for assistance.

**Happy Coding!**
