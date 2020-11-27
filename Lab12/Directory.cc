//
//  Lab 12
//  Directory.cc
//  Farhan Haziq
//

#include "Directory.h"
#include <iostream>
#include <stdexcept> // std::runtime_error

using namespace std;

// The directory iterator pre-fetches the name.  That is, readdir()
// is called when you first create the iterator, and upon ++.
//
// An end() iterator is designated by a null pointer for its DIR *.
// When readdir() fails, we set our pointer to null.

DirectoryIterator::DirectoryIterator(DIR *dp_arg, string k = string{}) : 
    dp(dp_arg), want(k)
    {
        ++*this;				// get that first entry
    }

DirectoryIterator &DirectoryIterator::operator++() {	// pre-increment
    while (auto p = readdir(dp)) {	// Read a directory entry.
        name = p->d_name;		    // C-string ⇒ C++ string
        if (wanted())		        // Stupid entry for current directory?
            continue;			    // Nobody wants that.
        return *this;			    // Everything else, I like!
    }
    dp = nullptr;			        // readdir failed; don’t try again.
    return *this;
}

string DirectoryIterator::operator*() const {
    return name;			// Fetched in a previous ++.
}

bool DirectoryIterator::operator!=(const DirectoryIterator &rhs) const {
    return dp != rhs.dp;
}

// fix #2
// also fix #3
bool DirectoryIterator::wanted(){
    return (name == "." || name == ".." || name.find(want) == string::npos) ? true : false;       
}


//////////////// Directory methods

// delegate to the 2nd constructor, compiler confused char* and string
Directory::Directory(const char dirname[]) 
    : Directory(dirname, string())
    {   
    }

Directory::Directory(const char dirname[], string s = string{}) 
    : dp(opendir(dirname)), m_s(s)
    {   
        // Fix #1, now with exception
        if (!dp){ throw std::runtime_error("failed to open directory '"s += dirname); }
    }



Directory::~Directory() {
    if (dp)				        // Only if opendir() succeeded:
	    closedir(dp);			//   should we close it.
}

Directory::iterator Directory::begin() const {
    return iterator(dp, m_s);
}

Directory::iterator Directory::end() const {
    return iterator();
}
