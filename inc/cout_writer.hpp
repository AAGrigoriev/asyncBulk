#pragma once

#include <iostream>
#include <memory>

#include "reader.hpp"
#include "worker.hpp"

namespace asycn {

class cout_writter final : public worker,
                           public std::enable_shared_from_this<cout_writter> {
public:
  static std::shared_ptr<cout_writter> create(const std::string &worker_name,
                                              std::shared_ptr<reader> &reader);

protected:
  void process() override;

private:
  cout_writter(const std::string &worker_name);
};

} // namespace asycn