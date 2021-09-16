#pragma once

#include <functional>
#include <string>

#include "command.hpp"
#include "observer.hpp"

namespace async {

class reader final : public i_observable<command> {
public:
  reader(std::size_t command_size = 1);

  void run(const std::string& data);

private:
  std::function<void(reader *, std::string&&)> state_f_;
  std::size_t                                  command_size_;
  command                                      command_;

  // Функции переключения режимов парсинга.
  void plain(std::string&&);
  void block(std::string&&);
  void nested(std::string&&);

  // Функция отправки сообщений.
  void flush_command();
};

} // namespace async