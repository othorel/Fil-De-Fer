# 🌐 FDF - 42 Project

<p align="center">
  <img src="https://github.com/leogaudin/42_project_badges/raw/main/badges/fdf_bonus.webp" />
</p>

Welcome to **FDF**, a 42 project where you create a 3D wireframe viewer for 3D landscapes based on 2D maps. The project involves graphics programming, coordinate transformation, and rendering.

---

## 📋 Project Overview

| **Category**            | **Functions**                                                                                           |
|-------------------------|--------------------------------------------------------------------------------------------------------|
| **Main Program**         | `fdf` - Displays a 3D wireframe of a map with optional customization.                                  |
| **Bonus Program**        | `fdf_bonus` - Enhances the main program with additional features such as interactive controls or extended visualization options. |

---

## 🚀 Key Features

1. **3D Wireframe Rendering**:
   - Renders a 3D wireframe of a given 2D map file (`*.fdf`) using isometric projection.
   
2. **User Interaction**:
   - Navigate, zoom, and rotate the 3D model for a more interactive experience.

3. **Customizability**:
   - Colors, scaling, and transformations are adjustable to improve the visualization.

4. **Bonus Features**:
   - Additional functionalities such as enhanced controls, alternative projections, or richer graphical effects.

---

## 🗂️ File Structure

| **File**                | **Description**                                                                                        |
|-------------------------|--------------------------------------------------------------------------------------------------------|
| `Makefile`              | Automates the compilation process for both `fdf` and `fdf_bonus`.                                      |
| `fdf.h`                 | Header file with function prototypes, macros, and necessary includes.                                  |
| `src/*.c`               | Source files containing the logic for graphics rendering, file parsing, and user interactions.         |
| `libft/`                | Custom library for utility functions like `ft_putnbr`, `ft_split`, and others.                        |
| `minilibx-linux/`       | The MiniLibX library for managing graphics and rendering.                                              |
| `obj/`                  | Directory for object files during compilation.                                                        |

---

## 🔧 Compilation Instructions

Use the **Makefile** to compile the project.

### Compile the main program:
```bash
make
```
### Compile the bonus program:
```bash
make bonus
```
### Clean the project (remove object files):
```bash
make clean
```
### Full cleanup (remove all generated files):
```bash
make fclean
```
### Recompile after cleaning:
```bash
make re
```
---
## 💻 Usage

Once compiled, you can run the program to display a 3D wireframe of a map.

Run the main program:
```bash
./fdf test_maps/[map].fdf
```

#### Different projections

By pressing `I`, `O` and `P` keys on your keyboard, you will switch projection views to `Isometric`, `Top View` and `Perspective`, respectively. 

<figure>
<figcaption><i>Isometric View</i></figcaption>
<img width="550px" src=https://github.com/othorel/Fil-De-Fer/blob/main/img/Screenshot%20from%202025-01-20%2016-31-01.png alt="FdF Isometric"/>
</figure>
<figure>
<figcaption><i>Top View</i></figcaption>
<img width="550px" src=https://github.com/othorel/Fil-De-Fer/blob/main/img/Screenshot%20from%202025-01-20%2016-34-17.png alt="FdF Top View"/>
</figure>
<figure>
<figcaption><i>Perspective View</i></figcaption>
<img width="550px" src=https://github.com/othorel/Fil-De-Fer/blob/main/img/Screenshot%20from%202025-01-20%2016-32-41.png alt="FdF Perspective"/>
</figure>
