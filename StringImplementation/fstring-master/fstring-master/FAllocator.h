/*
 * @author liangshaocong1994@gmail.com
 * @date 2018-11-04
 */

#ifndef FALLOCATOR_H
#define FALLOCATOR_H
#include <cstdio>
#include <cstdlib>

/**
 * a stateless allocator
 */
namespace lshaocong{
template <typename Tp>
class FAllocator{
 public:
  FAllocator<Tp>() = default;
  ~FAllocator<Tp>(){}
  Tp* allocate(const size_t nb) const {
    return static_cast<Tp*>(malloc(nb* sizeof(Tp)));
  }

  void deallocate(Tp *ptr) const {
    free(static_cast<void*>(ptr));
  }
};

}
#endif //FSTRING_FALLOCATOR_H
