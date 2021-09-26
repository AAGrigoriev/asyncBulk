#include "cout_writer.hpp"
#include "reader.hpp"

int main() {
  async::reader reader;

  reader.run("bla bla {bla bla}");
  
  return 0;
}