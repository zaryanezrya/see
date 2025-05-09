#ifndef SEE_PAIR
#define SEE_PAIR

#define generic_pair(FstType, FstName, SndType, SndName, PairType)             \
  typedef struct PairType {                                                    \
    FstType FstName;                                                           \
    SndType SndName;                                                           \
  } PairType;

#endif
