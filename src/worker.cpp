#include <mutex>

#include "worker.hpp"

namespace async {

worker::worker(const std::string &worker_name) : worker_name_(worker_name) {}

void worker::create_process() { workers_.emplace_back(&worker::process, this); }

void worker::update(const command &command) {
  {
    std::lock_guard lc(que_mutex_);
    command_.push(command);
  }
  cv_.notify_one();
}

worker::~worker() {
  done_ = true;
  cv_.notify_all();
}

} // namespace async