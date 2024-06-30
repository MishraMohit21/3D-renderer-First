# 3D Renderer

Welcome to the 3D Renderer project! This project is a simple 3D rendering engine written in C++. It is designed for beginners, so if you are new to programming or to C++, this is a great place to start.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [License](#license)

## Introduction
This project aims to create a basic 3D rendering engine from scratch. The engine will render 3D objects using simple algorithms and techniques. It is an educational project intended to help you understand the fundamentals of 3D graphics programming.

## Features
- Render basic 3D shapes (Sphere)
- Simple shading
- Camera control
- Basic transformations (translation, rotation, scaling)

## Installation
To get started with this project, you need to have the following tools installed on your system:
- A C++ compiler (GCC, Clang, MSVC, etc.)

### Steps to Install
1. Clone the repository:
    ```bash
    git clone https://github.com/MishraMohit21/3D-renderer-First.git
    cd 3D-renderer-First
    ```
2. Run the compiler to build the exe
    ```bash
    g++ main.cpp -o main
    ```

## Usage
After successfully building the project, you can run the executable to see the 3D renderer in action.

### Running the Renderer

Running the executable is a tricky part here as I haven't used file I/O thus we will redirect the output stream into the file using " << " operator like this 
```bash
    >> image.ppm
```

1. Run the executable:
    ```bash
    ./main >> image.ppm
    ```

Your image should be created and the shaped and stuff would be rendered in it


## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

---
