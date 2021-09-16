#pragma once;

#include <thread>

namespace async {
    
class thread_raii final {
public:
  enum thread_action { join, detach };

public:
  template <typename func> thread_raii(func &&f, thread_action action);

  ~thread_raii();
private:
  std::thread thread_;
  thread_action action_;
};

} // namespace async