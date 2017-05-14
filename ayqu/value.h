#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>


struct ayqu_value;
typedef struct ayqu_value ayqu_value_t;

enum ayqu_value_type {
	AYQU_VALUE_TYPE_NUMBER,
	AYQU_VALUE_TYPE_STRING,
	AYQU_VALUE_TYPE_BOOLEAN,
	AYQU_VALUE_TYPE_ARRAY,
	AYQU_VALUE_TYPE_OBJECT,
	AYQU_VALUE_TYPE_NULL,
};
typedef enum ayqu_value_type ayqu_value_type_t;

//TODO https://en.wikipedia.org/wiki/C_data_types

/**
 * Returns the type of specified payload.
 */
ayqu_error_t* ayqu_value_type(ayqu_value_t* payload, ayqu_value_type_t* value);

/**
 * Returns true if the number value stored in the payload doesn't have a fractional part.
 */
ayqu_error_t* ayqu_value_number_is_integer(ayqu_value_t* payload, bool* value);

/**
 * Returns true if the number value stored in the payload is negative
 */
ayqu_error_t* ayqu_value_number_is_negative(ayqu_value_t* payload, bool* value);

/**
 * Returns the payload as int.
 */
ayqu_error_t* ayqu_value_int(ayqu_value_t* payload, int* value);

/**
 * Returns the payload as unsigned int.
 */
ayqu_error_t* ayqu_value_uint(ayqu_value_t* payload, unsigned int* value);

/**
 * Returns the payload as long.
 */
ayqu_error_t* ayqu_value_long(ayqu_value_t* payload, long* value);

/**
 * Returns the payload as unsigned long.
 */
ayqu_error_t* ayqu_value_ulong(ayqu_value_t* payload, unsigned long* value);

/**
 * Returns the payload as int8_t.
 */
ayqu_error_t* ayqu_value_int8(ayqu_value_t* payload, int8_t* value);

/**
 * Returns the payload as uint8_t.
 */
ayqu_error_t* ayqu_value_uint8(ayqu_value_t* payload, uint8_t* value);

/**
 *
 */
//TODO design the string retrieval function signature.
ayqu_error_t* ayqu_value_string(ayqu_value_t* payload, const char**);

/**
 *
 */
ayqu_error_t* ayqu_value_bool(ayqu_value_t* payload, bool* value);

/**
 * Returns number of elements an array has.
 */
ayqu_error_t* ayqu_value_array_length(ayqu_value_t* payload, size_t* length);

/**
 * Returns an ayqu_value_t representing the element of array at specified index.
 */
ayqu_error_t* ayqu_value_array_at(ayqu_value_t* payload, size_t index, ayqu_value_t** value);

/**
 * Returns the number of keys an object has.
 */
ayqu_error_t* ayqu_value_object_keys(ayqu_value_t* payload, size_t* length);

/**
 * Returns an ayqu_value_t representing the key string at a given index.
 * Use ayqu_value_string to retrieve the literal value.
 */
ayqu_error_t* ayqu_value_object_key_at(ayqu_value_t* payload, size_t index, ayqu_value_t** value);

/**
 * Returns an ayqu_value_t representing the object associated with the key at a given index.
 * Use ayqu_value_string to retrieve the literal value.
 */
ayqu_error_t* ayqu_value_object_value_at(ayqu_value_t* payload, size_t index, ayqu_value_t** value);
