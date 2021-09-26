#include <chrono>

#include "cout_writer.hpp"
#include "reader.hpp"



int main() {
   async::reader reader;
   std::shared_ptr<async::cout_writer> cout_writer = async::cout_writer::create("cout_writer", reader);
  // cout_writer->create_process();

  // for (auto i = 0; i < 10000; ++i) {
  //   reader.run("bla bla bla { bla bla }");
  // }

  // using namespace std::chrono_literals;
  // std::this_thread::sleep_for(2000ms);
  
  // async::worker* worker = new async::cout_writer("faf");
  // worker->create_process();
  // std::shared_ptr<async::cout_writer> cout_writer = async::cout_writer::create("cout_worker", reader);
  // cout_writer->create_process();
  // //cout_writer->create_process(); 
  // //reader.run("bla bla {bla bla}");
  
  return 0;
}