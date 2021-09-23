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

void cout_writer::process() {
  while (!done_) {
    std::unique_lock lc(que_mutex_);
    cv_.wait(lk, [] { return !command_.empty() || done; });
    if (command_.empty) {
      return;
    }
    auto command_to_execute = std::move(command_.front());
    command_.pop();
    lk.unlock();
    {
      std::lock_guard lock(cout_mutex);
      std::cout << commant_to_execute;
    }
  }
}

} // namespace async