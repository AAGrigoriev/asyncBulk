#pragma once

#include <memory>
#include <thread>

#include "reader.hpp"
#include "worker.hpp"


namespace async {

class file_writer final : public worker,
                          public std::enable_shared_from_this<file_writer> {
public:
  static std::shared_ptr<file_writer> create(const std::string& name, reader& reader);

  void process()        override;
  void create_process() override;

  ~file_writer();

private:
  // todo 1: private constructor.
  // https://stackoverflow.com/questions/8147027/how-do-i-call-stdmake-shared-on-a-class-with-only-protected-or-private-const
  file_writer(const std::string& worker_name);

private:
  std::vector<std::thread> threads_;
};
} // namespace async