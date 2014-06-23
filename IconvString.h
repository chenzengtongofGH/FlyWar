#ifndef ICONV_STRING_H
#define ICONV_STRING_H

int convert(char *from_charset, char *to_charset, char *inbuf, size_t inlen, char *outbuf, size_t outlen);

int gbk2utf8(char *inbuf, size_t inlen, char *outbuf, size_t outlen);

#endif