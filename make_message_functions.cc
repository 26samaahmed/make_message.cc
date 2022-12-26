#include "make_message_functions.h"

#include <iomanip>

bool HasMatchingFileExtension(const std::string& file_name,
                              const std::string& extension) {
  if (file_name.length() >= extension.length() &&
      (file_name.compare((file_name.length() - extension.length()),
                         extension.length(), extension)) == 0) {
    return true;
  }
  return false;
}

std::seed_seq rng_seed{1, 2, 3, 4, 5};

RandomNumberGenerator rng_01{0, 1, rng_seed};

RandomNumberGenerator rng_11{-1, 1, rng_seed};

RandomNumberGenerator rng_coin_flip{-1, 1, rng_seed};
double RandomDouble01() { return rng_01.next(); }
double RandomDouble11() { return rng_11.next(); }
bool CoinFlip() { return rng_coin_flip.next() > 0.0; }