#include "file_writer.hpp"

#include <fstream>
#include <utility>


namespace async {

std::shared_ptr<file_writer> file_writer::create(const std::string& name, reader& reader) {
  auto shared_writer = std::shared_ptr<file_writer>(new file_writer(name));
  reader.subscribe(shared_writer);
  return shared_writer;
}


file_writer::file_writer(const std::string& worker_name)
  : worker(worker_name) {
  create_process();
}


void file_writer::process() {
  while(!done_) {
    std::unique_lock lk(que_mutex_);
    cv_.wait(lk, [&] { return !command_.empty() || done_; });
    if (command_.empty()) {
      return;
    }
    auto log_command = std::move(command_.front());
    command_.pop();
    lk.unlock();

    std::ofstream log(worker_name_, std::ios::out);
    log << log_command;
  }
}


void file_writer::create_process() {
  threads_.emplace_back(&file_writer::process, this);
}


file_writer::~file_writer() {
  done_ = true;
  cv_.notify_all();
  for (auto&& thread : threads_) {
    thread.join();
  }
}
} // namespace async