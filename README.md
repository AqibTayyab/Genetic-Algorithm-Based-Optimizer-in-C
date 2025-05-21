🧬 Genetic Algorithm-Based Optimizer in C
A Natural Selection-Inspired Optimization Solver

Overview
This project demonstrates a simple implementation of a Genetic Algorithm (GA) using the C programming language. It solves a basic mathematical optimization problem by simulating evolutionary processes like selection, crossover, and mutation.

Objective: Maximize the function
f(x) = x², where x ∈ [0, 31]
Features
- Binary chromosome representation (5-bit)
- Fitness evaluation using a square function
- Selection of the fittest parents
- Single-point crossover for breeding
- Bit-level mutation with a low probability
- Generation-by-generation evolution tracking
How to Run the Program
Requirements
- C Compiler (e.g., GCC)
- Command-line terminal (Linux, Mac, or Windows)
Steps to Play
1. Clone the Repository
   git clone https://github.com/AqibTayyab/Genetic-Algorithm-Based-Optimizer-in-C
   cd Genetic-Algorithm-Based-Optimizer-in-C
2. Compile the Code
   gcc -o Genetic-Algorithm-Based-Optimizer-in-C.c
3. Run the Executable
   ./Genetic-Algorithm-Based-Optimizer-in-C
4. Observe the Evolution
- The program prints:
  - The initial random population
  - The evolving population through generations
  - The optimized solution in the final generation
How the Algorithm Works
1. Population Initialization:
   A random set of individuals (binary strings) is created.
2. Fitness Calculation:
   Fitness of each individual is calculated using f(x) = x * x.
3. Selection:
   The two individuals with the highest fitness are selected as parents.
4. Crossover:
   A crossover point is randomly chosen to create two new children.
5. Mutation:
   Each bit in the children has a small chance to flip (mutate).
6. Replacement:
   The two individuals with the lowest fitness in the population are replaced by the new children.
7. Repeat:
   Steps 2–6 repeat over several generations (default: 10).
File Structure
genetic-algorithm-c/
│
├── main.c          # Main source code with full implementation
├── README.docx     # This documentation file
Author
AqibTayyab
GitHub: https://github.com/AqibTayyab

License
This project is licensed under the MIT License. You are free to use, modify, and distribute it.

Bonus Tips
- Change the fitness function to solve other optimization problems.
- Increase the chromosome length for a wider search space.
- Adjust the mutation rate to balance exploration and exploitation.
