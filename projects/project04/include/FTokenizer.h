#pragma once
#include "Stokenizer/STokenizer.h"
#include <fstream>
#include <string>

class FTokenizer {
private:
    static const int MAX_BUFFER = STokenizer::MAX_BUFFER;
    char buffer[MAX_BUFFER];

    int position = 0;
    int block_position = 0;
    bool _done = 0;

    STokenizer tokenizer;
    std::ifstream file_stream;

    bool get_new_block();

public:
    FTokenizer();
    FTokenizer(std::string filename);
    ~FTokenizer() { file_stream.close(); };
    Token next_token();
    bool done() { return _done; };
    // Current position in the file
    int pos();
    // Current position in the current block
    int block_pos();
    friend FTokenizer& operator>>(FTokenizer& f, Token& t);
};