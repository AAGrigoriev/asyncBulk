#pragma once

#include <memory.h>

#include "reader.hpp"
#include "worker.hpp"

namespace async
{

  class file_writer : public worker,
                      public std::enable_shared_from_this<file_writer> {
  
  public:
  // todo 1: private constructor. 
  // https://stackoverflow.com/questions/8147027/how-do-i-call-stdmake-shared-on-a-class-with-only-protected-or-private-const
    file_writer(const std::string &worker_name);
    
    static std::shared_ptr<file_writer> create(const std::string &name,
                                               reader &reader);

  protected:
    void process() override;
  };
} // namespace async