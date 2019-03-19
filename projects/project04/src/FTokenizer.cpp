#include "FTokenizer.h"

FTokenizer::FTokenizer() : _done(true) {}
FTokenizer::FTokenizer(std::string filename) {
    file_stream.open(filename);
    get_new_block();
}

bool FTokenizer::get_new_block() {
    file_stream.read(buffer, MAX_BUFFER - 1);
    buffer[file_stream.gcount()] = '\0';
    position += file_stream.gcount();
    block_position = 0;
    tokenizer.set_string(buffer);
    _done = file_stream.gcount() == 0;
    return _done;
}

Token FTokenizer::next_token() {
    Token t;
    if (tokenizer.done())
        get_new_block();

    // looks really dumb at first, but this checks if the tokenizer is still
    // empty after attempting to reload it
    if (!tokenizer.done()) {
        tokenizer >> t;
        block_position += t.token_str().length();
    }
    return t;
}

FTokenizer& operator>>(FTokenizer& f, Token& t) {
    t = f.next_token();
    return f;
}