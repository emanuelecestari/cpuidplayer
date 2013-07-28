// trying to determine what is the header available for unsigned ints
#if __cplusplus < 201103L
#include <stdint.h>
#else
#include <cstdint>
#endif

#include <cstdlib>
#include <string>
#include <map>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <sstream>

const static uint32_t fieldWidth = 2;

int main(int argc, char **argv) {

  std::map<std::string, uint32_t> bucket;
  bucket["EAX"] = 0x0; // initializing bucket with default values
  bucket["EBX"] = 0x0;
  bucket["ECX"] = 0x0;
  bucket["EDX"] = 0x0;

  if (argc >= 2) {
    switch (argc) {
    case 2:
      std::istringstream(argv[1]) >> std::hex >> bucket["EAX"];
      break;
    case 3:
      std::istringstream(argv[1]) >> std::hex >> bucket["EAX"];
      std::istringstream(argv[2]) >> std::hex >> bucket["EBX"];
      break;
    case 4:
      std::istringstream(argv[1]) >> std::hex >> bucket["EAX"];
      std::istringstream(argv[2]) >> std::hex >> bucket["EBX"];
      std::istringstream(argv[3]) >> std::hex >> bucket["ECX"];
      break;
    case 5:
      std::istringstream(argv[1]) >> std::hex >> bucket["EAX"];
      std::istringstream(argv[2]) >> std::hex >> bucket["EBX"];
      std::istringstream(argv[3]) >> std::hex >> bucket["ECX"];
      std::istringstream(argv[4]) >> std::hex >> bucket["EDX"];
      break;
    default:
      std::cout << "Too many arguments, exiting now\n";
      exit(EXIT_FAILURE);
    }

  } else {
    std::cout << "Not enough arguments, exiting now\n";
    exit(EXIT_FAILURE);
  }

  std::cout << "\nExecuting with this HEX values :\n\n";
  std::cout << "EAX = 0x" << std::hex << bucket["EAX"] << "\n"
            << "EBX = 0x" << std::hex << bucket["EBX"] << "\n"
            << "ECX = 0x" << std::hex << bucket["ECX"] << "\n"
            << "EDX = 0x" << std::hex << bucket["EDX"] << "\n";

  asm volatile("cpuid"
               : "=a"(bucket["EAX"]), "=b"(bucket["EBX"]), "=c"(bucket["ECX"]),
                 "=d"(bucket["EDX"])
               : "a"(bucket["EAX"]), "b"(bucket["EBX"]), "c"(bucket["ECX"]),
                 "d"(bucket["EDX"]));

  std::cout << "\nThe results:\n";
  for (std::map<std::string, uint32_t>::const_iterator k = bucket.begin();
       k != bucket.end(); ++k) {

    std::cout << "\n";
    std::cout << k->first << "\n";

    for (int c = 31; c >= 0; c--) {
      std::cout << std::setfill(' ') << std::setw(fieldWidth) << c;
    }

    std::cout << "\n";

    std::string s(std::bitset<32>(k->second).to_string());

    for (std::string::const_iterator j = s.begin(); j != s.end(); ++j) {
      std::cout << std::setfill(' ') << std::setw(fieldWidth) << *j;
    }

    std::cout << "\n";
  }
  std::cout << "\n";
  return (0);
}
