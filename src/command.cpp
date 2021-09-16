#include "command.hpp"

namespace async {

void command::push_command(std::string &&command) {
  if (command_.size() > 0) {
    std::chrono::system_clock::time_point time_stamp;
    time_ = std::to_string(time_stamp.time_since_epoch().count());
  }
  command_.push_back(std::move(command));
}

std::string &command::get_time() const { return time_; }

std::vector<std::string> &command::get_command() const { return command_; }

bool command::empty() const { return command_.empty(); }

} // namespace async