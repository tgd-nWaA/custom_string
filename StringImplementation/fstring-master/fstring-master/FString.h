/*
 * @author liangshaocong1994@gmail.com
 * @date 2018-11-03
 */

#ifndef FSTRING_H
#define FSTRING_H

#include <FAllocator.h>

#include <atomic>
#include <assert.h>
#include <stdlib.h>
#include <iostream>
namespace detail {
#define FSTRING_ASSERT(x) \
  if (!(x))               \
    abort();
} // namespace detail
namespace lshaocong {

typedef std::atomic_int AtomicInt;

template<typename Alloc>
class FString {
 private:
  typedef size_t size_type;
  typedef Alloc allocator_type;
  typedef char value_type;
  typedef char *iterator;
  typedef char &reference;
  typedef const char &const_reference;

 private:
  template<typename ForwardIterator>
  static char *Construct(ForwardIterator begin, ForwardIterator end, const Alloc &a);
  static char *Construct(size_type n, const char c, const Alloc &alloc);

  struct RepBase {
    RepBase() : refcount_(0), size_(0), capacity_(0) {}
    void increment() { refcount_++; }
    AtomicInt refcount_;
    size_t size_;
    size_t capacity_;
  };

  struct Rep : public RepBase {
    static char emptyString[];
    static char* Create(size_type len, const Alloc &alloc);
    Rep() = default;
    Rep(char ch, size_type count) {
    }
    Rep(const char *data, size_type count, const Alloc &alloc) {
    }

    void dispose(const Alloc &__alloc, char *data) {
      if (data != emptyString) {
        if (--this->refcount_ == 0) {
          destroy(__alloc, data);
        }
      }
    }

    void destroy(const Alloc &__alloc, char *data) {
      __alloc.deallocate(data);
    }
  };

  struct AllocHider : public Alloc {
    AllocHider(char *data, const Alloc &alloc) : Alloc(alloc), data_(data) {}
    char *data_;
  };

  mutable AllocHider dataPlus_;

  char *_M_Data() const {
    return dataPlus_.data_;
  }

  Rep& _M_Rep() const {
    return *(reinterpret_cast<Rep*>(_M_Data())-1);
  }
 public:
  static const size_type npos = static_cast<size_type>(-1);

  FString() : dataPlus_(Rep::emptyString+sizeof(RepBase), Alloc()) {}
  FString(const char *str, size_t count, Alloc alloc = FAllocator<char>());
  FString(const char *str, const Alloc &alloc = FAllocator<char>());
  FString(size_t count, const char ch, const Alloc &alloc = FAllocator<char>());
  ~FString() {
    _M_Rep().dispose(dataPlus_, _M_Data()-sizeof(Rep));
  }

  FString &assign(size_t count, char ch);
  FString &assign(const FString &src);
  FString &assign(const char *src, size_t count);

  size_t size() const {
    return _M_Rep().size_;
  }

  size_t capacity() const {
    return _M_Rep().capacity_;
  }
};
} // namespace lshaocong
#endif //FSTRING_H
