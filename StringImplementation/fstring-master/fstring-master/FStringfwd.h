#ifndef FSTRINGFWD_H
#define FSTRINGFWD_H
namespace lshaocong {
template<typename T>
class FAllocator;

template<typename Alloc>
class FString;

typedef FAllocator<char> FAlloc;
typedef FString<FAlloc> fstring;
}
#endif