#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ayqu/stream.h>
#include <ayqu/value.h>
#include <ayqu/error.h>


void handler(void* context, ayqu_event_t type, ayqu_value_t* payload);


int main(int argc, char** argv) {
	ayqu_error_t* e = NULL;
	ayqu_stream_t* stream = NULL;
	if((e = ayqu_create(&stream)))
		ayqu_assert(e, "failed to create stream");
	if((e = ayqu_option(stream, AYQU_OPTION_ALLOCATOR, malloc, free)))
		ayqu_assert(e, "failed to set allocator option");
	if((e = ayqu_option(stream, AYQU_OPTION_ENCODING, AYQU_ENCODING_UTF8)))
		ayqu_assert(e, "failed to set encoding option");
	if((e = ayqu_handler(stream, handler, NULL)))
		ayqu_assert(e);
	const char* json = "\"string value I am\"null{key: value}-1 [1, 2, 3]";
	if((e = ayqu_feed(stream, (const uint8_t*)json, strlen(json))))
		ayqu_assert(e);
	if((e = ayqu_dispose(stream)))
		ayqu_assert(e);
	return 0;
}


void handler(void* context, ayqu_event_t type, ayqu_value_t* payload) {
	switch(type) {
		case AYQU_EVENT_ERROR:
			break;
		case AYQU_EVENT_DOCUMENT_START:
			break;
		case AYQU_EVENT_DOCUMENT_END:
			{
				ayqu_value_type_t type;
				if(ayqu_value_type(payload, &type)) {
					printf("failed to get a value type for the json document\n");
				}
				else {
					printf("got a json document %d", type);
				}
			}
			break;
		case AYQU_EVENT_VALUE:
			break;
		case AYQU_EVENT_OBJECT_START:
			break;
		case AYQU_EVENT_OBJECT_KEY:
			break;
		case AYQU_EVENT_OBJECT_END:
			break;
		case AYQU_EVENT_ARRAY_START:
			break;
		case AYQU_EVENT_ARRAY_END:
			break;
		default:
			printf("unknown event");
			exit(1);
			break;
	}
}
