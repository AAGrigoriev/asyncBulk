#pragma once

#include <chrono>
#include <string>
#include <vector>

namespace async {

class command final {

  void push_command(std::string &&command);

  std::string &get_time() const;

  std::vector<std::string> &get_command() const;

  bool empty() const;

private:
  std::vector<std::string> command_;
  std::string time_;
};

} // namespace async