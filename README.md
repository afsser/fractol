# fract-ol Project Overview

The **fract-ol** project is a computer graphics application that allows users to visually explore fractals, which are intricate mathematical patterns that repeat at every scale. The project is implemented in C and adheres to strict memory management requirements—no memory leaks are tolerated, and all dynamically allocated memory must be properly freed. The fractals are rendered by plotting points based on iterative mathematical formulas, with each point's color corresponding to how quickly it diverges to infinity. This creates the iconic and complex fractal shapes such as the **Mandelbrot** and **Julia** sets. 

Through interactive controls like zooming and parameter adjustments, users can delve deeper into the fractal's infinite complexity while maintaining smooth performance and efficient resource usage.


## Key Features

- **Fractals Supported**: Julia and Mandelbrot sets.
- **Zooming and Interaction**: The mouse wheel allows infinite zoom in/out within the fractals, with support for user-defined parameters to explore different Julia sets.
- **Window Management**: The program provides smooth window interactions, including minimizing, switching windows, and closing via `ESC` or the window's close button.
- **Color Depth**: Fractals are rendered with various colors representing depth, and the color range can dynamically shift.

## Bonus Features

The project includes bonus functionality:
- **Extra Fractal**: An additional fractal type is implemented.
- **Zoom Focus**: Zooming centers around the mouse position.
- **View Navigation**: The view can be moved using arrow keys.
- **Dynamic Colors**: Color range shifts for added visual effects.

## Setup and Usage

- **Library**: MLX42 is automatically downloaded and configured via the Makefile, making setup straightforward.
- **Makefile Targets**: `all`, `clean`, `fclean`, `re`.
- **External Functions**: Utilizes math functions (`-lm`), `ft_printf`, and MLX42 functions.

This project introduces basic computer graphics concepts and allows users to interactively explore fractals while gaining experience with event handling and optimization techniques in C.
