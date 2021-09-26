#include <utility>

#include "thread_raii.hpp"

namespace async {

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