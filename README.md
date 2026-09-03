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



### Installation & Compilation

Clone MiniLibX (42 Paris Repository):

```bash
git clone git@github.com:42Paris/minilibx-linux.git minilibx-linux
```

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

| Key | Action |
| :--- | :--- |
| **W / S** | Move Forward / Backward |
| **A / D** | Strafe Left / Right |
| **Left / Right Arrow** | Rotate Camera Left / Right |
| **ESC / Window [X]** | Close Application Cleanly |

---

## Resources

### Documentation & References

Graphics Library: https://harm-smits.github.io/42docs/libs/minilibx — Unofficial reference guide for 42 MiniLibX functions and event handling.

Core Explanation: https://hackmd.io/@nszl/H1LXByIE2 — Comprehensive guide on Raycasting logic and implementation details.

Prior Curriculum Projects: Knowledge and structural patterns were adapted from our previous 42 project, so_long — specifically regarding MiniLibX initialization, window management, event handling hooks, parser and basic 2D map parsing strategies.

Cub3D Explanation : https://devabdilah.medium.com/3d-ray-casting-game-with-cub3d-7a116376056a

Executor Shematic: https://drive.google.com/drive/folders/1IMvo9bFC7staTYq7hgvpbmfqSZEuQTuk?usp=drive_link

### AI Usage

AI (Claude) was used in this project for the following tasks:

**Understanding the raycasting mathematics**
AI was used to derive and explain the formulas behind the raycasting
— why `delta_dist` equals `1 / ray_dir`, why the perpendicular distance
is used instead of the Euclidean one (and how the fisheye distortion appears without it),
why `dir` must be a unit vector while `plane` sets the field of view, and why the texture
column requires a mirroring correction. Each derivation was traced with concrete numerical
values and checked against the running program.

**Diagrams for the wall rendering pipeline**
AI was asked to generate diagrams to make the pipeline visual: how the DDA algorithm steps
from one grid boundary to the next, how the perpendicular distance keeps a flat wall from
appearing curved, and how a hit position on a wall surface maps to a texture column and
then to screen pixels.

**Review after completion**
Once the project was working, AI was used to review the codebase for memory leaks and edge
cases, and to produce a consolidated visual and written reference of the whole engine for
revision purposes.

Visual Reference: [https://drive.google.com/drive/folders/1IMvo9bFC7staTYq7hgvpbmfqSZEuQTuk?usp=drive_link] — A set of diagrams covering the camera geometry, the DDA ray
traversal and the wall rendering pipeline. Generated with AI during development as a
study aid (see AI Usage below).

AI was used to create the README.md file