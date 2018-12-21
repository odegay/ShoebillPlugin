#pragma once
#include <jni.h>
#include <iconv.h>


/**
 * Copyright (C) 2011 MK124
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

int mbs2wcs(unsigned int codepage, const char *src, int srclen, unsigned short *dst, int dstlen);

jstring mbs2wcs(JNIEnv *env, unsigned int codepage, const char *src, const int len);

int wcs2mbs(unsigned int codepage, const unsigned short *src, int srclen, char *dst, int dstlen);

char *wcs2mbs(JNIEnv *env, unsigned int codepage, const jstring src, const int destLen);