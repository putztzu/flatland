//******************************************************************************
// $Header$
// Copyright (C) 1998-2002 Flatland Online Inc.
// All Rights Reserved. 
//******************************************************************************

#include "tokens.h"

// Attribute definition structure.

struct attr_def {
	int token;
	int value_type;
	void *value_ptr;
	bool required;
};

// Tag definition class.

struct tag_def {
	int token;
	attr_def *attr_def_list;
	int attributes;
	bool is_start_tag;
};

// Array of flags indicating which attributes of a tag have been parsed.

#define MAX_ATTRIBUTES	32
extern bool parsed_attribute[MAX_ATTRIBUTES];

// Value definition class.

struct value_def {
	const char *str;
	int value;
};

// Initialisation function.

void
init_parser(void);

// URL and conversion functions.

void
split_URL(const char *URL, string *URL_dir, string *file_name,
		  string *entrance_name);

string
create_URL(const char *URL_dir, const char *file_name);

string
encode_URL(const char *URL);

string
decode_URL(const char *URL);

string
URL_to_file_path(const char *URL);

void
parse_identifier(const char *identifier, string &style_name, 
				 string &object_name);

bool
not_single_symbol(char ch, bool disallow_dot);

bool
not_double_symbol(char ch1, char ch2, bool disallow_dot_dot);

bool
string_to_single_symbol(const char *string_ptr, char *symbol_ptr,
						bool disallow_dot);

bool
string_to_double_symbol(const char *string_ptr, word *symbol_ptr,
						bool disallow_dot_dot);

bool
string_to_symbol(const char *string_ptr, word *symbol_ptr, 
				 bool disallow_dot_dot);

char *
version_number_to_string(unsigned int version_number);

// File functions.

bool
open_zip_archive(const char *file_path, const char *file_name);

bool
open_blockset(const char *blockset_URL, const char *blockset_name);

void
close_zip_archive(void);

bool
push_file(const char *file_path, const char *file_URL, bool text_file);

bool
push_zip_file(const char *file_path, bool text_file);

bool
push_zip_file_with_ext(const char *file_ext, bool text_file);

void
get_file_buffer(char **file_buffer_ptr, int *file_size);

bool
push_buffer(const char *buffer_ptr, int buffer_size);

void
rewind_file(void);

void
pop_file(void);

void
pop_all_files(void);

int
read_file(byte *buffer_ptr, int bytes);

bool
copy_file(const char *file_path, bool text_file);

// Error checking and reporting functions.

void
bprintf(char *buffer, int size, const char *format, ...);

void
vbprintf(char *buffer, int size, const char *format, va_list arg_ptr);

void
write_error_log(const char *format, ...);

void 
diagnose(const char *format, ...);

void
log(const char *format, ...);

void
warning(const char *format, ...);

void
memory_warning(const char *object);

void
error(const char *format, ...);

void
memory_error(const char *object);

bool
check_int_range(int value, int min, int max);

bool
check_float_range(float value, float min, float max);

// Name parsing function.

bool
parse_name(const char *old_name, string *new_name, bool list);

// Attribute value parsing functions.

void
start_parsing_value(int tag_token, int attr_token, char *attr_value,
					bool attr_required);

bool
parse_integer_in_value(int *int_ptr);

bool
parse_integer_range(intrange *intrange_ptr);

bool
parse_float_in_value(float *float_ptr);

bool
parse_playback_mode(char *attr_value, int *playback_mode_ptr);

bool
token_in_value_is(const char *token_string, bool generate_error);

bool
stop_parsing_value(bool generate_error);

// Document parsing functions.

void
parse_start_of_document(int start_tag_token, attr_def *attr_def_list,
						int attributes);

void
parse_rest_of_document(bool strict_XML_compliance);

void
save_document(const char *file_name);

void
start_parsing_nested_tags(void);

bool
parse_next_nested_tag(int start_tag_token, tag_def *tag_def_list, 
					  bool allow_text, int *tag_token_ptr);

string
text_to_string(void);

string
nested_tags_to_string(void);

string
nested_text_to_string(int start_tag_token);

void
stop_parsing_nested_tags(void);

// Attribute value conversion function.

string
attribute_value_to_string(int value_type, int value);

