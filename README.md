# 📊 C++ Bubble Sort Visualizer

A lightweight algorithmic tool that generates a step-by-step graphical visualization of the Bubble Sort algorithm. The program handles sorting logic in **C++** and exports the process as a dynamic **HTML/CSS** file.

## 💡 Overview

This project bridges low-level logic with frontend visualization. It accepts a user-defined array of integers, performs Bubble Sort, and captures the state of the array after every inner-loop iteration.

**Key Features:**
* **Dynamic Scaling:** Algorithmically calculates bar heights to fit any input range within the viewport.
* **Step-by-Step Rendering:** visualizes the array state at every significant comparison/swap.
* **No Dependencies:** Generates raw HTML/CSS; no external libraries required.

## 🛠️ Tech Stack

* **Logic:** C++ (STL, File I/O)
* **Visualization:** HTML5, CSS3 (Flexbox)

## 🚀 Quick Start

1.  **Compile the code:**
    ```bash
    g++ main.cpp -o visualizer
    ```

2.  **Run the application:**
    ```bash
    ./visualizer
    ```

3.  **Input Data:**
    Enter a comma-separated list of numbers (e.g., `50, 12, 34, 10, 90`).

4.  **View Output:**
    Open the generated `visualization.html` file in your browser to see the sorting process.

