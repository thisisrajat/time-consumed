#include <iostream>
#include <cstdio>
#include <ctime>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <sys/stat.h>

using namespace std;

// Global Declarations

vector< string > arguments; // Keeps all the arguments passed in the program

// Prints help

inline void print_info() {
  cerr << "Usage \n";
  cerr << "---------------------------\n";
  cerr << "[tc] <..1..> <..2..>\n";
  cerr << "1 => Out file / Executable file\n";
  cerr << "2 => Input file\n";
  cerr << "If usage is unclear, refer README.md\n";
  exit(0);
}

// Initialize the program. Sanity Checks

inline void init(int argc, char** argv) {
  for(int i = 1; i < argc; i++) {
    arguments.push_back(argv[i]);
  }
}

// Utility function which returns if a string is in the args

inline bool has(const string &u) {
  for(size_t i = 0; i < arguments.size(); i++) {
    if(arguments[i] == u) {
      return true;
    }
  }
  return false;
}

// Utility function which returns if the file exists in the pwd

inline bool file_exists(const string &u) {
  struct stat buffer;
  return (stat(u.c_str(), &buffer) == false);
}

// Utility function which modifys cmd string for Linux

void modify_cmd(string& cmd) {
  int index = cmd.find('.');
  
  // If File Format ends with .out => it is Linux
  
  if("out" == cmd.substr(index, 3)) {
    cmd = "./" + cmd;
  } 
}

int main(int argc, char **argv) {
  init(argc, argv);

  if(argc == 1 || argc == 2 || has("-h") || has("--h")) {
    print_info();
  }

  // Executable File
  string exec = arguments[0]; 

  // Input File
  string input = arguments[1];

  // Through error if file do not exists
  if(!file_exists(exec)) {
    cerr << "Executable file does not exist\n";
    return 0;
  }
  if(!file_exists(input)) {
    cerr << "Input file does not exist\n";
    return 0;
  }

  system("touch output.text");

  // Command that is to be run
  string cmd = exec + " < " + input + " > output.text";

  modify_cmd(cmd);

  // Time Calculation begins
  
  double t1 = clock();
  system(cmd.c_str());
  double t2 = clock();

  // Time Calculation Ends

  system("rm -rf output.text");

  // Print the results to stdout
  printf("Took about **%.4f secs**\n", (t2 - t1) / CLOCKS_PER_SEC);
} 