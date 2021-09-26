#include <fstream>
#include <utility>

#include "utils.hpp"
#include "file_writer.hpp"

namespace async {

file_writer::file_writer(const std::string &worker_name)
  : worker(worker_name) {}

std::shared_ptr<file_writer> file_writer::create(const std::string &name,
                                                 reader &reader) {
  auto shared_writer = std::make_shared<file_writer>(name);
  reader.subscribe(shared_writer);
  return shared_writer;
}

void file_writer::process() {
  while(!done_) {
    std::unique_lock lk(que_mutex_);
    cv_.wait(lk, [&] { return !command_.empty() || done_; });
    if (command_.empty()) {
      return;
    }
    auto log_command = std::move(command_.front());
    lk.unlock();

    std::ofstream log(worker_name_, std::ios::out);
    log << log_command;
  }
}

}