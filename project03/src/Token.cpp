#include "Token.h"

Token::Token(): _token(""), _type(0) {}
Token::Token(std::string str, int type): _token(str), _type(type)  {}

std::string Token::type_string() const {
    switch (_type) {
        case 1:
            return "ALPHA";
        case 2:
            return "SPACE";
        default:
            return "UNKNOWN";
    }
}
std::ostream& operator<<(std::ostream& outs, const Token& t) {
    return outs << std::setw(10) << std::left << '|' + t.token_str() + '|' << " "
                << t.type_string();
}