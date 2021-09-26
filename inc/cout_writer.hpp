#pragma once

#include <memory>
#include <thread>

#include "reader.hpp"
#include "worker.hpp"


namespace async {

class cout_writer final : public worker,
                          public std::enable_shared_from_this<cout_writer> {
public:
  static std::shared_ptr<cout_writer> create(const std::string& name, reader& reader);

  void process()        override;
  void create_process() override;

 ~cout_writer();

private:
  cout_writer(const std::string& worker_name);

private:
  std::mutex               cout_mutex_; ///< mutex для вывода в cout.
  /// todo: Очень важно, чтобы потоки распологались не в базовом классе. Из за порядка уничтожения от производных к базовому.
  /// Это приводит к дублированию кода. Надо будет переделать.
  std::vector<std::thread> threads_;    ///< Вектор потоков для работы с функцией process(). 
};

} // namespace asycn