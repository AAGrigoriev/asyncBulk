#include "thread_raii.hpp"

namespace async {

template <typename func>
thread_raii::thread_raii(func &&func, thread_action action)
    : action_(action), thread_(func) {}

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