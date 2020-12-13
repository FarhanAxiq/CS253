//
//  hasher.h
//  Farhan Haziq
//

#ifndef HASHER_H_INCLUDED
#define HASHER_H_INCLUDED

#include <string>

// Some sample hash functions
//
// They should return unsigned values, as equally-distributed as
// possible over the range of unsigned values.

class Hasher {
  public:
    unsigned operator()(int n) const {
	    return n;			// That was easy!
    }

    // Ex 3
    unsigned operator()(double d) const {
        return operator()(std::to_string(d));
    }

    // The FNV-1a hashing algorithm.
    // https://wikipedia.org/wiki/Fowler–Noll–Vo_hash_function#FNV-1a_hash
    unsigned operator()(const std::string &s) const {
	    unsigned sum = 0x811c9dc5;
	    for (char c : s) {
	        sum ^= static_cast<unsigned char>(c);
	        sum *= 16777619;
	    }   
	    return sum;
    }
};

#endif /* HASHER_H_INCLUDED */
