#pragma once

#include "error.h"
#include "value.h"

struct ayqu_stream;
typedef struct ayqu_stream ayqu_stream_t;

enum ayqu_stream_option {
	AYQU_OPTION_ALLOCATOR,
	AYQU_OPTION_ENCODING,
	AYQU_OPTION_ALLOW_COMMENTS,
};
typedef enum ayqu_stream_option ayqu_stream_option_t;

enum ayqu_encoding {
	AYQU_ENCODING_ASCII,
	AYQU_ENCODING_UTF8,
	AYQU_ENCODING_UTF16LE,
	AYQU_ENCODING_UTF16BE,
	AYQU_ENCODING_UTF32LE,
	AYQU_ENCODING_UTF32BE,
};
typedef enum ayqu_encoding ayqu_encoding_t;

enum ayqu_event {
	AYQU_EVENT_ERROR,
	AYQU_EVENT_DOCUMENT_START,
	AYQU_EVENT_DOCUMENT_END,
	AYQU_EVENT_VALUE,
	AYQU_EVENT_OBJECT_START,
	AYQU_EVENT_OBJECT_KEY,
	AYQU_EVENT_OBJECT_END,
	AYQU_EVENT_ARRAY_START,
	AYQU_EVENT_ARRAY_END,
};
typedef enum ayqu_event ayqu_event_t;

typedef void (*ayqu_handler_t)(void* context, ayqu_event_t, ayqu_value_t* payload);

ayqu_error_t* ayqu_create(ayqu_stream_t** stream);
ayqu_error_t* ayqu_dispose(ayqu_stream_t* stream);
ayqu_error_t* ayqu_option(ayqu_stream_t* stream, ayqu_stream_option_t option, ...);
ayqu_error_t* ayqu_handler(ayqu_stream_t* stream, ayqu_handler_t handler, void* context);
ayqu_error_t* ayqu_feed(ayqu_stream_t* stream, const uint8_t* data, size_t length);
