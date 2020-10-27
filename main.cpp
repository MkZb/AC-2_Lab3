#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <iostream>

static int h_count = 0;
static int v_count = 0;
static int C_count = 0;
static bool empty_C = true;
static int L_count = 0;

static std::string constant_val;
static std::string list_val;

int main(int argc, char *argv[]) {

    const char *short_options = "hvC::L:";

    const struct option long_options[] = {
            {"help",     no_argument,       NULL, 'h'},
            {"version",  no_argument,       NULL, 'v'},
            {"constant", optional_argument, NULL, 'C'},
            {"list",     required_argument, NULL, 'L'},
            {NULL, 0,                       NULL, 0}
    };
    int opt;
    int opt_index = -1;

    while ((opt = getopt_long(argc, argv, short_options, long_options, &opt_index)) != -1) {
        switch (opt) {
            case 'h': {
                if (opt_index < 0)
                    puts("Short -h key found");
                else
                    puts("Long -h key found");
                h_count++;
                break;
            }
            case 'v': {
                if (opt_index < 0)
                    puts("Short -v key found");
                else
                    puts("Long -v key found");
                v_count++;
                break;
            }
            case 'C': {
                if (opt_index < 0)
                    puts("Short -C key found");
                else
                    puts("Long -C key found");
                C_count++;
                if (optarg) {
                    constant_val = optarg;
                    empty_C = false;
                }
                break;
            }
            case 'L': {
                if (opt_index < 0)
                    puts("Short -L key found");
                else
                    puts("Long -L key found");
                L_count++;
                list_val = optarg;
                break;
            }
            case '?':
                exit(1);
            default: {
                abort();
            }
        }
        opt_index = -1;
    }

    if (h_count) {
        if (h_count == 1) {
            puts("List of available keys:\n"
                 "-h --help Show this message\n"
                 "-v --version Display version\n"
                 "-C --constant Constant with optional value\n"
                 "-L --list List with required values, separated with \",\"");
        } else {
            puts("Found more than 1 -h key");
        }
    }

    if (v_count) {
        if (v_count == 1) {
            puts("Version: 1.0");
        } else {
            puts("Found more than 1 -v key");
        }
    }

    if (C_count) {
        if (C_count == 1) {
            if (!empty_C) {
                printf("Value given: ");
                std::cout << constant_val << "\n";
            } else {
                puts("No value given. Set to default.");
            }
        } else {
            puts("Found more than 1 -C key");
        }
    }

    if (L_count) {
        if (L_count == 1) {
            printf("List of values: [ ");
            int pos;
            while ((pos = list_val.find(',')) != std::string::npos) {
                printf("%i, ", (int) std::stod(list_val.substr(0, pos)));
                list_val.erase(0, pos + 1);
            }
            std::cout << list_val << " ]\n";
        } else {
            puts("Found more than 1 -L key");
        }
    }

    return 0;
};