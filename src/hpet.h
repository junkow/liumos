#include "generic.h"

class HPET {
 public:
  enum class TimerConfig : uint64_t {
    kUseLevelTriggeredInterrupt = 1 << 1,
    kEnable = 1 << 2,
    kUsePeriodicMode = 1 << 3,
    kSetComparatorValue = 1 << 6,
  } configuration_and_capability;
  struct RegisterSpace;

  void Init(RegisterSpace* registers);
  void SetTimerMs(int timer_index,
                  uint64_t milliseconds,
                  HPET::TimerConfig flags);

 private:
  RegisterSpace* registers_;
  uint64_t count_per_femtosecond_;
};

constexpr HPET::TimerConfig operator|=(HPET::TimerConfig& a,
                                       HPET::TimerConfig b) {
  a = static_cast<HPET::TimerConfig>(static_cast<uint64_t>(a) |
                                     static_cast<uint64_t>(b));
  return a;
}

constexpr HPET::TimerConfig operator&=(HPET::TimerConfig& a,
                                       HPET::TimerConfig b) {
  a = static_cast<HPET::TimerConfig>(static_cast<uint64_t>(a) &
                                     static_cast<uint64_t>(b));
  return a;
}

constexpr HPET::TimerConfig operator|(HPET::TimerConfig a,
                                      HPET::TimerConfig b) {
  return static_cast<HPET::TimerConfig>(static_cast<uint64_t>(a) |
                                        static_cast<uint64_t>(b));
}

constexpr HPET::TimerConfig operator&(HPET::TimerConfig a,
                                      HPET::TimerConfig b) {
  return static_cast<HPET::TimerConfig>(static_cast<uint64_t>(a) &
                                        static_cast<uint64_t>(b));
}

constexpr HPET::TimerConfig operator~(HPET::TimerConfig a) {
  return static_cast<HPET::TimerConfig>(~static_cast<uint64_t>(a));
}