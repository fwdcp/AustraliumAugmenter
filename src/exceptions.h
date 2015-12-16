/**
 *  exceptions.h
 *  AustraliumAugmenter project
 *
 *  Copyright (c) 2015 Forward Command Post
 *  MIT License
 *  http://opensource.org/licenses/MIT
 *
 */

#pragma once

#include <sstream>
#include <string>

#ifdef _WIN32
#define noexcept _NOEXCEPT
#endif

class module_not_loaded : public std::exception {
public:
	module_not_loaded(const char *name) noexcept;
	virtual const char *what() const noexcept;
private:
	const char *moduleName;
};

inline module_not_loaded::module_not_loaded(const char *name) noexcept{
	moduleName = name;
}

inline const char *module_not_loaded::what() const noexcept{
	std::string s;
	std::stringstream ss;

	ss << "Module " << moduleName << " not loaded!\n";
	ss >> s;

	return s.c_str();
}
