/* Copyright (c) 2019 Griefer@Work                                            *
 *                                                                            *
 * This software is provided 'as-is', without any express or implied          *
 * warranty. In no event will the authors be held liable for any damages      *
 * arising from the use of this software.                                     *
 *                                                                            *
 * Permission is granted to anyone to use this software for any purpose,      *
 * including commercial applications, and to alter it and redistribute it     *
 * freely, subject to the following restrictions:                             *
 *                                                                            *
 * 1. The origin of this software must not be misrepresented; you must not    *
 *    claim that you wrote the original software. If you use this software    *
 *    in a product, an acknowledgement in the product documentation would be  *
 *    appreciated but is not required.                                        *
 * 2. Altered source versions must be plainly marked as such, and must not be *
 *    misrepresented as being the original software.                          *
 * 3. This notice may not be removed or altered from any source distribution. *
 */
#ifndef _LIBJSON_PARSER_H
#define _LIBJSON_PARSER_H 1

#include <__stdinc.h>

#include <bits/format-printer.h>
#include <bits/types.h>

#include "api.h"

/* Json parser example usage:
 * >> struct json_parser parser;
 * >> char const *input = "{\"bar\":\"baz\",\"foo\":[10,20,30]}";
 * >> json_parser_init(&parser, input, strend(input));
 * >> json_parser_enter(&parser);
 * >> json_parser_findkey(&parser, "foo");
 * >> json_parser_enter(&parser);
 * >> json_parser_findindex(&parser, 1);
 * >> intptr_t value;
 * >> json_parser_getnumber(&parser, &value);
 * >> printf("value = %Id\n", value); // `value = 20'
 */

__DECL_BEGIN


/* Json parser error codes. */
#define JSON_ERROR_OK       0  /* Success */
#define JSON_ERROR_SYNTAX (-1) /* Syntax error. */
#define JSON_ERROR_NOOBJ  (-2) /* Entity does not exist */
#define JSON_ERROR_SYSERR (-3) /* Other error (context-specific) */
#define JSON_ERROR_NOTEQ  JSON_ERROR_SYSERR /* Strings are not equal */
#define JSON_ERROR_EOF    JSON_ERROR_NOOBJ  /* End-of-file has been reachabed */

/* Json encoding values. */
#define JSON_ENCODING_UTF8    0x0000 /* utf-8 */
#define JSON_ENCODING_UTF16LE 0x0001 /* utf-16 (Little endian) */
#define JSON_ENCODING_UTF32LE 0x0002 /* utf-32 (Little endian) */
#define JSON_ENCODING_UTF16BE 0x0003 /* utf-16 (Big endian) */
#define JSON_ENCODING_UTF32BE 0x0004 /* utf-32 (Big endian) */

/* Json parser tokens. */
#define JSON_PARSER_EOF       0    /* End-of-file */
#define JSON_PARSER_ENDOBJECT ']'  /* } */
#define JSON_PARSER_ENDARRAY  '}'  /* ] */
#define JSON_PARSER_STRING    '\"' /* "foo" */
#define JSON_PARSER_NUMBER    '0'  /* 1234 */
#define JSON_PARSER_ARRAY     '['  /* [ */
#define JSON_PARSER_OBJECT    '{'  /* { */
#define JSON_PARSER_NULL      'n'  /* null */
#define JSON_PARSER_TRUE      't'  /* true */
#define JSON_PARSER_FALSE     'f'  /* false */


#ifdef __CC__
struct json_parser {
	char const  *jp_start;    /* Input data start */
	char const  *jp_end;      /* Input data end */
	char const  *jp_pos;      /* Current position within input data */
	unsigned int jp_encoding; /* [valid_if(jp_pos > jp_start)] Input encoding (One of `JSON_ENCODING_*')
	                           * The used encoding is automatically determined when parsing starts. */
	/* NOTE: You may have noticed that this parser is stateless, that is: it doesn't keep
	 *       track of a stack of object vs. array scopes, meaning that when any kind of
	 *       scope is exited, the token used for this (whether it be `]' or `}') isn't
	 *       actually taken into consideration, leading to the consequence that this parser
	 *       may accept json that would normally be considered to be malformed:
	 * >> {
	 * >>      "name": "demo",
	 * >>      "ids": [10, 20, 30},
	 * >>      "meta": {
	 * >>          "type": "demo_type"
	 * >>      ]
	 * >> ]
	 * As such, this is a known bug that can be considered as wont-fix, as doing so
	 * would involve having to introduce a heap-based approach to keeping track of
	 * active Json scopes, when the dependency on a heap wouldn't (and isn't) actually
	 * a requirement for proper execution. (Not depending on a heap allows this library
	 * to function entirely portable, as well as be entirely freestanding with absolutely
	 * 0 hard ABI/library dependencies)
	 */
};

/* Initialize a json parser with the given piece of in-memory json.
 * NOTE: This function automatically detects the encoding (one of `JSON_ENCODING_*')
 *       of the given input, as specified by the Json specs, meaning you don't have
 *       to concern yourself with the details on how to supply input to this function. */
typedef void (LIBJSON_CC *PJSON_PARSER_INIT)(struct json_parser *__restrict self,
                                             void const *start, void const *end);
#ifdef LIBJSON_WANT_PROTOTYPES
LIBJSON_DECL void LIBJSON_CC
json_parser_init(struct json_parser *__restrict self,
                 void const *start, void const *end);
#endif /* LIBJSON_WANT_PROTOTYPES */

/* Yield to the current token and advance to the next one
 * @return: JSON_PARSER_*:     The previously selected token (the parser now points at its end)
 * @return: JSON_ERROR_EOF:    The end of the input file has been reached.
 * @return: JSON_ERROR_SYNTAX: Syntax error. */
typedef int (LIBJSON_CC *PJSON_PARSER_YIELD)(struct json_parser *__restrict self);
#ifdef LIBJSON_WANT_PROTOTYPES
LIBJSON_DECL int LIBJSON_CC json_parser_yield(struct json_parser *__restrict self);
#endif /* LIBJSON_WANT_PROTOTYPES */

/* Yield to the previous token and return it
 * @return: JSON_PARSER_*:     The now selected token (The parser is now located at the previous token)
 * @return: JSON_ERROR_EOF:    The start of the input file had already been reached.
 * @return: JSON_ERROR_SYNTAX: Syntax error. */
typedef int (LIBJSON_CC *PJSON_PARSER_UNYIELD)(struct json_parser *__restrict self);
#ifdef LIBJSON_WANT_PROTOTYPES
LIBJSON_DECL int LIBJSON_CC json_parser_unyield(struct json_parser *__restrict self);
#endif /* LIBJSON_WANT_PROTOTYPES */

/* Rewind to the start of the current object/array
 * @return: JSON_PARSER_ARRAY:  The parser now points at the first token following the initial `['.
 * @return: JSON_PARSER_OBJECT: The parser now points at the first token following the initial `{'.
 * @return: JSON_ERROR_SYNTAX:  Syntax error. */
typedef int (LIBJSON_CC *PJSON_PARSER_REWIND)(struct json_parser *__restrict self);
#ifdef LIBJSON_WANT_PROTOTYPES
LIBJSON_DECL int LIBJSON_CC json_parser_rewind(struct json_parser *__restrict self);
#endif /* LIBJSON_WANT_PROTOTYPES */

/* Advance the parser to the next object member or array index
 * @return: JSON_ERROR_OK:    The parser now points at the first token after the `,'
 *                            following previous object memory/array index.
 *                            Should that token be a `}' or `]', `JSON_ERROR_NOOBJ'
 *                            will be returned instead.
 * @return: JSON_ERROR_NOOBJ: The end of the current object/array was reached.
 *                            The parser now points at the `}' or `]' following the object/array
 * @return: JSON_ERROR_SYNTAX: Syntax error. */
typedef int (LIBJSON_CC *PJSON_PARSER_NEXT)(struct json_parser *__restrict self);
#ifdef LIBJSON_WANT_PROTOTYPES
LIBJSON_DECL int LIBJSON_CC json_parser_next(struct json_parser *__restrict self);
#endif /* LIBJSON_WANT_PROTOTYPES */

/* Rewind the parser to the previous object member or array index
 * @return: JSON_ERROR_OK:    The parser now points at the start of the previous object member/array index.
 * @return: JSON_ERROR_NOOBJ: The start of the current object/array was reached.
 *                            In this case, the position of the parser depends on `leave_object':
 *                            leave_object == true: The parser now points at either:
 *                               - The `{' or `[' token if the inner object/array was an array index
 *                               - The start of the member name `"foo":{...}' if the inner
 *                                 object/array was an object member
 *                            leave_object == false: The parser still points at the start of
 *                                                   the first member of the inner object/array.
 * @return: JSON_ERROR_SYNTAX: Syntax error. */
typedef int (LIBJSON_CC *PJSON_PARSER_PREV)(struct json_parser *__restrict self,
                                            __BOOL leave_object);
#ifdef LIBJSON_WANT_PROTOTYPES
LIBJSON_DECL int LIBJSON_CC json_parser_prev(struct json_parser *__restrict self,
                                             __BOOL leave_object);
#endif /* LIBJSON_WANT_PROTOTYPES */

/* Advance the parser to the first member/index of an object/array
 * @return: JSON_ERROR_OK:    The parser now points at first member/index of the inner object/array.
 * @return: JSON_ERROR_NOOBJ: The parser didn't point at `{' or `[' (its position remains unchanged).
 * @return: JSON_ERROR_SYNTAX: Syntax error. */
typedef int (LIBJSON_CC *PJSON_PARSER_ENTER)(struct json_parser *__restrict self);
typedef int (LIBJSON_CC *PJSON_PARSER_ENTEROBJECT)(struct json_parser *__restrict self);
typedef int (LIBJSON_CC *PJSON_PARSER_ENTERARRAY)(struct json_parser *__restrict self);
#ifdef LIBJSON_WANT_PROTOTYPES
LIBJSON_DECL int LIBJSON_CC json_parser_enter(struct json_parser *__restrict self);
LIBJSON_DECL int LIBJSON_CC json_parser_enterobject(struct json_parser *__restrict self);
LIBJSON_DECL int LIBJSON_CC json_parser_enterarray(struct json_parser *__restrict self);
#endif /* LIBJSON_WANT_PROTOTYPES */

/* Skip the remainder of the current object/array and parse until after the following `,'
 * If that token doesn't exist, or is followed by another closing token, stop parsing there.
 * @return: JSON_ERROR_OK:  The parser now points at the first token after the `,'
 *                          following the previous object. - If that `,' does not exist,
 *                          the parser exists at the `}' or `]' that is taking its place.
 * @return: JSON_ERROR_EOF: The end of the input file has been reached.
 * @return: JSON_ERROR_SYNTAX: Syntax error. */
typedef int (LIBJSON_CC *PJSON_PARSER_LEAVE)(struct json_parser *__restrict self);
typedef int (LIBJSON_CC *PJSON_PARSER_LEAVEOBJECT)(struct json_parser *__restrict self);
typedef int (LIBJSON_CC *PJSON_PARSER_LEAVEARRAY)(struct json_parser *__restrict self);
#ifdef LIBJSON_WANT_PROTOTYPES
LIBJSON_DECL int LIBJSON_CC json_parser_leave(struct json_parser *__restrict self);
LIBJSON_DECL int LIBJSON_CC json_parser_leaveobject(struct json_parser *__restrict self);
LIBJSON_DECL int LIBJSON_CC json_parser_leavearray(struct json_parser *__restrict self);
#endif /* LIBJSON_WANT_PROTOTYPES */


/* Returns the current parser state / token type.
 * @return: JSON_PARSER_*: The current parser state.
 * @return: JSON_ERROR_SYNTAX: Syntax error. */
typedef int (LIBJSON_CC *PJSON_PARSER_STATE)(struct json_parser *__restrict self);
#ifdef LIBJSON_WANT_PROTOTYPES
LIBJSON_DECL int LIBJSON_CC json_parser_state(struct json_parser *__restrict self);
#endif /* LIBJSON_WANT_PROTOTYPES */


/* Search for the given key within the current object.
 * The given key is searched in both forward, and backward direction, starting
 * at the current parser location. - If the key exists multiple times, it is
 * undefined which of these locations will be returned.
 * @return: JSON_ERROR_OK:    The parser now points after the `:' following the matching key's name.
 * @return: JSON_ERROR_NOOBJ: The given `key' wasn't found (The position of `self' remains unchanged)
 * @return: JSON_ERROR_SYNTAX: Syntax error. */
typedef int (LIBJSON_CC *PJSON_PARSER_FINDKEY)(struct json_parser *__restrict self,
                                               /*utf-8*/ char const *__restrict key,
                                               size_t keylen);
#ifdef LIBJSON_WANT_PROTOTYPES
LIBJSON_DECL int LIBJSON_CC
json_parser_findkey(struct json_parser *__restrict self,
                    /*utf-8*/char const *__restrict key,
                    size_t keylen);
#endif /* LIBJSON_WANT_PROTOTYPES */

/* Got the `index'th' array elements before returning `JSON_ERROR_OK'
 * the parser is rewound to the start of the current array before proceeding.
 * NOTE: If the intend is to enumerate array elements, it is more efficient
 *       to rewind to the start of the array with `json_parser_rewind()', then
 *       proceeding to use `json_parser_next()' to iterate elements.
 * @return: JSON_ERROR_OK:    The parser was now advanced to the `index'th array element.
 *                            In this case, the parser points at the start of that element.
 * @return: JSON_ERROR_NOOBJ: The end of the array has been reached before, or when `index'
 *                            elements had been skipped. (The position of `self' remains unchanged)
 * @return: JSON_ERROR_SYNTAX: Syntax error. */
typedef int (LIBJSON_CC *PJSON_PARSER_FINDINDEX)(struct json_parser *__restrict self,
                                                 __uintptr_t index);
#ifdef LIBJSON_WANT_PROTOTYPES
LIBJSON_DECL int LIBJSON_CC
json_parser_findindex(struct json_parser *__restrict self,
                      __uintptr_t index);
#endif /* LIBJSON_WANT_PROTOTYPES */

/* Check if the current parser token (which should be a string) is equal to `str'
 * @return: JSON_ERROR_OK:     The previous token is was a string that was equal to `str'
 *                             In this case the parser now points at the first token after the string.
 * @return: JSON_ERROR_NOTEQ:  The string isn't equal to `str'.
 *                             In this case the parser now points at the first token after the string.
 * @return: JSON_ERROR_NOOBJ:  The parser didn't point at a string. (The position of `self' remains unchanged)
 * @return: JSON_ERROR_SYNTAX: Syntax error. */
typedef int (LIBJSON_CC *PJSON_PARSER_EQSTRING)(struct json_parser *__restrict self,
                                                /*utf-8*/ char const *__restrict str,
                                                size_t len);
#ifdef LIBJSON_WANT_PROTOTYPES
LIBJSON_DECL int LIBJSON_CC
json_parser_eqstring(struct json_parser *__restrict self,
                     /*utf-8*/char const *__restrict str,
                     size_t len);
#endif /* LIBJSON_WANT_PROTOTYPES */

/* Parse a Json string and print its contents to `printer'
 * @return: JSON_ERROR_OK:     Success. - The sum of all calls to `*printer' is stored in `*pprinter_result'
 *                             In this case the parser points at the first token after an optional trailing `,'
 *                             NOTE: Should the token following the string be a `:', the parser will point at
 *                                   that location instead.
 * @return: JSON_ERROR_NOOBJ:  The parser didn't point at a string token.
 *                             In this case the parser didn't change position.
 * @return: JSON_ERROR_SYSERR: An invocation of `printer' returned a negative value (stored in `*pprinter_result').
 *                             In this case the position of the parser is revered to the start of the string.
 * @return: JSON_ERROR_SYNTAX: Syntax error. */
typedef int (LIBJSON_CC *PJSON_PARSER_PRINTSTRING)(struct json_parser *__restrict self,
                                                   __pformatprinter printer, void *arg,
                                                   __ssize_t *__restrict pprinter_result);
#ifdef LIBJSON_WANT_PROTOTYPES
LIBJSON_DECL int LIBJSON_CC
json_parser_printstring(struct json_parser *__restrict self,
                        __pformatprinter printer, void *arg,
                        __ssize_t *__restrict pprinter_result);
#endif /* LIBJSON_WANT_PROTOTYPES */

/* A somewhat hacky variant of `libjson_parser_printstring()', which replaces the source
 * string in-line (thus modifying the source string) with its utf-8 encoded variant.
 * This is done by re-encoding the string using a special extension syntax token that is
 * specifically designed to be able to hold a NUL-terminated utf-8 string token:
 * BEFORE:  \"foo\\nbar\"
 * AFTER:   \0foo\nbar\0\0
 * NOTE: If the source input uses a multi-byte format, the width leading \0 matches
 *       that format's width, while the remainder of the string always follows UTF-8
 * NOTE: Another special encoding also exists for an empty string:
 * BEFORE:  \"\"
 * AFTER:   \1\1 -- Additional \1 character may follow
 * @param: plength: When non-NULL, write the length of the returned string here.
 * @return: * :     A pointer to the start of the inlined utf-8 string
 * @return: NULL:   An error occurred; when `perror` is non-NULL, that error is stored there:
 *                   - JSON_ERROR_NOOBJ:  Parser didn't point at a string object.
 *                   - JSON_ERROR_SYNTAX: Syntax error */
typedef /*utf-8*/char *(LIBJSON_CC *PJSON_PARSER_GETSTRING)(struct json_parser *__restrict self,
                                                            __size_t *plength, int *perror);
#ifdef LIBJSON_WANT_PROTOTYPES
LIBJSON_DECL /*utf-8*/char *LIBJSON_CC
json_parser_getstring(struct json_parser *__restrict self,
                      __size_t *plength, int *perror);
#endif /* LIBJSON_WANT_PROTOTYPES */


/* Decode a Json number and store its value in `*presult'
 * @return: JSON_ERROR_OK:     Success. - The number is stored in `*presult'
 *                             In this case the parser points at the first token after an optional trailing `,'
 * @return: JSON_ERROR_NOOBJ:  The parser didn't point at a number token.
 *                             In this case the parser didn't change position.
 * @return: JSON_ERROR_SYNTAX: Syntax error. */
typedef int (LIBJSON_CC *PJSON_PARSER_GETNUMBER)(struct json_parser *__restrict self,
                                                 __intptr_t *__restrict presult);
typedef int (LIBJSON_CC *PJSON_PARSER_GETINT64)(struct json_parser *__restrict self,
                                                __int64_t *__restrict presult);
typedef int (LIBJSON_CC *PJSON_PARSER_GETUINT64)(struct json_parser *__restrict self,
                                                 __uint64_t *__restrict presult);
typedef int (LIBJSON_CC *PJSON_PARSER_GETFLOAT)(struct json_parser *__restrict self,
                                                double *__restrict presult);
#ifdef LIBJSON_WANT_PROTOTYPES
LIBJSON_DECL int LIBJSON_CC
json_parser_getnumber(struct json_parser *__restrict self,
                      __intptr_t *__restrict presult);
LIBJSON_DECL int LIBJSON_CC
json_parser_getint64(struct json_parser *__restrict self,
                     __int64_t *__restrict presult);
LIBJSON_DECL int LIBJSON_CC
json_parser_getuint64(struct json_parser *__restrict self,
                      __uint64_t *__restrict presult);
LIBJSON_DECL int LIBJSON_CC
json_parser_getfloat(struct json_parser *__restrict self,
                     double *__restrict presult);
#endif /* LIBJSON_WANT_PROTOTYPES */

/* Decode a Json boolean and store its value in `*presult'
 * @return: JSON_ERROR_OK:     Success. - The value is stored in `*presult'
 *                             In this case the parser points at the first token after an optional trailing `,'
 * @return: JSON_ERROR_NOOBJ:  The parser didn't point at a true/false token.
 *                             In this case the parser didn't change position.
 * @return: JSON_ERROR_SYNTAX: Syntax error. */
typedef int (LIBJSON_CC *PJSON_PARSER_GETBOOL)(struct json_parser *__restrict self,
                                               __BOOL *__restrict presult);
#ifdef LIBJSON_WANT_PROTOTYPES
LIBJSON_DECL int LIBJSON_CC
json_parser_getbool(struct json_parser *__restrict self,
                    __BOOL *__restrict presult);
#endif /* LIBJSON_WANT_PROTOTYPES */

/* Decode a Json null-value
 * @return: JSON_ERROR_OK:     Success.
 *                             In this case the parser points at the first token after an optional trailing `,'
 * @return: JSON_ERROR_NOOBJ:  The parser didn't point at a `null' token.
 *                             In this case the parser didn't change position.
 * @return: JSON_ERROR_SYNTAX: Syntax error. */
typedef int (LIBJSON_CC *PJSON_PARSER_GETNULL)(struct json_parser *__restrict self);
#ifdef LIBJSON_WANT_PROTOTYPES
LIBJSON_DECL int LIBJSON_CC
json_parser_getnull(struct json_parser *__restrict self);
#endif /* LIBJSON_WANT_PROTOTYPES */

#endif /* __CC__ */



__DECL_END

#endif /* !_LIBJSON_PARSER_H */
