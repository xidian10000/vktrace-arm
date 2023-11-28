/*
 * Copyright (C) 2020-2023 ARM Limited
 * ALL RIGHTS RESERVED
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
 *
 */

#include "snappy.h"

#include "snpcompressor.h"

snpcompressor::~snpcompressor() {

}

// snappy compressor doesn't need outputLength parameter
int snpcompressor::compress(const char* input, size_t inputLength, char* output, size_t outputLength) {
    size_t compressLength;
    snappy::RawCompress(input, inputLength, output, &compressLength);
    return compressLength;
}

int snpcompressor::getMaxCompressedLength(size_t size)
{
    return snappy::MaxCompressedLength(size);
}
