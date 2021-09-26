#include "worker.hpp"

#include <functional>
#include <mutex>


namespace async {

worker::worker(const std::string& worker_name) : worker_name_(worker_name) 
  {}


void worker::update(const command& command) {
  {
    std::lock_guard lc(que_mutex_);
    command_.push(command);
  }
  cv_.notify_one();
}
} // namespace async