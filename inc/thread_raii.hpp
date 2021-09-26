#pragma once

#include <thread>

namespace async {

class thread_raii final {
public:
  enum thread_action { join, detach };

public:
  template <typename Func, typename... Args>
  thread_raii(Func &&f, Args &&...args) 
  : action_(join), thread_(std::move(f), std::forward<Args>(args)...) {}
  
  thread_raii(thread_raii&&) = default;
  ~thread_raii();

private:
  thread_action action_;
  std::thread   thread_;
};

} // namespace async