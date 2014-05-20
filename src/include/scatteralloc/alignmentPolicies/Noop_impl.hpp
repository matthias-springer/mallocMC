/*
  ScatterAlloc: Massively Parallel Dynamic Memory Allocation for the GPU.

  Copyright 2014 Institute of Radiation Physics,
                 Helmholtz-Zentrum Dresden - Rossendorf

  Author(s):  Carlchristian Eckert - c.eckert ( at ) hzdr.de

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

#pragma once

#include <boost/cstdint.hpp>
#include <string>

#include "Noop.hpp"
#include "../policy_malloc_hostclass.hpp"

namespace PolicyMalloc{
namespace AlignmentPolicies{

  class Noop{
    typedef boost::uint32_t uint32;

    public:

    static boost::tuple<void*,size_t> alignPool(void* memory, size_t memsize){
      return boost::make_tuple(memory,memsize);
    }

    PMMA_ACCELERATOR
    static uint32 applyPadding(uint32 bytes){
      return bytes;
    }

    static std::string classname(){
      return "Noop";
    }

  };

} //namespace AlignmentPolicies
} //namespace PolicyMalloc
