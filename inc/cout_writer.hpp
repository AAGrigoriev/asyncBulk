#pragma once

#include <iostream>
#include <memory>

#include "reader.hpp"
#include "worker.hpp"

namespace async {

class cout_writer final : public worker,
                          public std::enable_shared_from_this<cout_writer> {
public:
  cout_writer(const std::string &worker_name);

  static std::shared_ptr<cout_writer> create(const std::string &worker_name,
                                             reader &reader);

  void process() override;

private:
  std::mutex cout_mutex;
};

} // namespace asycn