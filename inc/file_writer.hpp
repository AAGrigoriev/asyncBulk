#pragma once

#include <memory.h>

#include "reader.hpp"
#include "worker.hpp"

namespace async {

class file_writer : public worker,
                    public std::enable_shared_from_this<file_writer> {
public:
  static std::shared_ptr<file_writer> create(const std::string &worker_name,
                                             std::shared_ptr<reader> &reader);

protected:
  void process() override;

private:
  file_writer(const std::string &worker_name);
};
} // namespace async