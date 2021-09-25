#include <utility>

#include "thread_raii.hpp"

namespace async {

template <typename Func>
thread_raii::thread_raii(Func &&func, thread_action action)
    : action_(action), thread_(std::move(func)) {}

template <typename Func, typename... Args>
thread_raii::thread_raii(Func &&f, Args &&...args, thread_action action)
    : action_(action), thread_(std::move(f), std::forward<Args>(args)...) {}

thread_raii::~thread_raii() {
  switch (action_) {
  case join:
    thread_.join();
  case detach:
    thread_.detach();
  default:
    break;
  }
}

} // namespace async