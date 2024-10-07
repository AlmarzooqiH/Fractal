# Fractal
This project is about computer graphics where i implemented mandelbrot fractal and julia fractal and some more fractals.

# Disclaimer
This program only works on Mac and Linux machines.

# Prerequisite
Make sure you have Minilibx installed on your machine before using it.

# Installation
- Linux:
-  ```sudo apt-get install gcc make xorg libxext-dev libbsd-dev```
- Macos:
- ```brew install Xquartz```

# Compiling
  - In the terminal use make
# How to start the program
  - ./fractol [fractal_name]
  - Available fractals
    - mandelbrot
    - burningship
    - tricon
    - julia (Real number between -2.0 to 2.0) (Imaginary number between -2.5 to 2.5)
  
# Controls
  - R: Reset
  - M: Will switch to Mandelbrot fractal
  - B: Will switch to Burningship fractal
  - T: Will switch to Tricon fractal
  - -: Will reduce the iteration per pixels by a factor of 10; p->ipp -=10;
  - +: Will increase the iteration per pixels by a factor of 10; p->ipp +=10;
  - 1-5: Will change the colors of the fractals.
