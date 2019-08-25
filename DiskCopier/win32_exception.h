#pragma once
#include <exception>
#include <string>
#include <sstream>

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>

/**
 * \brief A win32 error exception wrapper.
 * It takes an error from the C windows api and throws it as an exception.
 */
class win32_exception : std::exception
{
	std::string message_;
public:
	/**
	 * \brief Constructs a win32_exception object.
	 * \param error_code An error code gotten with GetLastError()
	 * \param message A message to be accommodated by the error code.
	 */
	win32_exception(const DWORD error_code, const std::string_view message)
	{
		std::stringstream ss;
		ss << message;
		ss << "\nError code: " << error_code << '\n';

		message_ = ss.str();
	}

	/**
	 * \brief Explains the exception.
	 * \return A formatted string detailing the error.
	 */
	[[nodiscard]] char const* what() const override
	{
		return message_.c_str();
	}
};

