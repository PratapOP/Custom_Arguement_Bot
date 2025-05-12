# Custom_Arguement_Bot
## ArgOS Shell - Interactive Command Line Tool

## Overview
ArgOS Shell is an interactive command-line interface that provides various utilities including argument analysis, mathematical calculations, and operating system scheduling algorithm simulations. The shell features colored output, command history, and a user-friendly interface.

## Features
- **Argument Discussion**: Start discussions on various topics with different response styles
- **Argument Analysis**: Analyze the structure and characteristics of arguments
- **Mathematical Operations**: Perform basic arithmetic calculations
- **Disk Scheduling**: Simulate various disk scheduling algorithms (FCFS, SSTF, SCAN, etc.)
- **Process Scheduling**: Simulate process scheduling algorithms (FCFS, SJF, Priority, etc.)
- **User-Friendly Interface**: Colored output, command history, and help system

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/PratapOP/Custom_Arguement_Bot
   ```
2. Navigate to the project directory:
   ```bash
   cd ArgOS-Shell
   ```
3. Compile the source code:
   ```bash
   g++ CustomArg.cpp -o argos
   ```
4. Run the shell:
   ```bash
   ./argos
   ```

## Usage
Once the shell is running, you can use the following commands:

| Command     | Description                                      | Example Usage               |
|-------------|--------------------------------------------------|-----------------------------|
| `help`      | Show all available commands                     | `help`                      |
| `clear`     | Clear the terminal screen                       | `clear`                     |
| `arg`       | Start an argument discussion                    | `arg climate change`        |
| `analyze`   | Analyze an argument structure                   | `analyze "This is my point"`|
| `math`      | Perform mathematical operations                 | `math 5 + 3`                |
| `disk`      | Simulate disk scheduling algorithms             | `disk fcfs`                 |
| `process`   | Simulate process scheduling algorithms          | `process sjf`               |
| `echo`      | Echo the input text                             | `echo Hello World`          |
| `version`   | Show the shell version                          | `version`                   |
| `exit`      | Exit the shell                                  | `exit`                      |

## Examples

1. Starting an argument discussion:
   ```
   user@argos:~$ arg artificial intelligence
   Starting argument discussion about: artificial intelligence
   Bot response style: socratic
   What makes "artificial intelligence" particularly important in your view?
   ```

2. Analyzing an argument:
   ```
   user@argos:~$ analyze "We should invest more in renewable energy"
   Analyzing argument: "We should invest more in renewable energy"
   - Word count: 7
   - Is question: No
   - Emphatic tone: No
   - Complex argument: No
   ```

3. Mathematical operation:
   ```
   user@argos:~$ math 2 ^ 10
   2 ^ 10 = 1024.000000
   ```

4. Disk scheduling simulation:
   ```
   user@argos:~$ disk fcfs
   Simulating First-Come, First-Served disk scheduling...
   Seek sequence: 53 → 98 → 183 → 37 → 122 → 14 → 124 → 65 → 67
   Total seek operations: 640
   ```

## Requirements
- C++ compiler (g++ recommended)
- Unix-like terminal for best experience (Windows users may need WSL for full functionality)

## Contributing
Contributions are welcome! Please fork the repository and submit a pull request with your changes.

## License
This project is open-source.
