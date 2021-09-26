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
  virtual void process() = 0;

protected:
  worker(const std::string &name);

protected:
  std::queue<command> command_;
  std::mutex que_mutex_;
  std::condition_variable cv_;
  std::atomic<bool> done_;
  std::string worker_name_;

private:
  std::vector<thread_raii> workers_;
};

} // namespace async