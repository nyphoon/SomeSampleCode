// This sample code can help us to verify our regular expression.
// modified from http://en.cppreference.com/w/cpp/regex
// ECMAScript syntax: http://www.cplusplus.com/reference/regex/ECMAScript/
// Note: regex is available after gcc 4.9
#include <iostream>
#include <iterator>
#include <string>
#include <regex>
#include <limits>

int main()
{
    std::string dft_s = "Some people, when confronted with a problem, think "
        "\"I know, I'll use regular expressions.\" "
        "Now they have two problems.";
    std::string s;

    std::cout<< "input target string({Press Enter to use default):\n";
    std::getline(std::cin, s);
    if( s=="" ) {
        s = dft_s;
        std::cout<<"no target input. use default target string:\n" << s << "\n\n";
    }

    // regex_search
    std::string phrase = "REGULAR EXPRESSIONS";
    std::regex self_regex(phrase,
            std::regex_constants::ECMAScript | std::regex_constants::icase);
    if (std::regex_search(s, self_regex)) {
        std::cout << "Text contains the phrase '"<<phrase<<"'\n";
    }

    // regex_match
    phrase = "So.*haha."; // this should not match
    self_regex = std::regex(phrase,
            std::regex_constants::ECMAScript | std::regex_constants::icase);
    if (std::regex_match(s, self_regex)) {
        std::cout << "Text matchs the phrase '"<<phrase<<"'\n";
    } else {
        std::cout << "Text doesn't match the phrase '"<<phrase<<"'\n";
    }

    // regex_search's match result
    std::smatch m;
    phrase = "p\\S*e";
    self_regex = std::regex(phrase,
            std::regex_constants::ECMAScript | std::regex_constants::icase);
    if (std::regex_search(s, m, self_regex)) {
        std::cout << "With regex=\""<<phrase<<"\" \""<<m[0]<<"\" is found\n\n";
    }

    // sregex_iterator
    std::string re;
    // re = "(\\S+)";
    std::cout<<"input RE to search: ";
    while( !std::getline(std::cin, re).eof() ) {
        try {
            std::regex word_regex(re);
            auto words_begin =
                std::sregex_iterator(s.begin(), s.end(), word_regex);
            auto words_end = std::sregex_iterator();

            std::cout << "Found "
                      << std::distance(words_begin, words_end)
                      << " words\n";

            for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
                std::cout << "  " << i->str() << '\n';
            }
        }catch( const std::regex_error& e ){
            std::cout<<"RE search error"<<std::endl;
        };
        std::cout<<"input RE: ";
    }

    // regex_replace
    std::regex long_word_regex("(\\w{6,})");
    std::string new_s = std::regex_replace(s, long_word_regex, "[$&]");
    std::cout << "\nmark word length longer than 6\n";
    std::cout << new_s << '\n';
}
