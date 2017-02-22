#include "type_tester.hpp"

void
TypeTester::run_type_tester() {
    times_up = false;
    
    get_params();
    get_words();

    gen_passage();

    while (!times_up || !force_quit) {
        get_input();i
    }

    add_log();
}
