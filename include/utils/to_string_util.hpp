#ifndef TO_STRING_UTIL_HPP
#define TO_STRING_UTIL_HPP

#include <string>
#include <sstream>

// General template for most types
template <typename T>
std::string to_string_custom(const T& value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

// Specialization for std::string
template <>
std::string to_string_custom<std::string>(const std::string& value) {
    return value;  // Directly return the string
}

// Specialization for const char* (C-style strings)
/*template <>
std::string to_string_custom<const char*>(const char* value) {
    ---------------------------------------------------------------------------------------------------------------------------------------------------------------------
    return std::string(value);  // Convert C-style string to std::string
}*/

#endif // TO_STRING_UTIL_HPP

