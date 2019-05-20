#include <iostream>
#include "src/HashMap.h"
using namespace std;

//  s is string of data to be hashed, recordLen is strlen(s)
unsigned long hash2(char* s, int tableSize, int bucketSize, int recordLen) {
  unsigned long orVal;
  unsigned long remainder;
  for (orVal = 0; strlen(s) >= 4; s += 4) orVal ^= *reinterpret_cast<unsigned long*>(s);
  if (strlen(s) != 0) {
    strcpy(reinterpret_cast<char*>(&remainder),s);
    orVal ^= remainder;
  }
  return (orVal % tableSize) * bucketSize * recordLen;
}

int main() {
  HashMap *newHashMap = new HashMap();
  char* sample = "thisfdsaferw strifdsarwvn";

  cout << "Sample Hash of 'this string': " << hash2(sample, 50, 4, strlen(sample)) << endl;
  cout << "HashMap a: " << newHashMap->a << ", b: " << newHashMap->b << endl;
  std::cout << "Hello, World!" << std::endl;
  return 0;
}


unsigned long File::hash(char *s) {
  unsigned long xor = 0, pack;
  int i, j, slength; // exclude trailing blanks;
  for (slength = strlen(s); isspace(s[slength-1]); slength--);
  for (i = 0; i < slength; ) {
    for (pack = 0, j = 0; ; j++, i++) {
      pack |= (unsigned long) s[i]; // include s[i] in the
      if (j == 3 || i == slength - 1) { // rightmost byte of pack;
        i++;
        break;
    }
      pack <<= 8;
    } // xor at one time 8 bytes from s;
    xor ^= pack; // last iteration may put less
} // than 8 bytes in pack;
  return (xor % tableSize) * bucketSize * recordLen;
}// return byte position of home bucket for s;