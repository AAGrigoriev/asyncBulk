#include "cout_writer.hpp"

#include <thread>
#include <iostream>


namespace async {

std::shared_ptr<cout_writer> cout_writer::create(const std::string& name, reader& reader, std::ostream& stream) {
  /// todo: Лучше использовать make_shared, но нужно геммороится из-за приватного конструктора.
  auto shared_writer = std::shared_ptr<cout_writer>(new cout_writer(name, stream));
  reader.subscribe(shared_writer);
  return shared_writer;
}


cout_writer::cout_writer(const std::string& worker_name, std::ostream& stream)
    : worker(worker_name), stream_(stream) {
  create_process();
}


void cout_writer::process() {
  while (!done_) {
    std::unique_lock lk(que_mutex_);
    cv_.wait(lk, [&] { return !command_.empty() || done_; });
    if (command_.empty()) {
      return;
    }
    auto command_to_execute = std::move(command_.front());
    command_.pop();
    lk.unlock();
    {
      std::lock_guard lock(cout_mutex_);
      stream_ << command_to_execute << std::endl;
    }
  }
}


void cout_writer::create_process() {
  threads_.emplace_back(&cout_writer::process, this);
}


cout_writer::~cout_writer() {
  done_ = true;
  cv_.notify_all();
  for (auto&& thread : threads_) {
    thread.join();
  }
}
} // namespace async