
/**
 @brief		Commonly used macros across the AirWatch SDK.
 @version 3.7.1
 @file		AWMacro.h
 */


#if defined(__GNUC__) && (__GNUC__ >= 4) && defined(__APPLE_CC__) && (__APPLE_CC__ >= 5465)
	#define AW_DEPRECATED_ATTRIBUTE __attribute__((deprecated))
#else
	#define AW_DEPRECATED_ATTRIBUTE
#endif

#ifndef __has_feature			// Optional of course.
	#define __has_feature(x) 0		// Compatibility with non-clang compilers.
#endif

#ifndef __has_extension
	#define __has_extension __has_feature // Compatibility with pre-3.0 compilers.
#endif    

#if __has_extension(attribute_deprecated_with_message)
	#ifndef AW_DEPRECATED_ATTRIBUTE_MESSAGE
		#define AW_DEPRECATED_ATTRIBUTE_MESSAGE(message) __attribute__((deprecated (message)))
	#endif
#else
	#ifndef AW_DEPRECATED_ATTRIBUTE_MESSAGE
		#define AW_DEPRECATED_ATTRIBUTE_MESSAGE(message) __attribute__((deprecated))
	#endif
#endif
