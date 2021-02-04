This is a simple terminal-only C program (that is pretty bad) that that raises a complex number in trigonometric form to a real power.

# Instructions
*Convert from file:* `complextrigpower.exe -f <input file name> <output file name>`
The input file must be in this format: `<Modulus> <Argument> <Power>`

The output file will be in the format: `<Modulus> <Argument>`

*Direct mode via terminal:* `complextrigpower.exe -d <Modulus> <Argument> <Power>`
The output will be in the terminal in the format: `<Modulus> <Argument>`

*Benchmark (experimental):* `complextrigpower.exe -b <Number of times to raise random complex number in trigonometric form to a random power`
This randomly generates n complex numbers in trigonometric form and raises them to a random power. This is just an experimental way of benchmarking a CPU. The time needed is then displayed in milliseconds.

# TODO
Make the algorithm more efficient, and add organized error-checking for bad input.
