#include "Token.h"

Token::Token(): _token(""), _type(0) {}
Token::Token(std::string str, int type): _token(str), _type(type)  {}

std::string Token::type_string() const {
    switch (_type) {
        case 1:
        case 7:
            return "ALPHA";
        case 2:
            return "SPACE";
        case 3:
            return "NUMBER";
        case 5:
            return "PUNCTUATION";
        case 9:
            return "ELLIPSIS";
        default:
            return "UNKNOWN";
    }
}
std::ostream& operator<<(std::ostream& outs, const Token& t) {
    return outs << std::setw(10) << std::left << '|' + t.token_str() + '|' << " "
                << t.type_string();
}