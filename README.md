# Cub3D: Wolfenstein-Style Raycaster 🏰

[![42 School](https://img.shields.io/badge/42-School-blue)](https://42firenze.it/)
[![GitHub license](https://img.shields.io/github/license/Nazar963/42_Cub3d)](https://github.com/Nazar963/42_Cub3d/blob/master/LICENSE)
[![Build Status](https://img.shields.io/github/actions/workflow/status/Nazar963/42_Cub3d/.github/workflows/build.yml?branch=master)](https://github.com/Nazar963/42_Cub3d/actions)

A sophisticated raycasting engine inspired by Wolfenstein 3D, implementing 3D rendering from 2D maps using the MiniLibX library.

![Cub3D Demo](https://raw.githubusercontent.com/Nazar963/42_Cub3d/master/images/demo.gif)


## Table of Contents 📖
- [Project Overview](#project-overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [Technical Implementation](#technical-implementation)
- [Testing](#testing)
- [Resources](#resources)
- [Acknowledgments](#acknowledgments)
- [License](#license)

## Project Overview

Cub3D is a 42 School project focused on creating a dynamic 3D environment from a 2D map using **raycasting principles**. This project introduces students to:
- 3D graphical rendering fundamentals
- MiniLibX library usage for graphics programming 
- Mathematical concepts behind raycasting
- Efficient algorithm design for real-time rendering
- Advanced memory management techniques

The project requires parsing a configuration file that defines:
- Map layout with walls, spaces, and player position
- Textures for different wall orientations
- Floor and ceiling colors

## Features

### Core Functionality 🔧
- **Raycasting Engine**: Efficient DDA (Digital Differential Analysis) algorithm
- **Map Parsing**: Supports `.cub` configuration files with error checking
- **Textured Walls**: Customizable textures for each cardinal direction
- **Dynamic Rendering**: Smooth 60+ FPS rendering even on large maps
- **Collision Detection**: Accurate wall collision with sliding prevention
- **Player Movement**: Fluid controls with rotation and strafing
- **Error Handling**: Comprehensive error management with meaningful messages

## Installation

### Requirements
- **MiniLibX**: 42's graphics library
- **X11/Xquartz** (macOS) or **Xorg** (Linux)
- **gcc** & **make**

### macOS Installation
```bash
# Install Xquartz (if not installed)
brew install --cask xquartz

# Clone repository
git clone https://github.com/Nazar963/42_Cub3d.git
cd 42_Cub3d

# Compile
make
```

### Linux Installation
```bash
# Install dependencies
sudo apt-get install gcc make xorg libxext-dev libbsd-dev

# Clone and compile
git clone https://github.com/Nazar963/42_Cub3d.git
cd 42_Cub3d
make
```

## Usage

### Basic Syntax
```bash
./cub3D path/to/map.cub
```

### Examples
```bash
# Run with standard map
./cub3d maps/map.cub
```

```c
NO textures/north.xpm   # North texture
SO textures/south.xpm   # South texture
WE textures/west.xpm    # West texture
EA textures/east.xpm    # East texture
F 220,100,100          # Floor color (RGB)
C 30,30,150            # Ceiling color (RGB)

        1111111111111111111111111
        1000000000110000000000001
        1011000011100000000000001
        1001000000000000000000001
111111111N11000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001       # Map layout
11110111111111011101010010001       # (1: walls)
11000000110101011100000010001       # (0: walkable)
10000000000000001100000010001       # (N,S,E,W: player start)
10000000000000001101010010001
110000011101010111110111100111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

## Controls
| Key | Action |
|-----|--------|
| **W** | Move forward |
| **S** | Move backward |
| **A** | Strafe left |
| **D** | Strafe right |
| **← →** | Rotate camera |
| **ESC** | Exit game |

## Technical Implementation

### Raycasting Algorithm
![Cub3d Example](https://raw.githubusercontent.com/Nazar963/42_Cub3d/master/images/image_sample.png)

### Key Components
1. **Digital Differential Analysis (DDA)**
   - Efficient grid traversal algorithm
   - Determines wall hit direction (NS/EW)
   - Calculates exact hit position for texture mapping

2. **Player Physics**
   ```c
   typedef struct s_player {
       double pos_x;       // X position
       double pos_y;       // Y position
       double dir_x;       // Direction vector
       double dir_y;
       double plane_x;     // Camera plane
       double plane_y;
       double move_speed;  // Movement velocity
       double rot_speed;   // Rotation speed
   } t_player;
   ```

3. **Texture Mapping**
   - UV coordinate calculation based on wall hit position
   - Texture buffering for performance optimization
   - Support for multiple texture resolutions

## Testing


### Memory Management
```bash
valgrind --leak-check=full ./cub3d maps/test_map.cub
```

### Recommended Testers
- [cub3D Map Validator](https://github.com/harm-smits/42docs)
- [Cub3D Tester](https://github.com/lschrafstetter/42_cub3d)

## Resources
1. [Lodev's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) - Comprehensive raycasting guide 
2. [42 MiniLibX Documentation](https://harm-smits.github.io/42docs/) - Official MLX reference 
3. [Raycasting Mathematics](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/) - Mathematical foundations

## Acknowledgments
- **42 School** for project concept and guidelines
- **Olivier Crouzet** for MiniLibX development 
- **Lode Vandevenne** for raycasting tutorials 
- **Peer Reviewers** at 42 Network for rigorous testing
- **Open-Source Community** for inspiration and resources

## 🤝 Contributing
Feel free to submit issues or pull requests if you have suggestions for improving the application or adding more features.

## License
This project is licensed under the MIT License - see [LICENSE](LICENSE) for details.

## 📧 Contact
For questions or feedback, please open an issue in the repository.

## ⭐ Star this repository if you found it helpful!
[![GitHub stars](https://img.shields.io/github/stars/Nazar963/42_Cub3d?style=social)](https://github.com/Nazar963/42_Cub3d/stargazers)

---

🎮 *"The first step into the world of 3D game development!"*  
[![42 School](https://img.shields.io/badge/42-profile-blue)](https://profile-v3.intra.42.fr/users/naal-jen)
[![GitHub Profile](https://img.shields.io/badge/GitHub-Nazar963-lightgrey)](https://github.com/Nazar963)
[![GitHub Follow](https://img.shields.io/github/followers/Nazar963?style=social)](https://github.com/Nazar963)

---
## 🍀 Goodluck:
Good luck with your Cub3d project at 42! 🚀
