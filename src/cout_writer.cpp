#include "cout_writer.hpp"

namespace async {

cout_writer::cout_writer(const std::string &worker_name)
    : worker(worker_name) {}

std::shared_ptr<cout_writer> create(const std::string &name,
                                    std::shared_ptr<reader> &reader) {
  auto shared_writer = std::make_shared<cout_writer>(name);
  reader->subscribe(shared_writer);
  return shared_writer;
}

void cout_writer::process() {}

} // namespace async