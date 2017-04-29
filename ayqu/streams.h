#include "errors.h"

struct ayqu_stream_t;

enum ayqu_stream_option_t {
	AYQU_OPTION_ENCODING,
	AYQU_OPTION_ALLOW_COMMENTS,
	AYQU_OPTION_NOISE_TOLERANT,
	AYQU_OPTION_ALLOCATOR,
};

enum ayqu_encoding_t {
	AYQU_ENCODING_ASCII,
	AYQU_ENCODING_UTF8,
	AYQU_ENCODING_UTF16LE,
	AYQU_ENCODING_UTF16BE,
	AYQU_ENCODING_UTF32LE,
	AYQU_ENCODING_UTF32BE,
};

enum ayqu_callback_type_t {
	AYQU_CALLBACK_ERROR          = (1 << 0),
	AYQU_CALLBACK_DOCUMENT_START = (1 << 1),
	AYQU_CALLBACK_DOCUMENT_END   = (1 << 2),
	AYQU_CALLBACK_VALUE          = (1 << 3),
	AYQU_CALLBACK_OBJECT_START   = (1 << 4),
	AYQU_CALLBACK_OBJECT_KEY     = (1 << 5),
	AYQU_CALLBACK_OBJECT_END     = (1 << 5),
	AYQU_CALLBACK_ARRAY_START    = (1 << 6),
	AYQU_CALLBACK_ARRAY_END      = (1 << 7),
	AYQU_CALLBACK_NOISE          = (1 << 8),
	AYQU_CALLBACK_ALL            = 0xFFFFFFFF,
};

typedef void (*ayqu_callback_t)(void* context, ayqu_callback_type_t, ayqu_value_t payload);

ayqu_error_code_t ayqu_create(ayqu_stream_t** stream);
ayqu_error_code_t ayqu_dispose(ayqu_stream_t* stream);
ayqu_error_code_t ayqu_option(ayqu_stream_t* stream, ayqu_stream_option_t option, ...);
ayqu_error_code_t ayqu_callback(ayqu_callback_type_t callbacks, ayqu_callback_t callback, void* context);
ayqu_error_code_t ayqu_feed(ayqu_stream_t* stream, int8_t* data, size_t length);
