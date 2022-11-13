/*
 * @author liangshaocong1994@gmail.com
 * @date 2018-11-04
 */

#include <FString.h>
#include <assert.h>
#include <string.h>

namespace lshaocong
{
const size_t FACTOR = 2;
template <typename Alloc>
char FString<Alloc>::Rep::emptyString[sizeof(FString<Alloc>::RepBase)+sizeof(char*)]= {0,0,0,0};
template <typename Alloc>
const typename FString<Alloc>::size_type FString<Alloc>::npos;

template <typename Alloc>
char* FString<Alloc>::Rep::Create(size_t len, const Alloc &alloc) {
  size_t __capacity = len*2;
  char *__raw = alloc.allocate(sizeof(Rep) + __capacity);

  Rep* __rep = reinterpret_cast<Rep*>(__raw);
  __rep->capacity_ = __capacity;
  __rep->size_ = len;
  __rep->refcount_++;

  return __raw;
}

template <typename Alloc>
template <typename ForwardIterator>
char* FString<Alloc>::Construct(ForwardIterator begin, ForwardIterator end, const Alloc &a) {
  char *raw = Rep::Create(end-begin, a);
  char *__real_data = raw + sizeof(Rep);
  memcpy(__real_data, begin, end-begin);
  return __real_data;
}
template <typename Alloc>
char* FString<Alloc>::Construct(size_type n, const char c, const Alloc &alloc){
  char *raw = Rep::Create(n, alloc);
  char *__real_data = raw+sizeof(Rep);
  for(size_t i = 0; i < n; ++i){
    __real_data[i] = c;
  }
  return __real_data;
}

template <typename Alloc>
FString<Alloc>::FString(size_t count, const char ch, const Alloc &alloc):dataPlus_(Construct(count, ch, alloc), alloc){
}

template <typename Alloc>
FString<Alloc>::FString(const char *src, const Alloc &alloc):dataPlus_(Construct(src, src+strlen(src), alloc), alloc){
}

} // namespace lshaocong
