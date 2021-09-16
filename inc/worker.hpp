#pragma once

#include <atomic>
#include <condition_variable>
#include <mutex>
#include <queue>

#include "command.hpp"
#include "observer.hpp"
#include "thread_raii.hpp"

namespace async {

class worker final {

protected:
  virtual void process() = 0;

private:
  worker(std::string name);

protected:
  std::queue<command> command_;
  std::mutex que_mutex_;
  std::condition_variable cv_;
  std::atomic<bool> done_;

private:
  std::string worker_name_;
  std::vector<thread_raii> workers_;
};

} // namespace async