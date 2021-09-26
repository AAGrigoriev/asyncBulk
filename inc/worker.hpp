#pragma once

#include <atomic>
#include <condition_variable>
#include <mutex>
#include <queue>

#include "command.hpp"
#include "observer.hpp"


namespace async {
  
class worker : public i_observer<command> {
public:
  void update(const command& command) override;
  
  virtual void process()        = 0;
  virtual void create_process() = 0;
  
  virtual ~worker() = default;

protected:
  worker(const std::string& name);

protected:
  std::queue<command> command_;
  std::mutex que_mutex_;
  std::condition_variable cv_;
  std::atomic<bool> done_;
  std::string worker_name_;
};

} // namespace async