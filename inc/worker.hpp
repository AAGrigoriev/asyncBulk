#pragma once

#include <atomic>
#include <condition_variable>
#include <mutex>
#include <queue>

#include "command.hpp"
#include "observer.hpp"
#include "thread_raii.hpp"

namespace async {
class worker : public i_observer<command> {
public:
  void create_process();
  void update(const command &command) override;
  virtual ~worker();

protected:
  worker(const std::string &name);
  virtual void process() = 0;

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