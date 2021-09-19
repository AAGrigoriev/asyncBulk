#pragma once;

#include <thread>

namespace async {

class thread_raii final {
public:
  enum thread_action { join, detach };

public:
  template <typename Func> thread_raii(Func &&f, thread_action action);

  template <typename Func, typename... Args>
  explicit thread_raii(Func &&f, Args &&...args, thread_action action);

  ~thread_raii();

private:
  std::thread thread_;
  thread_action action_;
};

} // namespace async