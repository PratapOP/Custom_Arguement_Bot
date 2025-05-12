#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <limits>
#include <deque>
#include <queue>

using namespace std;

// Color codes for terminal output
const string RESET = "\033[0m";
const string GREEN = "\033[32m";
const string RED = "\033[31m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";
const string BRIGHT_GREEN = "\033[92m";

// Command history
vector<string> commandHistory;
int historyIndex = -1;

// Print colored output
void printColored(const string& text, const string& color = WHITE) {
    cout << color << text << RESET << endl;
}

// Print prompt
void printPrompt() {
    cout << GREEN << "user@argos:~$ " << RESET;
}

// Clear screen
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Show help
void showHelp() {
    printColored("Available commands:", BLUE);
    printColored("  help      Show this help message", WHITE);
    printColored("  clear     Clear the terminal", WHITE);
    printColored("  arg       Start an argument discussion (usage: arg <topic>)", WHITE);
    printColored("  analyze   Analyze an argument (usage: analyze <argument>)", WHITE);
    printColored("  echo      Echo the input (usage: echo <text>)", WHITE);
    printColored("  version   Show system version", WHITE);
    printColored("  exit      Exit the shell", WHITE);
    printColored("  math      Perform mathematical operations (usage: math <expression>)", WHITE);
    printColored("  print     Print to terminal (usage: print <text>)", WHITE);
    printColored("  disk      Disk scheduling algorithms (usage: disk <fcfs|sstf|scan|cscan|look|clook>)", WHITE);
    printColored("  process   Process scheduling algorithms (usage: process <fcfs|sjf|priority|rr|srjf>)", WHITE);
}

// Handle argument discussion
void handleArgument(const string& topic) {
    if (topic.empty()) {
        printColored("Usage: arg <topic>", RED);
        return;
    }

    vector<string> styles = {"neutral", "supportive", "critical", "socratic"};
    string currentStyle = styles[rand() % styles.size()];

    printColored("Starting argument discussion about: " + topic, YELLOW);
    printColored("Bot response style: " + currentStyle, BLUE);

    map<string, vector<string>> responses = {
        {"neutral", {
            "The topic \"" + topic + "\" presents several valid perspectives worth considering.",
            "There are reasonable arguments on multiple sides of \"" + topic + "\".",
            "\"" + topic + "\" is a complex issue with no simple answers."
        }},
        {"supportive", {
            "I agree with your focus on \"" + topic + "\" - it's an important issue.",
            "You're absolutely right to bring up \"" + topic + "\" - more people should discuss this.",
            "\"" + topic + "\" is indeed a critical matter that deserves attention."
        }},
        {"critical", {
            "Your emphasis on \"" + topic + "\" might overlook some important factors.",
            "While \"" + topic + "\" is relevant, it may not be the most pressing concern.",
            "There are strong counterarguments to common views about \"" + topic + "\"."
        }},
        {"socratic", {
            "What makes \"" + topic + "\" particularly important in your view?",
            "How might someone with a different perspective view \"" + topic + "\"?",
            "What evidence would change your mind about \"" + topic + "\"?"
        }}
    };

    string response = responses[currentStyle][rand() % responses[currentStyle].size()];
    printColored(response, YELLOW);
}

// Analyze argument structure
void analyzeArgument(const string& argument) {
    if (argument.empty()) {
        printColored("Usage: analyze <argument>", RED);
        return;
    }

    printColored("Analyzing argument: \"" + argument + "\"", BLUE);

    // Simple argument analysis
    size_t wordCount = count(argument.begin(), argument.end(), ' ') + 1;
    bool hasQuestion = argument.find('?') != string::npos;
    bool isEmphatic = all_of(argument.begin(), argument.end(), [](char c) {
        return isupper(c) || isspace(c) || ispunct(c);
    }) && wordCount > 3;
    bool isComplex = wordCount > 15;

    printColored("- Word count: " + to_string(wordCount), WHITE);
    printColored("- Is question: " + string(hasQuestion ? "Yes" : "No"), WHITE);
    printColored("- Emphatic tone: " + string(isEmphatic ? "Yes" : "No"), WHITE);
    printColored("- Complex argument: " + string(isComplex ? "Yes" : "No"), WHITE);

    // Provide feedback
    if (wordCount < 5) {
        printColored("Note: Argument seems quite brief. Consider expanding your points.", YELLOW);
    }
    if (isEmphatic) {
        printColored("Note: ALL CAPS can be perceived as shouting. Consider more measured language.", YELLOW);
    }
}

// Mathematical evaluation
void evaluateMath(const string& expression) {
    if (expression.empty()) {
        printColored("Usage: math <expression>", RED);
        return;
    }

    try {
        // Simple math evaluation (for demonstration)
        // In a real application, you'd want a proper expression parser
        istringstream iss(expression);
        double a, b;
        char op;
        iss >> a >> op >> b;

        double result = 0;
        switch (op) {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/':
                if (b == 0) throw runtime_error("Division by zero");
                result = a / b;
                break;
            case '^': result = pow(a, b); break;
            default: throw runtime_error("Invalid operator");
        }

        printColored(expression + " = " + to_string(result), BRIGHT_GREEN);
    } catch (const exception& e) {
        printColored("Math evaluation error: " + string(e.what()), RED);
    }
}

// Disk Scheduling Algorithms
void handleDiskScheduling(const string& algorithm) {
    map<string, string> algorithms = {
        {"fcfs", "First-Come, First-Served"},
        {"sstf", "Shortest Seek Time First"},
        {"scan", "SCAN (Elevator)"},
        {"cscan", "C-SCAN (Circular SCAN)"},
        {"look", "LOOK"},
        {"clook", "C-LOOK"}
    };

    if (algorithm.empty() || algorithms.find(algorithm) == algorithms.end()) {
        printColored("Available disk scheduling algorithms:", BLUE);
        for (const auto& [abbr, name] : algorithms) {
            printColored("  " + abbr + string(6 - abbr.length(), ' ') + name, WHITE);
        }
        return;
    }

    printColored("Simulating " + algorithms[algorithm] + " disk scheduling...", BLUE);

    // Sample disk requests
    vector<int> requests = {98, 183, 37, 122, 14, 124, 65, 67};
    int headStart = 53;
    int totalSeek = 0;

    if (algorithm == "fcfs") {
        // First-Come, First-Served
        int current = headStart;
        vector<int> sequence = {current};
        for (int req : requests) {
            totalSeek += abs(current - req);
            current = req;
            sequence.push_back(current);
        }

        ostringstream oss;
        for (size_t i = 0; i < sequence.size(); ++i) {
            if (i != 0) oss << " → ";
            oss << sequence[i];
        }

        printColored("Seek sequence: " + oss.str(), WHITE);
        printColored("Total seek operations: " + to_string(totalSeek), BRIGHT_GREEN);
    }
    else if (algorithm == "sstf") {
        // Shortest Seek Time First
        vector<int> remaining = requests;
        int currentPos = headStart;
        vector<int> sequence = {currentPos};

        while (!remaining.empty()) {
            // Find request with shortest seek time
            auto closest = min_element(remaining.begin(), remaining.end(),
                [currentPos](int a, int b) {
                    return abs(a - currentPos) < abs(b - currentPos);
                });

            totalSeek += abs(currentPos - *closest);
            currentPos = *closest;
            sequence.push_back(currentPos);
            remaining.erase(closest);
        }

        ostringstream oss;
        for (size_t i = 0; i < sequence.size(); ++i) {
            if (i != 0) oss << " → ";
            oss << sequence[i];
        }

        printColored("Seek sequence: " + oss.str(), WHITE);
        printColored("Total seek operations: " + to_string(totalSeek), BRIGHT_GREEN);
    }
    else {
        printColored("Algorithm " + algorithm + " visualization not yet implemented", RED);
    }
}

// Process Scheduling Algorithms
void handleProcessScheduling(const string& algorithm) {
    map<string, string> algorithms = {
        {"fcfs", "First-Come, First-Served"},
        {"sjf", "Shortest Job First"},
        {"srjf", "Shortest Remaining Job First"},
        {"priority", "Priority Scheduling"},
        {"rr", "Round Robin"}
    };

    if (algorithm.empty() || algorithms.find(algorithm) == algorithms.end()) {
        printColored("Available process scheduling algorithms:", BLUE);
        for (const auto& [abbr, name] : algorithms) {
            printColored("  " + abbr + string(6 - abbr.length(), ' ') + name, WHITE);
        }
        return;
    }

    printColored("Simulating " + algorithms[algorithm] + " process scheduling...", BLUE);

    // Sample processes
    struct Process {
        int id;
        int arrival;
        int burst;
        int priority;
    };

    vector<Process> processes = {
        {1, 0, 8, 3},
        {2, 1, 4, 1},
        {3, 2, 9, 4},
        {4, 3, 5, 2}
    };

    if (algorithm == "fcfs") {
        // First-Come, First-Served
        vector<string> timeline;
        int currentTime = 0;

        for (const auto& proc : processes) {
            if (proc.arrival > currentTime) {
                currentTime = proc.arrival;
            }
            timeline.push_back("P" + to_string(proc.id) + " (" +
                             to_string(currentTime) + "-" +
                             to_string(currentTime + proc.burst) + ")");
            currentTime += proc.burst;
        }

        ostringstream oss;
        for (size_t i = 0; i < timeline.size(); ++i) {
            if (i != 0) oss << " → ";
            oss << timeline[i];
        }

        printColored("Execution timeline: " + oss.str(), WHITE);
    }
    else if (algorithm == "sjf") {
        // Shortest Job First (non-preemptive)
        vector<Process> sjfProcs = processes;
        sort(sjfProcs.begin(), sjfProcs.end(), [](const Process& a, const Process& b) {
            return a.burst < b.burst;
        });

        vector<string> timeline;
        int currentTime = 0;

        for (const auto& proc : sjfProcs) {
            if (proc.arrival > currentTime) {
                currentTime = proc.arrival;
            }
            timeline.push_back("P" + to_string(proc.id) + " (" +
                             to_string(currentTime) + "-" +
                             to_string(currentTime + proc.burst) + ")");
            currentTime += proc.burst;
        }

        ostringstream oss;
        for (size_t i = 0; i < timeline.size(); ++i) {
            if (i != 0) oss << " → ";
            oss << timeline[i];
        }

        printColored("Execution timeline: " + oss.str(), WHITE);
    }
    else {
        printColored("Algorithm " + algorithm + " visualization not yet implemented", RED);
    }
}

// Main shell loop
void runShell() {
    string input;

    clearScreen();
    printColored("Welcome to ArgOS Shell. Type 'help' for commands.", BLUE);

    while (true) {
        printPrompt();

        // Get input with support for history
        getline(cin, input);

        // Handle empty input
        if (input.empty()) {
            continue;
        }

        // Add to command history
        commandHistory.push_back(input);
        historyIndex = -1;

        // Handle exit command
        if (input == "exit") {
            printColored("Exiting ArgOS Shell. Goodbye!", BLUE);
            break;
        }

        // Split input into command and arguments
        istringstream iss(input);
        vector<string> tokens;
        string token;

        while (iss >> quoted(token)) {
            tokens.push_back(token);
        }

        string command = tokens[0];
        vector<string> args(tokens.begin() + 1, tokens.end());

        // Process commands
        if (command == "help") {
            showHelp();
        }
        else if (command == "clear") {
            clearScreen();
            printColored("Terminal cleared. Type 'help' for commands.", BLUE);
        }
        else if (command == "arg") {
            string topic = args.empty() ? "" : args[0];
            for (size_t i = 1; i < args.size(); ++i) {
                topic += " " + args[i];
            }
            handleArgument(topic);
        }
        else if (command == "analyze") {
            string argument = args.empty() ? "" : args[0];
            for (size_t i = 1; i < args.size(); ++i) {
                argument += " " + args[i];
            }
            analyzeArgument(argument);
        }
        else if (command == "echo" || command == "print") {
            string text = args.empty() ? "" : args[0];
            for (size_t i = 1; i < args.size(); ++i) {
                text += " " + args[i];
            }
            printColored(text, WHITE);
        }
        else if (command == "version") {
            printColored("ArgOS Shell v2.0 (build 2023.12)", BLUE);
        }
        else if (command == "math") {
            string expr = args.empty() ? "" : args[0];
            for (size_t i = 1; i < args.size(); ++i) {
                expr += " " + args[i];
            }
            evaluateMath(expr);
        }
        else if (command == "disk") {
            string alg = args.empty() ? "" : args[0];
            handleDiskScheduling(alg);
        }
        else if (command == "process") {
            string alg = args.empty() ? "" : args[0];
            handleProcessScheduling(alg);
        }
        else if (command == "hello" || command == "hi" || command == "hey") {
            printColored("Hi there! How are you?", BRIGHT_GREEN);
        }
        else {
            printColored("Command not found: " + command + ". Type 'help' for available commands.", RED);
        }
    }
}

int main() {
    srand(time(0)); // Seed random number generator
    runShell();
    return 0;
}
