#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <unistd.h>
#include <array>
#include <memory>
#include <sys/types.h>
#include <sys/wait.h>
#include <algorithm> 
#include <cctype>
#include <locale>

// trim from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}


// https://pubs.opengroup.org/onlinepubs/009695399/functions/environ.html

using namespace std;


void pipeexample() {
  int fd[2];
  pipe(fd);

  pid_t pid;
  if ((pid = fork()) == 0) {
    //Child
    close(0);
    close(fd[1]);
    int myCin = dup(fd[0]);
    string s;
    while (std::cin.peek() != EOF) {
      getline(cin, s);
      std::cout << "("<<s<<")" << std::endl;
    }

  }
  else {
    //parent
    write(fd[1], "hello world", sizeof("hello world"));
    cout << "Ron"<< endl;
    close(fd[1]);
    waitpid(pid, NULL, 0);
  }
}






std::string myexec(const char* cmd) {
  std::array<char, 128> buffer;
  std::string result;
  std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
  if (!pipe) {
    throw std::runtime_error("popen() failed!");
  }
  while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
    result += buffer.data();
  }
  trim(result);
  return result;
}




std::string bc(string cmd) {
  cmd = "echo '"+cmd+"'|bc";
  string s = myexec(cmd.c_str());
  return s;
}







void createUnaryTest(string tensor1, string tensor2, string data1, string data2, string funcname, list<string> vals) {
  char buffer[512];

  printf("  {\n");

  cout << "    ";
  printf(tensor1.c_str(), data1.c_str());
  printf(" x;\n");
  string s = "    x = {"+*(vals.begin())+"};\n";
  cout << s;

  cout << "    ";
  printf(tensor2.c_str(), data2.c_str());
  printf(" expected;\n");

  // TODO: we need to loop over vals list
  
  string cmd = funcname+"("+*(vals.begin())+")";

  // TODO: for now we use bc. will change to matlab
  string sexpect = bc(cmd);

  s = "    expected = {"+sexpect+"};\n";
  cout << s;


  cout << "    ";
  printf(tensor2.c_str(), data2.c_str());
  printf(" result;\n");
  s = "    result = "+funcname+"(x);\n";
  cout << s;

  printf("  }\n");
}





 
int main ( int argc, char *argv[] )
{

  // TODO: create arrays for float types, signed int types, unisgen dint types, bool
  //       create default data for each. Then just loop through every combo
  //       as well as loops of Scalar, Vector, Matrix, Tensor
  //       test with complex and imaginary types as well
  createUnaryTest("Scalar<%s>", "Scalar<%s>", "double", "double", "-", {"2.3"});

  // if ( argc != 2 ) // argc should be 2 for correct execution
  //   // We print argv[0] assuming it is the program name
  //   cout<<"usage: "<< argv[0] <<" <filename>\n";
  // else {
  //   // We assume argv[1] is a filename to open
  //   ifstream the_file ( argv[1] );
  //   // Always check to see if file opening succeeded
  //   if ( !the_file.is_open() )
  //     cout<<"Could not open file\n";
  //   else {
  //     char x;
  //     // the_file.get ( x ) returns false if the end of the file
  //     //  is reached or an error occurs
  //     while ( the_file.get ( x ) )
  //       cout<< x;
  //   }
  //   // the_file is closed implicitly here
  // }
}
