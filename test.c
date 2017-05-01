#include <ayqu/streams.h>
#include <ayqu/values.h>
#include <ayqu/errors.h>


void main(int argc, char** argv) {
	ayqu_error_t* e = AYQU_ERROR_NONE;
	ayqu_stream_t* stream = NULL;
	if(e = ayqu_create(&stream))
		ayqu_assert(e);
	if(e = ayqu_option(stream, AYQU_OPTION_ALLOCATOR, malloc, free))
		ayqu_assert(e);
	if(e = ayqu_option(stream, AYQU_OPTION_ENCODING, AYQU_ENCODING_UTF8))
		ayqu_assert(e);
	if(e = ayqu_option(stream, AYQU_OPTION_NOISE_TOLERANT, true))
		ayqu_assert(e);
	if(e = ayqu_callback(stream, AYQU_CALLBACK_ALL, callback))
		ayqu_assert(e);
	const char* json = "\"string value I am\"null{key: value}-1 NaN [1, 2, 3]";
	if(e = ayqu_feed(stream, json, strlen(json)))
		ayqu_assert(e);
	if(e = ayqu_dispose(stream))
		ayqu_assert(e);
}

void callback(void* context, ayqu_callback_type_t type, ayqu_value_t* payload) {
	switch(type) {
		case AYQU_CALLBACK_ERROR:
			break;
		case AYQU_CALLBACK_DOCUMENT_START:
			break;
		case AYQU_CALLBACK_DOCUMENT_END:
			break;
		case AYQU_CALLBACK_VALUE:
			break;
		case AYQU_CALLBACK_OBJECT_START:
			break;
		case AYQU_CALLBACK_OBJECT_KEY:
			break;
		case AYQU_CALLBACK_OBJECT_END:
			break;
		case AYQU_CALLBACK_ARRAY_START:
			break;
		case AYQU_CALLBACK_ARRAY_END:
			break;
		case AYQU_CALLBACK_NOISE:
			break;
		default:
			assert(("unknown callback type", false));
			break;
	}
}
