*This project has been created as part of the 42 curriculum by zkarali, skucukon.*

# cub3D - My first 3D World with Raycasting

## Description
**cub3D** is a 42 Network group project that explores the basics of 3D computer graphics using the **Raycasting** technique—popularized by classic 90s games like *Wolfenstein 3D*. 

The goal of this project is to create a dynamic 3D graphical representation of a maze from a first-person perspective. The application reads a scene description file with a `.cub` extension, parses the map configuration, handles texture mapping for walls, and provides real-time window management and user interactions using **MiniLibX**.

### Key Features
- **Raycasting Engine:** Calculates wall distances, height projections, and vertical rendering slices in real-time.
- **Directional Textures:** Distinct XPM texture mapping for North, South, East, and West walls.
- **Customizable Colors:** Dynamic RGB color rendering for floor and ceiling elements.
- **Interactive Controls:** Smooth player movement (W, A, S, D) and rotation (Left/Right arrow keys or Mouse).
- **Strict Map Parser:** Validates wall enclosures, map boundaries, player starting points, and scene configurations.

---

## Instructions

### Prerequisites
- A Unix-based operating system (Linux or macOS).
- `cc` compiler.
- `make` utility.
- X11 graphics interface library (for MiniLibX on Linux).

### Compilation
To compile the executable, run the following command in the root directory:

```bash
make
```

### Available Makefile Rules
* `make` / `make all`: Compiles the `cub3D` executable.
* `make clean`: Removes object files (`.o`).
* `make fclean`: Removes object files and the `cub3D` executable.
* `make re`: Performs a complete re-compilation.

---

## Execution
Run `cub3D` by passing a valid `.cub` map file as an argument:

```bash
./cub3D maps/valid_map.cub
```

### Controls

Key                Action

W / S              Move Forward / Backward
A / D              Strafe Left / Right
Left / Right       Arrow Rotate Camera Left / Right
ESC / Window [X]   Close Application Cleanly

---

## Resources

### Documentation & References

Graphics Library: https://harm-smits.github.io/42docs/libs/minilibx — Unofficial reference guide for 42 MiniLibX functions and event handling.

Core Explanation: https://hackmd.io/@nszl/H1LXByIE2 — Comprehensive guide on Raycasting logic and implementation details.

Prior Curriculum Projects: Knowledge and structural patterns were adapted from our previous 42 project, so_long — specifically regarding MiniLibX initialization, window management, event handling hooks, parser and basic 2D map parsing strategies.