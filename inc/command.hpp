#pragma once

#include <chrono>
#include <iostream>
#include <string>
#include <vector>

namespace async {

class command final {
public:
  void push_command(std::string &&command);

  std::string &get_time() const;

  std::vector<std::string> &get_command() const;

  bool empty() const;

  friend std::ostream &operator<<(std::ostream &a_osOut,
                                  const command &command);

private:
  std::vector<std::string> command_;
  std::string time_;
};

} // namespace async